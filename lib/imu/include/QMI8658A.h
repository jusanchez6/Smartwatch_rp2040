#ifndef QMI8658A_H
#define QMI8658A_H

#include <iostream>
#include "I2C_dev.h"
#include "QMI8658ARegisters.h"

using namespace std;

class QMI8658A{
public:
    /**
     * @brief Constructor for the QMI8658A IMU sensor.
     * 
     * @param i2c_hw Pointer to the I2C hardware instance.
     * @param sda_pin SDA pin number.
     * @param scl_pin SCL pin number.
     * @param address I2C address of the QMI8658A sensor.
     */
    QMI8658A(i2c_inst_t* i2c_hw, uint8_t sda_pin, uint8_t scl_pin, uint8_t address);


    /**
     * @brief Initialize the QMI8658A sensor.
     * 
     * @return rp2040_err_t Result of the initialization.
     */
    rp2040_err_t begin();
    
    /**
     * @brief Read accelerometer data from the QMI8658A sensor.
     * 
     * @param x Pointer to store the X-axis accelerometer data.
     * @param y Pointer to store the Y-axis accelerometer data.
     * @param z Pointer to store the Z-axis accelerometer data.
     */
    void read_accelerometer(int16_t* x, int16_t* y, int16_t* z);

    /**
     * @brief Read gyroscope data from the QMI8658A sensor.
     * 
     * @param x Pointer to store the X-axis gyroscope data.
     * @param y Pointer to store the Y-axis gyroscope data.
     * @param z Pointer to store the Z-axis gyroscope data.
     */
    void read_gyroscope(int16_t* x, int16_t* y, int16_t* z);

private:

    /**
     * @brief I2C device instance for communication with the QMI8658A sensor.
     */
    I2C_dev i2c_dev_; 
    
    /**
     * @brief I2C address of the QMI8658A sensor.
     */
    uint8_t address_;

    /**
     * @brief QMI8658A reset status.
     */
    uint8_t qmi_reset_status_;


    /**
     * @brief Read a register from the QMI8658A sensor.
     * 
     * @param reg Register address to read.
     * @param data Pointer to store the read data.
     * @return rp2040_err_t Result of the read operation.
     */
    rp2040_err_t write_register(uint8_t reg, uint8_t value);

    /**
     * @brief Read a register from the QMI8658A sensor.
     * 
     * @param reg Register address to read.
     * @param value Pointer to store the read value.
     * @return rp2040_err_t Result of the read operation.
     */
    rp2040_err_t read_register(uint8_t reg, uint8_t* value);

    /**
     * @brief Reset the QMI8658A sensor.
     * 
     * @return rp2040_err_t Result of the reset operation.
     */
    rp2040_err_t reset();


    /**
     * @brief Read multiple registers from the QMI8658A sensor.
     * 
     * @param reg Starting register address to read.
     * @param data Pointer to store the read data.
     * @param len Number of registers to read.
     * @return rp2040_err_t Result of the read operation.
     */
    rp2040_err_t read_multiple_registers(uint8_t reg, uint8_t* data, size_t len);
    
};







#endif // QMI8658A_H
