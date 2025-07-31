#include "I2C_dev.h"

I2C_dev::I2C_dev(i2c_inst_t* i2c_hw, uint8_t sda_pin, uint8_t scl_pin, uint8_t addr)
    : i2c_(i2c_hw), addr_(addr), sda_pin_(sda_pin), scl_pin_(scl_pin)
{
    i2c_init(i2c_, 400 * 1000); // 400 kHz
    gpio_set_function(sda_pin_, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin_, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin_);
    gpio_pull_up(scl_pin_);
}



rp2040_err_t I2C_dev::write_byte(uint8_t reg, uint8_t value) {
    uint8_t buffer[2] = { reg, value };
    int result = i2c_write_blocking(i2c_, addr_, buffer, 2, false); // stop = true

    return (result == 2) ? OK : ERROR;
}


rp2040_err_t I2C_dev::read_byte(uint8_t reg, uint32_t* value) {
    
    if (i2c_read_blocking(i2c_, addr_, &reg, 1, true) < 0) {
        return ERROR;
    }
    if (i2c_read_blocking(i2c_, addr_, (uint8_t*)value, 1, false) < 0) {
        return ERROR;
    }
    return OK;  
}


rp2040_err_t I2C_dev::write_nbytes(uint8_t reg, const uint8_t* data, uint32_t len) {
    
    if (i2c_write_blocking(i2c_, addr_, &reg, len, false) < 0) {
        return ERROR;
    }

    return OK;
}

rp2040_err_t I2C_dev::read_nbytes(uint8_t reg, uint8_t* data, uint32_t len) {
    
    if (i2c_write_blocking(i2c_, addr_, &reg, 1, false) < 0) {
        return ERROR;
    }
    
    if (i2c_read_blocking(i2c_, addr_, data, len, false) < 0) {
        return ERROR;
    }
    
    return OK;
}