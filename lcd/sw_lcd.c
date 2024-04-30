#include <stdio.h>
#include <assert.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "sw_lcd.h"
#include "../gpio/sw_gpio.h"
#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func, uint8_t scan_dir)
{
    lcd_set_func(p_lcd_func);
    lcd_init(scan_dir);
}

void sw_lcd_gpio_init(const lcd_io_cfg *p_lcd_io)
{
    assert(p_lcd_io);
    lcd_set_io(p_lcd_io);

    sw_gpio_mode_init(p_lcd_io->reset_pin, 1);
    sw_gpio_mode_init(p_lcd_io->dc_pin, 1);
    sw_gpio_mode_init(p_lcd_io->cs_pin, 1);
    sw_gpio_mode_init(p_lcd_io->bl_pin, 1);

    sw_gpio_write(p_lcd_io->cs_pin, 1);
    sw_gpio_write(p_lcd_io->dc_pin, 0);
    sw_gpio_write(p_lcd_io->bl_pin, 1);
}

void sw_lcd_clear_screen(lcd_frame frame, uint16_t color)
{
    lcd_clear_screen(frame, color);
}

void sw_lcd_display_point(uint16_t X, uint16_t Y, uint16_t color)
{
    lcd_display_point(X, Y, color);
}

void sw_lcd_display_partial(lcd_frame frame, uint16_t *image)
{
    lcd_display_partial(frame, image);
}

void sw_lcd_display_fullscreen(lcd_frame frame, uint16_t *image)
{
    lcd_display_fullscreen(frame, image);
}