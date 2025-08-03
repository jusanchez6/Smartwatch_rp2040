#ifndef RTC_H
#define RTC_H

#include <stdint.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"

#include "rp2040_err.h"




rp2040_err_t dev_rtc_init(void);

rp2040_err_t dev_rtc_set_datetime(const datetime_t *dt);

rp2040_err_t dev_rtc_get_datetime(datetime_t *dt);




#endif // RTC_H