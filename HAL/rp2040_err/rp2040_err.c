#include "rp2040_err.h"

const char* rp2040_err_to_string(rp2040_err_t err) {
    switch (err) {
        case OK:
            return "OK";
        case INVALID_ARG:
            return "Invalid argument";
        case TIMEOUT:
            return "Timeout";
        case BUSY:
            return "Busy";
        case UNKNOWN:
            return "Unknown error";
        default:
            return "Unrecognized error code";
    }
}
