#ifndef DEV_RTC_H
#define DEV_RTC_H

#include <stdint.h>
#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"




class dev_rtc
{
private:

    datetime_t current_time;

public:

    /**
     * @brief Initialize the RTC device.
     */
    dev_rtc();
    
    void set_datetime (const datetime_t &dt);

    datetime_t get_datetime();

    void print_datetime();
};

#endif // DEV_RTC_H