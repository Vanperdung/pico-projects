#include "hal_lcd.h"
#include "../lcd/lcd.h"

void hal_lcd_init(const lcd_func_cfg *p_lcd_func, const lcd_io_cfg *p_lcd_io)
{
    hal_lcd_func_init(p_lcd_func);
    hal_lcd_hardware_init(p_lcd_io);
    hal_lcd_init_cmd();
}

void hal_lcd_func_init(const lcd_func_cfg *p_lcd_func)
{
    lcd_set_func(p_lcd_func);
}

void hal_lcd_hardware_init(const lcd_io_cfg *p_lcd_io)
{
    lcd_set_io(p_lcd_io);
}

void hal_lcd_init_cmd(void)
{
    lcd_init();
}