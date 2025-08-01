#ifndef lcd_h
#define lcd_h

#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"

extern "C" {
#include "spi_lcd.h"

}

#define LCD_WIDTH 240
#define LCD_HEIGHT 320

#define LCD_HORIZONTAL 0
#define LCD_VERTICAL 1


class lcd {
public:
    lcd();

    void init(uint8_t scan_dir);
    void clear(uint16_t color);
    void display(uint16_t* image);
    void displayWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t* image);
    void setWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend);

private:

    /**
     * @brief Sends a command to the LCD.
     */
    void sendCommand(uint8_t reg);

    /**
     * @brief Sends an 8-bit data to the LCD.
     */
    void sendData8(uint8_t data);

    /**
     * @brief Sends a 16-bit data to the LCD.
     */
    void sendData16(uint16_t data);

    /**
     * @brief Resets the LCD.
     */
    void reset();

    /**
     * @brief Initializes the LCD registers.
     */
    void initRegisters();

    /**
     * @brief Sets the LCD attributes.
     */
    void setAttributes(uint8_t scan_dir);

    /**
     * @brief Initializes the LCD with the specified scan direction.
     */
    uint8_t SCAN_DIR;
    
    /**
     * @brief Width and height of the LCD display.
     */
    uint16_t WIDTH;

    /**
     * @brief Height of the LCD display.
     */
    uint16_t HEIGHT;

};










#endif // lcd_h