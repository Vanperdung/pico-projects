#ifndef _HAL_LCD_H_
#define _HAL_LCD_H_

#include "../lcd/lcd.h"

void hal_lcd_init(const lcd_func_cfg *p_lcd_func, const lcd_io_cfg *p_lcd_io);
void hal_lcd_func_init(const lcd_func_cfg *p_lcd_func);
void hal_lcd_hardware_init(const lcd_io_cfg *p_lcd_io);
void hal_lcd_init_cmd(void);

#endif