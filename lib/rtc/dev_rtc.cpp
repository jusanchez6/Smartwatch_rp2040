#include "dev_rtc.h"


dev_rtc::dev_rtc() {
    rtc_init();
}

void dev_rtc::set_datetime(const datetime_t &dt) {
    current_time = dt;
    rtc_set_datetime(&current_time);
    sleep_us(64);
}

datetime_t dev_rtc::get_datetime() {
    rtc_get_datetime(&current_time);
    return current_time;
}

void dev_rtc::print_datetime() {
    char buffer[64];
    rtc_get_datetime(&current_time);
    datetime_to_str(buffer, sizeof(buffer), &current_time);
    printf("Current RTC time: %s\n", buffer);
}