#include <stdio.h>
#include <assert.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "sw_lcd.h"
#include "../gpio/sw_gpio.h"
#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func)
{
    lcd_set_func(p_lcd_func);
    lcd_init();
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