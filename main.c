#include <stdio.h>
#include "pico/stdlib.h"

#include "smartwatch.h"


int main()
{
    if (smartwatch_init() != 0) {return -1;} 

    // Bucle principal para LVGL

    return 0;
}
