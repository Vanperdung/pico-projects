#ifndef _SW_LCD_H_
#define _SW_LCD_H_

#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func, uint8_t scan_dir);
void sw_lcd_gpio_init(const lcd_io_cfg *p_lcd_io);
void sw_lcd_clear_screen(lcd_frame frame, uint16_t color);
void sw_lcd_display_point(uint16_t X, uint16_t Y, uint16_t color);
void sw_lcd_display_partial(lcd_frame frame, uint16_t *image);
void sw_lcd_display_fullscreen(lcd_frame frame, uint16_t *image);
void sw_lcd_set_screen(lcd_frame frame);
#endif