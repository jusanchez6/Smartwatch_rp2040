#include "QMI8658A.h"
#include "QMI8658ARegisters.h"


QMI8658A::QMI8658A(i2c_inst_t* i2c_hw, uint8_t sda_pin, uint8_t scl_pin, uint8_t address)
    : i2c_dev_(i2c_hw, sda_pin, scl_pin, address), address_(address)
{}

rp2040_err_t QMI8658A::begin() {
    uint8_t chip_id = 0xFF; // algo no cero para asegurarte que cambie

    rp2040_err_t err = read_register(WHO_AM_I_REG, &chip_id);
    std::cout << "Debug: read_register returned " << err << ", chip_id = 0x"
              << std::hex << static_cast<int>(chip_id) << std::dec << std::endl;

    if (chip_id != QMI8658A_WHO_AM_I) {
        std::cerr << "QMI8658A not found, expected ID: 0x"
                  << std::hex << static_cast<int>(QMI8658A_WHO_AM_I)
                  << ", got: 0x" << static_cast<int>(chip_id) << std::dec << std::endl;
        return ERROR;
    }

    std::cout << "QMI8658A found, ID: 0x"
              << std::hex << static_cast<int>(chip_id) << std::dec << std::endl;


    // Configurar el sensor

    write_register(CTRL7_REG, 0x01); // Habilitar el sensor

    // Reset
    // err = reset();
    // if (err != OK) {
    //     return ERROR;
    // }

    return OK;
}

void QMI8658A::read_accelerometer(int16_t* x, int16_t* y, int16_t* z) {
    uint8_t data[6];
    rp2040_err_t err = read_multiple_registers(ACCEL_X_L_REG, data, sizeof(data));
    if (err != OK) {
        return; // Handle error appropriately
    }

    *x = (int16_t)((data[1] << 8) | data[0]);
    *y = (int16_t)((data[3] << 8) | data[2]);
    *z = (int16_t)((data[5] << 8) | data[4]);
}


void QMI8658A::read_gyroscope(int16_t* x, int16_t* y, int16_t* z) {
    uint8_t data[6];
    rp2040_err_t err = read_multiple_registers(GYRO_X_L_REG, data, sizeof(data));
    if (err != OK) {
        return; // Handle error appropriately
    }

    *x = (int16_t)((data[1] << 8) | data[0]);
    *y = (int16_t)((data[3] << 8) | data[2]);
    *z = (int16_t)((data[5] << 8) | data[4]);
}


rp2040_err_t QMI8658A::reset() {
    // 1. Escribir al registro de soft reset
    rp2040_err_t err = write_register(SOFT_RESET_REG, RESET_IMU);
    if (err != OK) {
        std::cerr << "Failed to write reset command." << std::endl;
        return ERROR;
    }

    // 2. Esperar un momento para que el dispositivo se reinicie
    sleep_ms(10); // depende del sensor, 10–20 ms suele bastar

    // 3. Leer un registro conocido para confirmar que el sensor está listo
    uint8_t status = 0;
    err = read_register(0x4D, &status);
    if (err != OK) {
        std::cerr << "Failed to read reset status." << std::endl;
        return ERROR;
    }

    // 4. Comprobar si el sensor respondió con el valor esperado
    if (status != QMI8658A_RESET_SUCCESS) {
        std::cerr << "QMI8658A reset failed, status: 0x" 
                  << std::hex << static_cast<int>(status) << std::dec << std::endl;
        return ERROR;
    }

    return OK;
}


rp2040_err_t QMI8658A::read_register(uint8_t reg, uint8_t* data)
{
    uint32_t temp_data = 0;
    rp2040_err_t err = i2c_dev_.read_byte(reg, &temp_data);
    if (err == OK && data != nullptr) {
        *data = static_cast<uint8_t>(temp_data & 0xFF);
    }
    return err;
}

rp2040_err_t QMI8658A::write_register(uint8_t reg, uint8_t value)
{
    return i2c_dev_.write_byte(reg, value);
}

rp2040_err_t QMI8658A::read_multiple_registers(uint8_t reg, uint8_t* data, size_t len)
{
    if (data == nullptr || len == 0) {
        return ERROR; // Invalid parameters
    }
    
    return i2c_dev_.read_nbytes(reg, data, len);
}

