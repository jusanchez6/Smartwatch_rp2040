#ifndef QMI8658AREGISTERS_H
#define QMI8658AREGISTERS_H


#define QMI8658A_I2C_ADDRESS    (0x6A)              // Default I2C address for QMI8658A 
#define QMI8658A_WHO_AM_I        (0x05)             // WHO_AM_I register address
#define QMI8658A_REVISION_ID    (0x6A)              // Expected value for WHO_AM_I register


#define RESET_IMU               (0x0B)              // Value to reset the IMU
#define QMI8658A_RESET_SUCCESS  (0x80)              // Expected value after reset



/**
 * @addtogroup QMI8658A_PEDOMETER_PARAMS
 * 
 * @{
 * 
 * Parámetros para la configuración del pedometer del sensor IMU.
 */

/*! @brief Indica la cantidad de muestras por lote/ventana para el cálculo */
#define PED_SAMPLE_CNT_L 0x32
/*! @brief Indica la cantidad de muestras por lote/ventana para el cálculo */
#define PED_SAMPLE_CNT_H 0x00
/*! @brief Indica el umbral para la detección válida de pico a pico */
#define PED_FIX_PEAK2PEAK_L 0xD0
/*! @brief Indica el umbral para la detección válida de pico a pico */
#define PED_FIX_PEAK2PEAK_H 0x00
/*! @brief Indica el umbral para la detección de picos en comparación con el promedio */
#define PED_FIX_PEAK_L      0x66
/*! @brief Indica el umbral para la detección de picos en comparación con el promedio */
#define PED_FIX_PEAK_H      0x00
/*! @brief Indica la duración máxima (ventana de tiempo límite) para un paso. Restablece el cálculo si no se detectan picos dentro de esta duración. */
#define PED_TIME_UP_L       0xC8
/*! @brief Indica la duración máxima (ventana de tiempo límite) para un paso. Restablece el cálculo si no se detectan picos dentro de esta duración. */
#define PED_TIME_UP_H       0x00
/*! @brief Indica la duración mínima para un paso. Los picos detectados dentro de esta duración (tiempo de quietud) se ignoran. */
#define PED_TIME_LOW        0x14
/*! @brief Indica la cantidad mínima de pasos continuos para comenzar el conteo de pasos válidos. Si los pasos detectados de manera continua son inferiores
a esta cantidad y se alcanza el tiempo límite, los pasos no serán tenidos en cuenta; de lo contrario, todos los pasos detectados serán contabilizados, y se comenzará a contar cada paso siguiente antes de que se alcance el tiempo límite. Esto es útil para filtrar los pasos falsos detectados por vibraciones no relacionadas con pasos. */
#define PED_CNT_ENTRY  0x05
/*! @brief Se recomienda un valor de 0 */
#define PED_FIX_PRECISION   0x00
/*! @brief La cantidad de pasos después de la cual se actualizan los registros de salida del podómetro */
#define PED_SIG_COUNT       0x01
/*! @brief Máscara para habilitar el podómetro */
#define PEDOMETER_EN 0x10



/**
 * @}
 * 
 */

enum IMU_REGISTERS
{
    /*! \brief Devise Identifier*/
    WHO_AM_I_REG = 0x00,
    /*! \brief Device Register ID*/
    REVISION_ID_REG = 0x01,
    /*! \brief SPI interface and sensor enable*/
    CTRL1_REG = 0x02,
    /*! \brief Accelerometer: OPutput Data Rate, Full Scale, Self test*/
    CTRL2_REG = 0x03,
    /*! \brief Gyroscope: Output Data Rate, Full Scale, Self test*/
    CTRL3_REG = 0x04,
    /*! \brief RESERVED*/
    CTRL4_REG = 0x05,
    /*! \brief Low pass filter setting*/
    CTRL5_REG = 0x06,
    /*! \brief RESERVED*/
    CTRL6_REG = 0x07,
    /*! \brief RESERVED 1*/
    CTRL7_REG = 0x08,
    /*! \brief Motion Detection Control*/
    CTRL8_REG = 0x09,
    /*! \brief Host commands*/
    CTRL9_REG = 0x0A,
    /*! \brief Calibration Register 1 lower bits*/
    CAL1_L_REG = 0x0B,
    /*! \brief Calibration Register 1 higher bits*/
    CAL1_H_REG = 0x0C,
    /*! \brief Calibration Register 2 lower bits*/
    CAL2_L_REG = 0x0D,
    /*! \brief Calibration Register 2 higher bits*/
    CAL2_H_REG = 0x0E,
    /*! \brief Calibration Register 3 lower bits*/
    CAL3_L_REG = 0x0F,
    /*! \brief Calibration Register 3 higher bits*/
    CAL3_H_REG = 0x10,
    /*! \brief Calibration Register 4 lower bits*/
    CAL4_L_REG = 0x11,
    /*! \brief Calibration Register 4 higher bits*/
    CAL4_H_REG = 0x12,
    /*! \brief FIFO watermark level in ODRs*/
    FIFO_WTH_TH_REG = 0x13,
    /*! \brief FIFO control*/
    FIFO_CTRL_REG = 0x14,
    /*! \brief FIFO Sample count LSBs*/
    FIFO_SMPL_CONT_REG = 0x15,
    /*! \brief FIFO Status*/
    FIFO_STATUS_REG = 0x16,
    /*! \brief FIFO data*/
    FIFO_DATA_REG = 0x17,
    /*! \brief Sensor Data Availability with the Locking Mechanism*/
    STATUSINT_REG = 0x2D,
    /*! \brief Ouput Data Over Run and Data Availability*/
    STATUS0_REG = 0x2E,
    /*! \brief Miscellaneous status: any motion, no motion, significan motrion, pedometer, tap*/
    STATUS1_REG = 0x2F,
    /*! \brief Sample time stamp lower bits*/
    TIMESTAMP_LOW_REG = 0x30,
    /*! \brief Sample time stamp middle bits*/
    TIMESTAMP_MID_REG = 0x31,
    /*! \brief Sample time stamp higher bits*/
    TIMESTAMP_HIGH_REG = 0x32,
    /*! \brief Temperature Output Data*/
    TEMP_OUT_L_REG = 0x33,
    /*! \brief Temperature Output Data*/
    TEMP_OUT_H_REG = 0x34,
    /*! \brief Accel X Output Data lower bits*/
    ACCEL_X_L_REG = 0x35,
    /*! \brief Accel X Output Data higher bits*/
    ACCEL_X_H_REG = 0x36,
    /*! \brief Accel Y Output Data lower bits*/
    ACCEL_Y_L_REG = 0x37,
    /*! \brief Accel Y Output Data higher bits*/
    ACCEL_Y_H_REG = 0x38,
    /*! \brief Accel Z Output Data lower bits*/
    ACCEL_Z_L_REG = 0x39,
    /*! \brief Accel Z Output Data higher bits*/
    ACCEL_Z_H_REG = 0x3A,
    /*! \brief Gyro X Output Data lower bits*/
    GYRO_X_L_REG = 0x3B,
    /*! \brief Gyro X Output Data higher bits*/
    GYRO_X_H_REG = 0x3C,
    /*! \brief Gyro Y Output Data lower bits*/
    GYRO_Y_L_REG = 0x3D,
    /*! \brief Gyro Y Output Data higher bits*/
    GYRO_Y_H_REG = 0x3E,
    /*! \brief Gyro Z Output Data lower bits*/
    GYRO_Z_L_REG = 0x3F,
    /*! \brief Gyro Z Output Data higher bits*/
    GYRO_Z_H_REG = 0x40,
    /*! \brief Calibration-On-Demand status register*/
    COD_STATUS_REG = 0x46,
    /*! \brief General Purpose register*/
    dQW_L_REG = 0x49,
    /*! \brief General Purpose register*/
    dQW_H_REG = 0x4A,
    /*! \brief General Purpose register*/
    dQX_L_REG = 0x4B,
    /*! \brief RESERVED*/
    dQX_H_REG = 0x4C,
    /*! \brief General Purpose register*/
    dQY_L_REG = 0x4D,
    /*! \brief RESERVED 1*/
    dQY_H_REG = 0x4E,
    /*! \brief RESERVED 2*/
    dQZ_L_REG = 0x4F,
    /*! \brief RESERVED 3*/
    dQZ_H_REG = 0x50,
    /*! \brief General Purpose register*/
    dVX_L_REG = 0x51,
    /*! \brief General Purpose register*/
    dVX_H_REG = 0x52,
    /*! \brief General Purpose register*/
    dVY_L_REG = 0x53,
    /*! \brief General Purpose register*/
    dVY_H_REG = 0x54,
    /*! \brief General Purpose register*/
    dVZ_L_REG = 0x55,
    /*! \brief General Purpose register*/
    dVZ_H_REG = 0x56,
    /*! \brief Axis, direction, number of detected tap*/
    TAP_STATUS_REG = 0x59,
    /*! \brief low byte of step count of pedometer*/
    STEP_CNT_LOW_REG = 0x5A,
    /*! \brief middle byte of step count of pedometer*/
    STEP_CNT_MIDL_REG = 0x5B,
    /*! \brief high byte of step count of pedometer*/
    STEP_CNT_HIGH_REG = 0x5C,

    /*! \brief Soft Reset Register*/
    SOFT_RESET_REG = 0x60,
};



/**
 * @addtogroup QMI8658A_CTRL9_COMMANDS
 * @{
 *
 * Comandos para configurar el sensor IMU.
 */
enum QMI8658A_CTRL9_COMMANDS
{
    /*! \brief Acknowledge command*/
    CTRL_CMD_ACK = 0x00,
    /*! \brief Set up the and enable Wake on Motion WoM*/
    CTRL_CMD_WRITE_WOM_SETTING = 0x08,
    /*! \brief Configure Tap detection*/
    CTRL_CMD_TAP = 0x0C,
    /*! \brief Configure Pedometer*/
    CTRL_CMD_PEDOMETER = 0x0D,
    /*! \brief Configure Any motion/ no motion / significant motion detection*/
    CTRL_CMD_CONFIGURE_MOTION = 0x0E,
    /*! \brief Reset pedometer count (step counter)*/
    CTRL_CMD_RESET_PEDOMETER = 0x0F,
};

/**
 * @}
 *
 */

/**
 * @addtogroup CTRL2 Accelerometer settings
 *
 * @{
 *
 */

/**
 * @brief Enumeración de las tasas de salida de datos del sensor IMU.
 *
 */
enum QMI8658_ODR
{
    /*! @brief 7174.4 Hz*/
    ODR_ACC_7174 = 0x00,
    /*! @brief 3587.2 Hz*/
    ODR_ACC_3587 = 0x01,
    /*! @brief 1793.6 Hz*/
    ODR_ACC_1793 = 0x02,
    /*! @brief 896.8 Hz*/
    ODR_ACC_896 = 0x03,
    /*! @brief 448.4 Hz*/
    ODR_ACC_448 = 0x04,
    /*! @brief 224.2 Hz*/
    ODR_ACC_224 = 0x05,
    /*! @brief 112.1 Hz*/
    ODR_ACC_112 = 0x06,
    /*! @brief 56.1 Hz*/
    ODR_ACC_56 = 0x07,
    /*! @brief 28.1 Hz*/
    ODR_ACC_28 = 0x08,
};

/**
 * @brief Enumeración de la escala de aceleración del sensor IMU.
 *
 */
enum QMI8658_aFS
{
    /*! @brief 2g*/
    aFS_2g = 0x00,
    /*! @brief 4g*/
    aFS_4g = 0x10,
    /*! @brief 8g*/
    aFS_8g = 0x20,
    /*! @brief 16g*/
    aFS_16g = 0x30,
};

/**
 * @brief Enumeración de los modos de auto test del sensor IMU.
 *
 */
enum QMI8568_aST
{
    /*! @brief Dissable self test mode*/
    DIS_self_test = 0x00,
    /*! @brief Enable self test mode*/
    EN_self_test = 0x80,
};

/**
 * @}
 *
 */


/**
 * @addtogroup CTRL3 Gyroscope settings
 *
 * @{
 *
 */

/**
 * @brief Enumeración de las tasas de salida de datos del sensor IMU.
 *
 */
enum QMI8658_ODR_GYRO
{
    /*! @brief 7174.4 Hz*/
    ODR_GYRO_7174 = 0x00,
    /*! @brief 3587.2 Hz*/
    ODR_GYRO_3587 = 0x01,
    /*! @brief 1793.6 Hz*/
    ODR_GYRO_1793 = 0x02,
    /*! @brief 896.8 Hz*/
    ODR_GYRO_896 = 0x03,
    /*! @brief 448.4 Hz*/
    ODR_GYRO_448 = 0x04,
    /*! @brief 224.2 Hz*/
    ODR_GYRO_224 = 0x05,
    /*! @brief 112.1 Hz*/
    ODR_GYRO_112 = 0x06,
    /*! @brief 56.1 Hz*/
    ODR_GYRO_56 = 0x07,
    /*! @brief 28.1 Hz*/
    ODR_GYRO_28 = 0x08,
};

/**
 * @brief Enumeración de la escala de giro del sensor IMU.
 *
 */
enum QMI8658_gFS
{
    /*! @brief 16 dps*/
    gFS_16dps = 0x00,
    /*! @brief 32 dps*/
    gFS_32dps = 0x01,
    /*! @brief 64 dps*/
    gFS_64dps = 0x02,
    /*! @brief 128 dps*/
    gFS_128dps = 0x03,
    /*! @brief 256 dps*/
    gFS_256dps = 0x04,
    /*! @brief 512 dps*/
    gFS_512dps = 0x05,
    /*! @brief 1024 dps*/
    gFS_1024dps = 0x06,
    /*! @brief 2048 dps*/
    gFS_2048dps = 0x07,

};

enum QMI8568_gST
{
    /*! @brief Disable gyro self test*/
    DIS_SELF_TEST = 0x00,
    /*! @brief Enable Self test*/
    EN_SELF_TEST = 0x01,
};

/**
* @}
}

}
 *
 */

#endif  // QMI8658ARegisters.h 
        
