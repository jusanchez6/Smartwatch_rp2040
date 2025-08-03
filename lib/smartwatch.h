#ifndef SMARTWATCH_H
#define SMARTWATCH_H

#include <stdio.h>

// Librerias del SDK
#include "hardware/gpio.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/sync.h"


// Librerias de la pico
#include "pico/stdlib.h"
#include "pico/platform.h"

// Librerias de la aplicacion
#include "imu.h"
#include "LCD.h"
#include "rtc.h"


//Libreria LGVL para el manejo de la interfaz grafica
#include "../lv_conf.h"
#include "../lvgl/lvgl.h"


/*! @brief Frecuencia del PLL del sistema */
#define PLL_SYS_KHZ (270 * 1000)
/*! @brief Pin de interrupción 1 */
#define INT1_PIN 23
/*! @brief Mascara para la interupcion por WoM*/
#define WOM_INT 0x04
/*! @brief Mascara para la interrupcion por paso */
#define STEP_INT 0x10
/*! @brief Resolución horizontal del display */
#define DISP_HOR_RES 240 
/*! @brief Resolución vertical del display */
#define DISP_VER_RES 240 




/**
 * @brief Función que actualiza la pantalla principal
 * 
 * En esta funcion se realiza el chequeo de las variables y banderas de software para actualizar la pantalla principal
 * 
 * @return none
 * 
 */
void update_main_screen(void);


/**
 * @brief Configura todo el sistema
 * 
 * Función que configura los clocks del sistema, los pines de interrupción e inicializa las librerias de hardware.
 * 
 * @return none
 * 
*/
int smartwatch_init(void);









#endif // SMARTWATCH_H