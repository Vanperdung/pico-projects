#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "lcd/lcd.h"
#include "lvgl/lvgl.h"
#include "hal/hal_lcd.h"
#include "hal/hal_uart.h"

int main(void)
{
    stdio_init_all();
    hal_uart_init();
    lv_init();
    printf("-------------------Setup done-------------------\r\n");
    
    while (1)
    {
        lv_timer_handler();
        sleep_ms(5);
    }
    return 0;
}