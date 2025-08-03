
#ifndef dev_spi_H
#define dev_spi_H

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"
#include "hardware/dma.h"
#include "hardware/pwm.h"

/**
 * @addtogroup SPI_CONFIG
 *
 * @{
 *
 * Configuración del driver SPI.
 *
 */
/*! @brief Puerto spi para LCD*/
#define SPI_PORT spi1

/*! @brief Puerto spi para RTC*/
#define SPI_PORT0 spi0

/*! @brief Frecuencia de la comunicacion spi con el LCD*/
#define SPI_FREQ (270000 * 1000)

/*! @brief Frecuencia de la comunicacion spi con el RTC*/
#define SPI0_FREQ (1000 * 1000)


/*! @brief LCD command/data selection pin*/
#define LCD_DC_PIN 8
/*! @brief LCD chip selection*/
#define LCD_CS_PIN 9
/*! @brief LCD SCK pin*/
#define LCD_SCK_PIN 10
/*! @brief LCD MOSI pin*/
#define LCD_MOSI_PIN 11
/*! @brief LCD RESET PIN*/
#define LCD_RESET_PIN 12
/*! @brief LCD BLACKLIGHT CONTROL pin*/
#define LCD_BL_PIN 25
/*! @brief Marcara de los pines de control del display*/
#define LCD_PIN_MASKS ((1U << LCD_DC_PIN) | (1U << LCD_CS_PIN) | (1U << LCD_RESET_PIN) | (1U << LCD_BL_PIN))

/*! @brief RTC chip selection*/
#define RTC_CS_PIN 17
/*! @brief RTC SCK pin*/
#define RTC_SCK_PIN 18
/*! @brief RTC MOSI pin*/
#define RTC_MOSI_PIN 19
/*! @brief RTC MISO PIN*/
#define RTC_MISO_PIN 16

/*! @brief Define if the spi0 port is LSB first*/
#define SPI0_LSB_FIRST 1




/**
 * @}
 */


extern uint dma_tx;
extern dma_channel_config c;
/**
 * @addtogroup SPI_FUNCTIONS
 *
 * @{
 *
 * Funciones del driver SPI.
 */

/**
 * @brief Función que inicializa el driver SPI.
 *
 * Esta función inicializa el driver SPI, configurando los registros necesarios para su correcto funcionamiento.
 */
void SPI_init(void);

/**
 * @brief Función que escribe un byte en el puerto SPI.
 *
 * Esta función escribe un byte en el puerto SPI.
 *
 * @param Value Byte a escribir.
 *
 * @return void
 */
void SPI_WriteByte(uint8_t Value);

/**
 * @brief Función que escribe una cadena de bytes en el puerto SPI.
 *
 * Esta función escribe una cadena de bytes en el puerto SPI.
 *
 * @param pData Cadena de bytes a escribir.
 * @param Len Longitud de la cadena de bytes.
 *
 * @return void
 */
void SPI_Write_nByte(uint8_t pData[], uint32_t Len);

/**
 * @}
 */


/**
 * @brief Función que configura el DMA para el driver SPI.
 * 
 * Esta función configura el DMA para el driver SPI.
 * 
 * @return void
 */
void config_dma(void);

/**
 * @brief Función que configura el PWM para el driver SPI.
 * 
 * Esta función configura el PWM para el driver SPI, esta configuracion 
 * se utiliza para controlar el brillo de la pantalla.
 */
void config_pwm(void);

/**
 * @brief Función que configura los pines GPIO para el driver SPI.
 * 
 * Esta función configura los pines GPIO para el driver SPI.
 */
void config_gpio(void);

void set_pwm(uint8_t level);

#endif // dev_spi_H
