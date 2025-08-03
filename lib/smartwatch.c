#include "smartwatch.h"

#define DISP_HOR_RES 240 // Resolución horizontal del display
#define DISP_VER_RES 240 // Resolución vertical del display

static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf0[DISP_HOR_RES * DISP_VER_RES/2];
static lv_color_t buf1[DISP_HOR_RES * DISP_VER_RES/2];
static lv_disp_drv_t disp_drv;

static lv_indev_drv_t indev_en;
static lv_group_t *group;
static lv_obj_t *screen1;
static lv_obj_t *label_steps;
static lv_obj_t *label_time;
static lv_obj_t *label_date;
static lv_obj_t *label_battery;
static lv_obj_t *label_calories;
static lv_obj_t *label_distance;
static lv_obj_t *label_heart;

static lv_obj_t *bar_steps;
static lv_obj_t *arc_calories, *arc_distance;

static struct repeating_timer lvgl_timer;
static struct repeating_timer ms_timer;

static void disp_flush_cb(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);

static void dma_handler(void);
static void timer_callback(lv_timer_t * timer);
static void create_screen1 (void);



datetime_t current_time = {
    .year = 2025,
    .month = 8,
    .day = 2,
    .dotw = 6, // Saturday
    .hour = 1,
    .min = 15,
    .sec = 0
};

/**
 * @brief Función para configurar los clocks del sistema.
 * 
 * Esta función configura los clocks del sistema, estableciendo la frecuencia del PLL del sistema y configurando los clocks de los periféricos.
 * 
 */
static void config_clocks (void) {
    set_sys_clock_khz(PLL_SYS_KHZ, true);
    clock_configure(
        clk_peri,
        0,
        CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS,
        PLL_SYS_KHZ * 1000,
        PLL_SYS_KHZ * 1000);
        
}

void disp_flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    // Configurar la ventana de dibujo en la pantalla
    LCD_1IN28_SetWindows(area->x1, area->y1, area->x2, area->y2);
    
    // Enviar datos utilizando DMA
    dma_channel_configure(
        dma_tx,
        &c,
        (volatile void *)&spi_get_hw(SPI_PORT)->dr, // Dirección destino: Registro SPI
        color_p,                                    // Dirección fuente: Buffer de color
        ((area->x2 + 1 - area-> x1)*(area->y2 + 1 - area -> y1))*2, // Cantidad de datos
        true); // Iniciar transferencia automáticamente
}

static void dma_handler(void)
{
    uint32_t status = dma_channel_get_irq0_status(dma_tx);
    //printf("status: %08x\n", status);
    if (status) {
        dma_channel_acknowledge_irq0(dma_tx);
        lv_disp_flush_ready(&disp_drv);         /* Indicate you are ready with the flushing*/
    } else {
        printf("DMA IRQ but no status set\n");
    }
}

static void create_screen1 (void) {
    
    screen1 = lv_obj_create(NULL);

    // WIDGET DE LA HORA
    label_time = lv_label_create(screen1);
    lv_label_set_text(label_time, "15:45");
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_48, 0);
    lv_obj_align(label_time, LV_ALIGN_CENTER, 0, -70);

    // WIDGET DE LA FECHA (DEBAJO DE LA HORA)
    label_date = lv_label_create(screen1);
    lv_label_set_text(label_date, "10/12/2024 WED");
    lv_obj_set_style_text_font(label_date, &lv_font_montserrat_18, 0);
    lv_obj_align(label_date, LV_ALIGN_CENTER, 0, -40);


    // WIDGET DE LA BATERIA
    label_battery = lv_label_create(screen1);
    lv_label_set_text(label_battery, LV_SYMBOL_BATTERY_FULL "100%");
    lv_obj_align(label_battery, LV_ALIGN_TOP_RIGHT, -90, 7);

    // BARRA DE PROGRESO DE LOS PASOS
    bar_steps = lv_bar_create(screen1);
    lv_obj_set_size(bar_steps, 100, 20);
    lv_bar_set_range(bar_steps, 0, 1000);
    lv_bar_set_value(bar_steps, 0, LV_ANIM_OFF);
    lv_obj_align(bar_steps, LV_ALIGN_CENTER, -50, -10);

    label_steps = lv_label_create(screen1);
    lv_label_set_text(label_steps, "Steps: 0");
    lv_obj_set_style_text_font(label_steps, &lv_font_montserrat_10, 0);
    lv_obj_align_to(label_steps, bar_steps, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);


    // WIDGET DE LAS CALORIAS
    arc_calories = lv_arc_create(screen1);
    lv_obj_set_size(arc_calories, 45, 45);
    lv_arc_set_rotation(arc_calories, 270);
    lv_arc_set_bg_angles(arc_calories, 0, 360);
    lv_obj_remove_style(arc_calories, NULL, LV_PART_KNOB);
    lv_arc_set_value(arc_calories, 0);
    lv_obj_align(arc_calories, LV_ALIGN_CENTER, -40, 45);

    label_calories = lv_label_create(screen1);
    lv_label_set_text(label_calories, "0");
    lv_obj_set_style_text_font(label_calories, &lv_font_montserrat_10, 0);
    lv_obj_align_to(label_calories, arc_calories, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);


    // WIDGET DE LA DISTANCIA
    arc_distance = lv_arc_create(screen1);
    lv_obj_set_size(arc_distance, 45, 45);
    lv_arc_set_rotation(arc_distance, 270);
    lv_arc_set_bg_angles(arc_distance, 0, 360);
    lv_obj_remove_style(arc_distance, NULL, LV_PART_KNOB);
    lv_arc_set_value(arc_distance, 0);
    lv_obj_align(arc_distance, LV_ALIGN_CENTER, 40, 45);

    label_distance = lv_label_create(screen1);
    lv_label_set_text(label_distance, "0m");
    lv_obj_set_style_text_font(label_distance, &lv_font_montserrat_10, 0);
    lv_obj_align_to(label_distance, arc_distance, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);

}

static bool repeating_lvgl_timer_callback (struct repeating_timer *t) {
    lv_tick_inc(5);
    return true;
}

int64_t update_rtc(alarm_id_t id, void *user_data)
{
    if (!rtc_get_datetime(&current_time)) {
        return 60 * 1000 * 1000; // sigue intentando aunque falle
    }

    // Formatear la hora (HH:MM)
    char time_buf[16];
    snprintf(time_buf, sizeof(time_buf), "%02d:%02d", current_time.hour, current_time.min);
    lv_label_set_text(label_time, time_buf);

    // Días de la semana (opcional)
    static const char* const weekday_str[] = {
        "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
    };
    const char* day_str = weekday_str[current_time.dotw % 7];

    // Formatear la fecha (DD/MM/YYYY DOW)
    char date_buf[32];
    snprintf(date_buf, sizeof(date_buf), "%02d/%02d/%04d %s",
             current_time.day, current_time.month, current_time.year, day_str);
    lv_label_set_text(label_date, date_buf);

    return 60 * 1000 * 1000; 
}


int smartwatch_init(){
    // Configuración de PLL y clocks
    config_clocks();

    // Inicialización USB para debug
    stdio_init_all();
    sleep_ms(3000);

    // Inicialización del hardware
    LCD_init(HORIZONTAL);
    set_pwm(100);
    QMI8658_init();

    rtc_init();
    rtc_set_datetime(&current_time);



    add_repeating_timer_ms(5, repeating_lvgl_timer_callback, NULL, &lvgl_timer);
    add_alarm_in_ms(60000, update_rtc, NULL, true);

    // Inicialización de LVGL
    lv_init();


    lv_disp_draw_buf_init(&disp_buf, buf0, buf1, DISP_HOR_RES * DISP_VER_RES / 2); 
    lv_disp_drv_init(&disp_drv);    
    disp_drv.flush_cb = disp_flush_cb;
    disp_drv.draw_buf = &disp_buf;        
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    dma_channel_set_irq0_enabled(dma_tx, true);
    irq_set_exclusive_handler(DMA_IRQ_0, dma_handler);
    irq_set_enabled(DMA_IRQ_0, true);

    create_screen1();

    // Inicializar la primera pantalla
    lv_scr_load(screen1);

    uint32_t steps = 0;

    printf("DMA status: %08x\n", dma_channel_get_irq0_status(dma_tx));  
    // Bucle principal para LVGL
    while (true)
    {
        steps = read_imu_step_count();
        char steps_str[32];
        snprintf(steps_str, 64, "Steps: %d", steps);
        printf("udapted text: %s\n", steps_str);

        lv_bar_set_value(bar_steps, steps, LV_ANIM_OFF);

        lv_label_set_text(label_steps, steps_str);
        lv_obj_align_to(label_steps, bar_steps, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
        lv_obj_invalidate(screen1);

        lv_task_handler(); 
        sleep_ms(5); // Ajustar al ciclo de tiempo necesario
    }

    return 0;

}


