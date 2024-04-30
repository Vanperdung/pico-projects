#ifndef _SW_LCD_H_
#define _SW_LCD_H_

#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func);
void sw_lcd_gpio_init(const lcd_io_cfg *p_lcd_io);

#endif