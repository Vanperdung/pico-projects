#ifndef _SW_LCD_H_
#define _SW_LCD_H_

#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func, const lcd_io_cfg *p_lcd_io);
void sw_lcd_func_init(const lcd_func_cfg *p_lcd_func);
void sw_lcd_hardware_init(const lcd_io_cfg *p_lcd_io);
void sw_lcd_init_cmd(void);

#endif