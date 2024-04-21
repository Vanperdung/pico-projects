#include "lcd.h"

void lcd_control_reset(const lcd_io_cfg *lcd_io, bool val)
{
    gpio_put(lcd_io->reset_pin, val);
}

void lcd_control_data_cmd(const lcd_io_cfg *lcd_io, bool val)
{
    gpio_put(lcd_io->dc_pin, val);
}

void lcd_control_chip_select(const lcd_io_cfg *lcd_io, bool val)
{
    gpio_put(lcd_io->cs_pin, val);
}

void lcd_write_cmd(const lcd_io_cfg *lcd_io, const lcd_func_cfg *lcd_func, uint cmd)
{
    lcd_func->control_data_cmd(lcd_io, LCD_OFF);
    lcd_func->control_chip_select(lcd_io, LCD_OFF);
    // TODO spi_tx(&cmd, sizeof(cmd))
    lcd_func->control_chip_select(lcd_io, LCD_ON);
}

void lcd_write_data(const lcd_io_cfg *lcd_io, const lcd_func_cfg *lcd_func, uint cmd)
{
    
}

lcd_func_cfg lcd_func = SET_LCD_FUNC()