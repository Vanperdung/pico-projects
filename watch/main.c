#include <stdio.h>
#include "pico/stdlib.h"
#include "lcd/lcd.h"
#include "lvgl/lvgl.h"
#include "hal/hal_lcd.h"
#include "lvgl/examples/lv_examples.h"

int main(void)
{
    lv_init();

    while (1)
    {
        lv_timer_handler();
        sleep_ms(5);
    }
    return 0;
}