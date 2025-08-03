#include "rtc.h"
#include <stdio.h>
#include "hardware/rtc.h"
#include "pico/util/datetime.h"

rp2040_err_t dev_rtc_init(void) {
    rtc_init();
    return OK;
}

rp2040_err_t dev_rtc_set_datetime(const datetime_t *dt) {
    if (dt == NULL) {
        return INVALID_ARG;
    }

    if (!rtc_set_datetime(dt)) {
        return UNKNOWN;
    }

    return OK;
}

rp2040_err_t dev_rtc_get_datetime(datetime_t *dt) {
    if (dt == NULL) {
        return INVALID_ARG;
    }

    if (!rtc_get_datetime(dt)) {
        return UNKNOWN;
    }

    return OK;
}

