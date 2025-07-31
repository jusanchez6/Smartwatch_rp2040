#include <iostream>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"

#include "dev_rtc.h"

using namespace std;

dev_rtc rtc;

int main()
{
    stdio_init_all();
    datetime_t dt = {2025, 7, 31, 4, 10, 5, 0}; // Set to October 1, 2023, 12:00:00
    rtc.set_datetime(dt);
    

    while (true)
    {
        rtc.print_datetime();
        sleep_ms(60000);
    }
}


int16_t year;    ///< 0..4095
    int8_t month;    ///< 1..12, 1 is January
    int8_t day;      ///< 1..28,29,30,31 depending on month
    int8_t dotw;     ///< 0..6, 0 is Sunday
    int8_t hour;     ///< 0..23
    int8_t min;      ///< 0..59
    int8_t sec;      ///< 0..59