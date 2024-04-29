#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "lcd/lcd.h"
#include "lvgl/lvgl.h"
#include "hal/hal_lcd.h"
#include "hal/hal_uart.h"
#include "hal/hal_timer.h"

static struct repeating_timer lvgl_timer;

static bool repeating_lvgl_timer_callback(struct repeating_timer *timer)
{
    lv_tick_inc(5);
    return true;
}

int main(void)
{
    stdio_init_all();
    hal_uart_init();
    hal_repeating_timer_init(-5, repeating_lvgl_timer_callback, NULL, &lvgl_timer);
    lv_init();
    
    while (1)
    {
        lv_timer_handler();
        sleep_ms(2);
    }
    return 0;
}