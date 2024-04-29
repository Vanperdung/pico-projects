#include "sw_lcd.h"
#include "lcd.h"

void sw_lcd_init(const lcd_func_cfg *p_lcd_func, const lcd_io_cfg *p_lcd_io)
{
    sw_lcd_func_init(p_lcd_func);
    sw_lcd_hardware_init(p_lcd_io);
    sw_lcd_init_cmd();
}

void sw_lcd_func_init(const lcd_func_cfg *p_lcd_func)
{
    lcd_set_func(p_lcd_func);
}

void sw_lcd_hardware_init(const lcd_io_cfg *p_lcd_io)
{
    lcd_set_io(p_lcd_io);
}

void sw_lcd_gpio_init(const lcd_io_cfg *p_lcd_io)
{
    
}

void sw_lcd_init_cmd(void)
{
    lcd_init();
}