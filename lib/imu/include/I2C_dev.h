#ifndef I2C_dev_H
#define I2C_dev_H



#include "hardware/i2c.h"
#include "hardware/gpio.h"

/** @brief Enumeración de errores para las operaciones de I2C.*/
enum RP2040_Error {
    OK = 0,
    ERROR,
    TIMEOUT,
    NACK
};

typedef enum RP2040_Error rp2040_err_t;


/**
 * @brief Clase para manejar la comunicación I2C en RP2040.
 * 
 * Esta clase encapsula las operaciones de lectura y escritura en un dispositivo I2C.
 * Permite la configuración del hardware I2C, así como la lectura y escritura de bytes y bloques de datos.
 * 
 * @note Esta clase está diseñada para ser utilizada con el microcontrolador RP2040.
 */
class I2C_dev {
public:
    /**
     * @brief Constructor for the I2C device.
     * 
     * @param i2c_hw Pointer to the I2C hardware instance.
     * @param sda_pin SDA pin number.
     * @param scl_pin SCL pin number.
     * @param addr I2C address of the device.
     */
    I2C_dev(i2c_inst_t* i2c_hw, uint8_t sda_pin, uint8_t scl_pin, uint8_t addr);

    /**
     * @brief Destructor for the I2C device.
     */
    ~I2C_dev();
    

    /**
     * @brief Write a single byte to a register.
     * 
     * @param reg Register address.
     * @param value Value to write.
     * @return rp2040_err_t Result of the operation.
     */
    rp2040_err_t write_byte(uint8_t reg, const uint8_t value);

    /**
     * @brief Read a single byte from a register.
     * 
     * @param reg Register address.
     * @param pvalue Pointer to store the read value.
     * @return rp2040_err_t Result of the operation.
     */
    rp2040_err_t read_byte(uint8_t reg, uint32_t* pvalue);
    
    /**
     * @brief Write multiple bytes to a register.
     * 
     * @param reg Register address.
     * @param pdata Pointer to the data to write.
     * @param len Number of bytes to write.
     * @return rp2040_err_t Result of the operation.
     */
    rp2040_err_t write_nbytes(uint8_t reg, const uint8_t* pdata, uint32_t len);
    
    /**
     * @brief Read multiple bytes from a register.
     * 
     * @param reg Register address.
     * @param data Pointer to store the read data.
     * @param len Number of bytes to read.
     * @return rp2040_err_t Result of the operation.
     */
    rp2040_err_t read_nbytes(uint8_t reg, uint8_t* data, uint32_t len);


private:
    /**
     * @brief Pointer to the I2C hardware instance.
     */
    i2c_inst_t* i2c_;

    /**
     * @brief I2C address of the device.
     */
    uint8_t addr_;

    /**
     * @brief SDA pin number.
     */
    uint8_t sda_pin_;

    /**
     * @brief SCL pin number.
     */
    uint8_t scl_pin_;
};





#endif // I2C_RP2040_H
