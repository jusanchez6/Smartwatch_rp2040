#ifndef RP2040_ERR_H
#define RP2040_ERR_H

#include <stdint.h>
#include "pico/stdlib.h"

typedef enum {
    OK = 0,
    INVALID_ARG,
    TIMEOUT,
    BUSY,
    UNKNOWN
} rp2040_err_t;

const char* rp2040_err_to_string(rp2040_err_t err);

#endif // RP2040_ERR_H