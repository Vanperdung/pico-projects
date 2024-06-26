#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "lcd/sw_lcd.h"
#include "lcd/lcd.h"
#include "lvgl/lvgl.h"
#include "uart/sw_uart.h"
#include "timer/sw_timer.h"
#include "gpio/sw_gpio.h"
#include "spi/sw_spi.h"
#include "clock/sw_clock.h"
#include "hal/hal_lvgl.h"
#include "devicetree.h"

int main(void)
{
    lcd_io_cfg lcd_io = SET_LCD_IO(LCD_RST, LCD_DC, LCD_SPI_CS, LCD_BL);
    lcd_func_cfg lcd_func_cfg = SET_LCD_FUNC(sw_gpio_set_bl, sw_gpio_set_reset,
                                             sw_gpio_set_dc, sw_gpio_set_cs, sleep_ms,
                                             sw_spi_write_bytes, NULL);
    lcd_frame frame = {{0, 0}, {LCD_WIDTH - 1, LCD_HEIGHT - 1}};

    // Hardware configurations
    sw_set_sys_clock();
    stdio_init_all();
    sw_uart_init();
    sw_measure_freqs();
    sw_spi_dma_init(270000 * 1000);
    sw_lcd_gpio_init(&lcd_io);
    sw_lcd_init(&lcd_func_cfg, HORIZONTAL);
    sw_lcd_clear_screen(frame, WHITE);

    // Software configurations
    hal_lvgl_init();

    while (1)
    {
        lv_timer_handler();
        sleep_ms(5);
    }
}