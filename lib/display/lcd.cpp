#include "lcd.h"

lcd::lcd() {
}

void lcd::sendCommand(uint8_t reg) {
    gpio_put(LCD_DC_PIN, 0);
    SPI_WriteByte(reg);
}

void lcd::sendData8(uint8_t data) {
    gpio_put(LCD_DC_PIN, 1);
    SPI_WriteByte(data);
}

void lcd::sendData16(uint16_t data) {
    gpio_put(LCD_DC_PIN, 1);
    SPI_WriteByte(data >> 8); // Send high byte
    SPI_WriteByte(data); // Send low byte
}


void lcd::reset() {
    gpio_put(LCD_RESET_PIN, 1);
    sleep_ms(100); // Reset pulse width
    gpio_put(LCD_RESET_PIN, 0);
    sleep_ms(100); // Wait for the display to reset
    gpio_put(LCD_RESET_PIN, 1);
    gpio_put(LCD_DC_PIN, 0); // Set DC low for command mode
    sleep_ms(100);

    printf("LCD reset complete.\n");
}

void lcd::initRegisters() {
    sendCommand(0xEF);
	sendCommand(0xEB);
	sendData8(0x14); 
	
    sendCommand(0xFE);			 
	sendCommand(0xEF); 

	sendCommand(0xEB);	
	sendData8(0x14); 

	sendCommand(0x84);			
	sendData8(0x40); 

	sendCommand(0x85);			
	sendData8(0xFF); 

	sendCommand(0x86);			
	sendData8(0xFF); 

	sendCommand(0x87);			
	sendData8(0xFF);

	sendCommand(0x88);			
	sendData8(0x0A);

	sendCommand(0x89);			
	sendData8(0x21); 

	sendCommand(0x8A);			
	sendData8(0x00); 

	sendCommand(0x8B);			
	sendData8(0x80); 

	sendCommand(0x8C);			
	sendData8(0x01); 

	sendCommand(0x8D);			
	sendData8(0x01); 

	sendCommand(0x8E);			
	sendData8(0xFF); 

	sendCommand(0x8F);			
	sendData8(0xFF); 


	sendCommand(0xB6);
	sendData8(0x00);
	sendData8(0x20);

	sendCommand(0x36);
	sendData8(0x08);//Set as vertical screen

	sendCommand(0x3A);			
	sendData8(0x05); 


	sendCommand(0x90);			
	sendData8(0x08);
	sendData8(0x08);
	sendData8(0x08);
	sendData8(0x08); 

	sendCommand(0xBD);			
	sendData8(0x06);
	
	sendCommand(0xBC);			
	sendData8(0x00);	

	sendCommand(0xFF);			
	sendData8(0x60);
	sendData8(0x01);
	sendData8(0x04);

	sendCommand(0xC3);			
	sendData8(0x13);
	sendCommand(0xC4);			
	sendData8(0x13);

	sendCommand(0xC9);			
	sendData8(0x22);

	sendCommand(0xBE);			
	sendData8(0x11); 

	sendCommand(0xE1);			
	sendData8(0x10);
	sendData8(0x0E);

	sendCommand(0xDF);			
	sendData8(0x21);
	sendData8(0x0c);
	sendData8(0x02);

	sendCommand(0xF0);   
	sendData8(0x45);
	sendData8(0x09);
	sendData8(0x08);
	sendData8(0x08);
	sendData8(0x26);
 	sendData8(0x2A);

 	sendCommand(0xF1);    
 	sendData8(0x43);
 	sendData8(0x70);
 	sendData8(0x72);
 	sendData8(0x36);
 	sendData8(0x37);  
 	sendData8(0x6F);


 	sendCommand(0xF2);   
 	sendData8(0x45);
 	sendData8(0x09);
 	sendData8(0x08);
 	sendData8(0x08);
 	sendData8(0x26);
 	sendData8(0x2A);

 	sendCommand(0xF3);   
 	sendData8(0x43);
 	sendData8(0x70);
 	sendData8(0x72);
 	sendData8(0x36);
 	sendData8(0x37); 
 	sendData8(0x6F);

	sendCommand(0xED);	
	sendData8(0x1B); 
	sendData8(0x0B); 

	sendCommand(0xAE);			
	sendData8(0x77);
	
	sendCommand(0xCD);			
	sendData8(0x63);		


	sendCommand(0x70);			
	sendData8(0x07);
	sendData8(0x07);
	sendData8(0x04);
	sendData8(0x0E); 
	sendData8(0x0F); 
	sendData8(0x09);
	sendData8(0x07);
	sendData8(0x08);
	sendData8(0x03);

	sendCommand(0xE8);			
	sendData8(0x34);

	sendCommand(0x62);			
	sendData8(0x18);
	sendData8(0x0D);
	sendData8(0x71);
	sendData8(0xED);
	sendData8(0x70); 
	sendData8(0x70);
	sendData8(0x18);
	sendData8(0x0F);
	sendData8(0x71);
	sendData8(0xEF);
	sendData8(0x70); 
	sendData8(0x70);

	sendCommand(0x63);			
	sendData8(0x18);
	sendData8(0x11);
	sendData8(0x71);
	sendData8(0xF1);
	sendData8(0x70); 
	sendData8(0x70);
	sendData8(0x18);
	sendData8(0x13);
	sendData8(0x71);
	sendData8(0xF3);
	sendData8(0x70); 
	sendData8(0x70);

	sendCommand(0x64);			
	sendData8(0x28);
	sendData8(0x29);
	sendData8(0xF1);
	sendData8(0x01);
	sendData8(0xF1);
	sendData8(0x00);
	sendData8(0x07);

	sendCommand(0x66);			
	sendData8(0x3C);
	sendData8(0x00);
	sendData8(0xCD);
	sendData8(0x67);
	sendData8(0x45);
	sendData8(0x45);
	sendData8(0x10);
	sendData8(0x00);
	sendData8(0x00);
	sendData8(0x00);

	sendCommand(0x67);			
	sendData8(0x00);
	sendData8(0x3C);
	sendData8(0x00);
	sendData8(0x00);
	sendData8(0x00);
	sendData8(0x01);
	sendData8(0x54);
	sendData8(0x10);
	sendData8(0x32);
	sendData8(0x98);

	sendCommand(0x74);			
	sendData8(0x10);	
	sendData8(0x85);	
	sendData8(0x80);
	sendData8(0x00); 
	sendData8(0x00); 
	sendData8(0x4E);
	sendData8(0x00);					
	
    sendCommand(0x98);			
	sendData8(0x3e);
	sendData8(0x07);

	sendCommand(0x35);	
	sendCommand(0x21);

	sendCommand(0x11);
	sleep_ms(120);
	sendCommand(0x29);
	sleep_ms(20);

}


void lcd::setAttributes(uint8_t scan_dir) {
    SCAN_DIR = scan_dir;

    uint8_t MemmoryAccess = 0x08;

    if (SCAN_DIR == LCD_HORIZONTAL) {
        WIDTH = LCD_WIDTH;
        HEIGHT = LCD_HEIGHT;
        MemmoryAccess = 0xc8;
    } else {
        WIDTH = LCD_HEIGHT;
        HEIGHT = LCD_WIDTH;
        MemmoryAccess = 0x68;
    }

    sendCommand(0x36);
    sendData8(MemmoryAccess);
}


void lcd::setWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend) {
   // Set the X coordinates
    sendCommand(0x2A);
    sendData8(0x00);
    sendData8(Xstart);
    sendData8((Xend)>>8);
    sendData8(Xend);

    // Set the Y coordinates
    sendCommand(0x2B);
    sendData8(0x00);
    sendData8(Ystart);
    sendData8((Yend)>>8);
    sendData8(Yend);

    sendCommand(0x2C);
    gpio_put(LCD_DC_PIN, 1);
}

void lcd::clear(uint16_t color) {

    uint16_t j;
    uint16_t image[LCD_WIDTH* LCD_HEIGHT];

    color = ((color << 8)& 0xFF00) | (color >> 8);

    for (j = 0; j < LCD_WIDTH* LCD_HEIGHT; j++) {
        image[j] = color;
    }

    setWindow(0, 0, LCD_WIDTH, LCD_HEIGHT);
    gpio_put(LCD_DC_PIN, 1);

    for (j = 0; j < LCD_HEIGHT; j++) {
        SPI_Write_nByte((uint8_t *)&image[j * LCD_WIDTH], LCD_WIDTH* 2);
    }
}


void lcd::display(uint16_t* image) {
    
    uint16_t j;
    setWindow(0, 0, WIDTH - 1, HEIGHT - 1);
    gpio_put(LCD_DC_PIN, 1);

    for (j = 0; j < LCD_HEIGHT; j++) {
        SPI_Write_nByte((uint8_t *)&image[j * LCD_WIDTH], LCD_WIDTH* 2);
    }
}

void lcd::displayWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t* image) {
    
    uint32_t Addr = 0;
    uint16_t j;

    setWindow(Xstart, Ystart, Xend, Yend);
    gpio_put(LCD_DC_PIN, 1);

    for (j = Ystart; j < Yend; j++) {
        Addr = j * WIDTH + Xstart;
        SPI_Write_nByte((uint8_t *)&image[Addr], (Xend - Xstart) * 2);
    }
}

void lcd::init(uint8_t scan_dir) {
    
    SPI_init();
    
    reset();

    setAttributes(scan_dir);
    
    initRegisters();
    
    printf("LCD initialized successfully.\n");
}
