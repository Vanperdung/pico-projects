#include "lcd.h"

lcd_func_cfg lcd_func = {0};

void lcd_set_func(const lcd_func_cfg *p_lcd_func)
{
    memcpy(&lcd_func, p_lcd_func, sizeof(lcd_func_cfg));
}

// void lcd_control_reset(const lcd_io_cfg *lcd_io, bool val)
// {
//     gpio_put(lcd_io->reset_pin, val);
// }

// void lcd_control_data_cmd(const lcd_io_cfg *lcd_io, bool val)
// {
//     gpio_put(lcd_io->dc_pin, val);
// }

// void lcd_control_chip_select(const lcd_io_cfg *lcd_io, bool val)
// {
//     gpio_put(lcd_io->cs_pin, val);
// }

void lcd_write_cmd(const lcd_io_cfg *lcd_io, uint8_t cmd)
{
    lcd_func.control_data_cmd(lcd_io, LCD_OFF);
    lcd_func.control_chip_select(lcd_io, LCD_OFF);
    // TODO spi_tx(&cmd, sizeof(cmd))
    lcd_func.control_chip_select(lcd_io, LCD_ON);
}

void lcd_write_data(const lcd_io_cfg *lcd_io, uint8_t *data, size_t len)
{
    lcd_func.control_data_cmd(lcd_io, LCD_ON);
    lcd_func.control_chip_select(lcd_io, LCD_OFF);
    // TODO spi_tx(data, len)
    lcd_func.control_chip_select(lcd_io, LCD_ON);   
}

void lcd_write_byte(const lcd_io_cfg *lcd_io, uint8_t val)
{
    lcd_func.write_data(lcd_io, &val, sizeof(val));
}

void lcd_write(const lcd_io_cfg *lcd_io, uint8_t *data, size_t len)
{
    lcd_func.write_cmd(lcd_io, LCD_CMD_MEM_WR);
    lcd_func.write_data(lcd_io, data, len);
}

void lcd_write_continuos(const lcd_io_cfg *lcd_io, uint8_t *data, size_t len)
{
    lcd_func.write_cmd(lcd_io, LCD_CMD_MEM_WR_CONT);
    lcd_func.write_data(lcd_io, data, len);
}

void lcd_init(const lcd_io_cfg *lcd_io)
{
    lcd_func.control_chip_select(lcd_io, LCD_ON);
    lcd_func.sleep(5);
    lcd_func.control_reset(lcd_io, LCD_OFF);
    lcd_func.sleep(10);
    lcd_func.control_reset(lcd_io, LCD_OFF);
    lcd_func.sleep(120);

    lcd_func.write_cmd(lcd_io, 0xEF);
    
    lcd_func.write_cmd(lcd_io, 0xEB);
    lcd_func.write_byte(lcd_io, 0x14);
    
    lcd_func.write_cmd(lcd_io, 0xFE);
    lcd_func.write_cmd(lcd_io, 0xEF);
    
    lcd_func.write_cmd(lcd_io, 0xEB);
    lcd_func.write_byte(lcd_io, 0x14);
    
    lcd_func.write_cmd(lcd_io, 0x84);
    lcd_func.write_byte(lcd_io, 0x40);
    
    lcd_func.write_cmd(lcd_io, 0x85);
    lcd_func.write_byte(lcd_io, 0xFF);
    
    lcd_func.write_cmd(lcd_io, 0x86);
    lcd_func.write_byte(lcd_io, 0xFF);
    
    lcd_func.write_cmd(lcd_io, 0x87);
    lcd_func.write_byte(lcd_io, 0xFF);
    
    lcd_func.write_cmd(lcd_io, 0x88);
    lcd_func.write_byte(lcd_io, 0x0A);
    
    lcd_func.write_cmd(lcd_io, 0x89);
    lcd_func.write_byte(lcd_io, 0x21);
    
    lcd_func.write_cmd(lcd_io, 0x8A);
    lcd_func.write_byte(lcd_io, 0x00);
    
    lcd_func.write_cmd(lcd_io, 0x8B);
    lcd_func.write_byte(lcd_io, 0x80);
    
    lcd_func.write_cmd(lcd_io, 0x8C);
    lcd_func.write_byte(lcd_io, 0x01);
    
    lcd_func.write_cmd(lcd_io, 0x8D);
    lcd_func.write_byte(lcd_io, 0x01);
    
    lcd_func.write_cmd(lcd_io, 0x8E);
    lcd_func.write_byte(lcd_io, 0xFF);
    
    lcd_func.write_cmd(lcd_io, 0x8F);
    lcd_func.write_byte(lcd_io, 0xFF);
    
    
    lcd_func.write_cmd(lcd_io, 0xB6);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    
    lcd_func.write_cmd(lcd_io, 0x36);
    
#if ORIENTATION == 0
    lcd_func.write_byte(lcd_io, 0x18);
#elif ORIENTATION == 1
    lcd_func.write_byte(lcd_io, 0x28);
#elif ORIENTATION == 2
    lcd_func.write_byte(lcd_io, 0x48);
#else
    lcd_func.write_byte(lcd_io, 0x88);
#endif
    
    lcd_func.write_cmd(lcd_io, LCD_CMD_COLOR_MODE);
    lcd_func.write_byte(lcd_io, LCD_CMD_COLOR_MODE_18_BIT);
    
    lcd_func.write_cmd(lcd_io, 0x90);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x08);
    
    lcd_func.write_cmd(lcd_io, 0xBD);
    lcd_func.write_byte(lcd_io, 0x06);
    
    lcd_func.write_cmd(lcd_io, 0xBC);
    lcd_func.write_byte(lcd_io, 0x00);
    
    lcd_func.write_cmd(lcd_io, 0xFF);
    lcd_func.write_byte(lcd_io, 0x60);
    lcd_func.write_byte(lcd_io, 0x01);
    lcd_func.write_byte(lcd_io, 0x04);
    
    lcd_func.write_cmd(lcd_io, 0xC3);
    lcd_func.write_byte(lcd_io, 0x13);
    lcd_func.write_cmd(lcd_io, 0xC4);
    lcd_func.write_byte(lcd_io, 0x13);
    
    lcd_func.write_cmd(lcd_io, 0xC9);
    lcd_func.write_byte(lcd_io, 0x22);
    
    lcd_func.write_cmd(lcd_io, 0xBE);
    lcd_func.write_byte(lcd_io, 0x11);
    
    lcd_func.write_cmd(lcd_io, 0xE1);
    lcd_func.write_byte(lcd_io, 0x10);
    lcd_func.write_byte(lcd_io, 0x0E);
    
    lcd_func.write_cmd(lcd_io, 0xDF);
    lcd_func.write_byte(lcd_io, 0x21);
    lcd_func.write_byte(lcd_io, 0x0c);
    lcd_func.write_byte(lcd_io, 0x02);
    
    lcd_func.write_cmd(lcd_io, 0xF0);
    lcd_func.write_byte(lcd_io, 0x45);
    lcd_func.write_byte(lcd_io, 0x09);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x26);
    lcd_func.write_byte(lcd_io, 0x2A);
    
    lcd_func.write_cmd(lcd_io, 0xF1);
    lcd_func.write_byte(lcd_io, 0x43);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x72);
    lcd_func.write_byte(lcd_io, 0x36);
    lcd_func.write_byte(lcd_io, 0x37);
    lcd_func.write_byte(lcd_io, 0x6F);
    
    lcd_func.write_cmd(lcd_io, 0xF2);
    lcd_func.write_byte(lcd_io, 0x45);
    lcd_func.write_byte(lcd_io, 0x09);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x26);
    lcd_func.write_byte(lcd_io, 0x2A);
    
    lcd_func.write_cmd(lcd_io, 0xF3);
    lcd_func.write_byte(lcd_io, 0x43);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x72);
    lcd_func.write_byte(lcd_io, 0x36);
    lcd_func.write_byte(lcd_io, 0x37);
    lcd_func.write_byte(lcd_io, 0x6F);
    
    lcd_func.write_cmd(lcd_io, 0xED);
    lcd_func.write_byte(lcd_io, 0x1B);
    lcd_func.write_byte(lcd_io, 0x0B);
    
    lcd_func.write_cmd(lcd_io, 0xAE);
    lcd_func.write_byte(lcd_io, 0x77);
    
    lcd_func.write_cmd(lcd_io, 0xCD);
    lcd_func.write_byte(lcd_io, 0x63);
    
    lcd_func.write_cmd(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x07);
    lcd_func.write_byte(lcd_io, 0x07);
    lcd_func.write_byte(lcd_io, 0x04);
    lcd_func.write_byte(lcd_io, 0x0E);
    lcd_func.write_byte(lcd_io, 0x0F);
    lcd_func.write_byte(lcd_io, 0x09);
    lcd_func.write_byte(lcd_io, 0x07);
    lcd_func.write_byte(lcd_io, 0x08);
    lcd_func.write_byte(lcd_io, 0x03);
    
    lcd_func.write_cmd(lcd_io, 0xE8);
    lcd_func.write_byte(lcd_io, 0x34);
    
    lcd_func.write_cmd(lcd_io, 0x62);
    lcd_func.write_byte(lcd_io, 0x18);
    lcd_func.write_byte(lcd_io, 0x0D);
    lcd_func.write_byte(lcd_io, 0x71);
    lcd_func.write_byte(lcd_io, 0xED);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x18);
    lcd_func.write_byte(lcd_io, 0x0F);
    lcd_func.write_byte(lcd_io, 0x71);
    lcd_func.write_byte(lcd_io, 0xEF);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x70);
    
    lcd_func.write_cmd(lcd_io, 0x63);
    lcd_func.write_byte(lcd_io, 0x18);
    lcd_func.write_byte(lcd_io, 0x11);
    lcd_func.write_byte(lcd_io, 0x71);
    lcd_func.write_byte(lcd_io, 0xF1);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x18);
    lcd_func.write_byte(lcd_io, 0x13);
    lcd_func.write_byte(lcd_io, 0x71);
    lcd_func.write_byte(lcd_io, 0xF3);
    lcd_func.write_byte(lcd_io, 0x70);
    lcd_func.write_byte(lcd_io, 0x70);
    
    lcd_func.write_cmd(lcd_io, 0x64);
    lcd_func.write_byte(lcd_io, 0x28);
    lcd_func.write_byte(lcd_io, 0x29);
    lcd_func.write_byte(lcd_io, 0xF1);
    lcd_func.write_byte(lcd_io, 0x01);
    lcd_func.write_byte(lcd_io, 0xF1);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x07);
    
    lcd_func.write_cmd(lcd_io, 0x66);
    lcd_func.write_byte(lcd_io, 0x3C);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0xCD);
    lcd_func.write_byte(lcd_io, 0x67);
    lcd_func.write_byte(lcd_io, 0x45);
    lcd_func.write_byte(lcd_io, 0x45);
    lcd_func.write_byte(lcd_io, 0x10);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    
    lcd_func.write_cmd(lcd_io, 0x67);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x3C);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x01);
    lcd_func.write_byte(lcd_io, 0x54);
    lcd_func.write_byte(lcd_io, 0x10);
    lcd_func.write_byte(lcd_io, 0x32);
    lcd_func.write_byte(lcd_io, 0x98);
    
    lcd_func.write_cmd(lcd_io, 0x74);
    lcd_func.write_byte(lcd_io, 0x10);
    lcd_func.write_byte(lcd_io, 0x85);
    lcd_func.write_byte(lcd_io, 0x80);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x00);
    lcd_func.write_byte(lcd_io, 0x4E);
    lcd_func.write_byte(lcd_io, 0x00);
    
    lcd_func.write_cmd(lcd_io, 0x98);
    lcd_func.write_byte(lcd_io, 0x3e);
    lcd_func.write_byte(lcd_io, 0x07);
    
    lcd_func.write_cmd(lcd_io, 0x35);
    lcd_func.write_cmd(lcd_io, 0x21);
    
    lcd_func.write_cmd(lcd_io, 0x11);
    lcd_func.sleep(120);
    lcd_func.write_cmd(lcd_io, 0x29);
    lcd_func.sleep(20);
}

void lcd_set_frame(const lcd_io_cfg *lcd_io, lcd_frame frame)
{
    uint8_t data[4];

    lcd_func.write_cmd(lcd_io, LCD_CMD_COL_ADDR_SET);
    data[0] = (frame.start.X >> 8) & 0xFF;
    data[1] = frame.start.X & 0xFF;
    data[2] = (frame.end.X >> 8) & 0xFF;
    data[3] = frame.end.X & 0xFF;
    lcd_func.write_data(lcd_io, data, sizeof(data));

    lcd_func.write_cmd(lcd_io, LCD_CMD_ROW_ADDR_SET);
    data[0] = (frame.start.Y >> 8) & 0xFF;
    data[1] = frame.start.Y & 0xFF;
    data[2] = (frame.end.Y >> 8) & 0xFF;
    data[3] = frame.end.Y & 0xFF;
    lcd_func.write_data(lcd_io, data, sizeof(data));
}