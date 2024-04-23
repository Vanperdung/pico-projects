#include "lcd.h"

lcd_func_cfg lcd_func = {0};
lcd_io_cfg lcd_io = {0};

void lcd_set_func(const lcd_func_cfg *p_lcd_func)
{
    memcpy(&lcd_func, p_lcd_func, sizeof(lcd_func_cfg));
}

void lcd_set_io(const lcd_io_cfg *p_lcd_io)
{
    memcpy(&lcd_io, p_lcd_io, sizeof(lcd_io_cfg));
}

// void lcd_control_reset(bool val)
// {
//     gpio_put(lcd_io->reset_pin, val);
// }

// void lcd_control_data_cmd(bool val)
// {
//     gpio_put(lcd_io->dc_pin, val);
// }

// void lcd_control_chip_select(bool val)
// {
//     gpio_put(lcd_io->cs_pin, val);
// }

void lcd_write_cmd(uint8_t cmd)
{
    lcd_func.control_data_cmd(LCD_OFF);
    lcd_func.control_chip_select(LCD_OFF);
    // TODO spi_tx(&cmd, sizeof(cmd))
    lcd_func.control_chip_select(LCD_ON);
}

void lcd_write_data(uint8_t *data, size_t len)
{
    lcd_func.control_data_cmd(LCD_ON);
    lcd_func.control_chip_select(LCD_OFF);
    // TODO spi_tx(data, len)
    lcd_func.control_chip_select(LCD_ON);
}

void lcd_write_byte(uint8_t val)
{
    lcd_write_data(&val, sizeof(val));
}

void lcd_write(uint8_t *data, size_t len)
{
    lcd_write_cmd(LCD_CMD_MEM_WR);
    lcd_write_data(data, len);
}

void lcd_write_continuos(uint8_t *data, size_t len)
{
    lcd_write_cmd(LCD_CMD_MEM_WR_CONT);
    lcd_write_data(data, len);
}

void lcd_init(void)
{
    lcd_func.control_chip_select(LCD_ON);
    lcd_func.sleep(5);
    lcd_func.control_reset(LCD_OFF);
    lcd_func.sleep(10);
    lcd_func.control_reset(LCD_OFF);
    lcd_func.sleep(120);

    lcd_write_cmd(0xEF);

    lcd_write_cmd(0xEB);
    lcd_write_byte(0x14);

    lcd_write_cmd(0xFE);
    lcd_write_cmd(0xEF);

    lcd_write_cmd(0xEB);
    lcd_write_byte(0x14);

    lcd_write_cmd(0x84);
    lcd_write_byte(0x40);

    lcd_write_cmd(0x85);
    lcd_write_byte(0xFF);

    lcd_write_cmd(0x86);
    lcd_write_byte(0xFF);

    lcd_write_cmd(0x87);
    lcd_write_byte(0xFF);

    lcd_write_cmd(0x88);
    lcd_write_byte(0x0A);

    lcd_write_cmd(0x89);
    lcd_write_byte(0x21);

    lcd_write_cmd(0x8A);
    lcd_write_byte(0x00);

    lcd_write_cmd(0x8B);
    lcd_write_byte(0x80);

    lcd_write_cmd(0x8C);
    lcd_write_byte(0x01);

    lcd_write_cmd(0x8D);
    lcd_write_byte(0x01);

    lcd_write_cmd(0x8E);
    lcd_write_byte(0xFF);

    lcd_write_cmd(0x8F);
    lcd_write_byte(0xFF);

    lcd_write_cmd(0xB6);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);

    lcd_write_cmd(0x36);

#if ORIENTATION == 0
    lcd_write_byte(0x18);
#elif ORIENTATION == 1
    lcd_write_byte(0x28);
#elif ORIENTATION == 2
    lcd_write_byte(0x48);
#else
    lcd_write_byte(0x88);
#endif

    lcd_write_cmd(LCD_CMD_COLOR_MODE);
    lcd_write_byte(LCD_CMD_COLOR_MODE_18_BIT);

    lcd_write_cmd(0x90);
    lcd_write_byte(0x08);
    lcd_write_byte(0x08);
    lcd_write_byte(0x08);
    lcd_write_byte(0x08);

    lcd_write_cmd(0xBD);
    lcd_write_byte(0x06);

    lcd_write_cmd(0xBC);
    lcd_write_byte(0x00);

    lcd_write_cmd(0xFF);
    lcd_write_byte(0x60);
    lcd_write_byte(0x01);
    lcd_write_byte(0x04);

    lcd_write_cmd(0xC3);
    lcd_write_byte(0x13);
    lcd_write_cmd(0xC4);
    lcd_write_byte(0x13);

    lcd_write_cmd(0xC9);
    lcd_write_byte(0x22);

    lcd_write_cmd(0xBE);
    lcd_write_byte(0x11);

    lcd_write_cmd(0xE1);
    lcd_write_byte(0x10);
    lcd_write_byte(0x0E);

    lcd_write_cmd(0xDF);
    lcd_write_byte(0x21);
    lcd_write_byte(0x0c);
    lcd_write_byte(0x02);

    lcd_write_cmd(0xF0);
    lcd_write_byte(0x45);
    lcd_write_byte(0x09);
    lcd_write_byte(0x08);
    lcd_write_byte(0x08);
    lcd_write_byte(0x26);
    lcd_write_byte(0x2A);

    lcd_write_cmd(0xF1);
    lcd_write_byte(0x43);
    lcd_write_byte(0x70);
    lcd_write_byte(0x72);
    lcd_write_byte(0x36);
    lcd_write_byte(0x37);
    lcd_write_byte(0x6F);

    lcd_write_cmd(0xF2);
    lcd_write_byte(0x45);
    lcd_write_byte(0x09);
    lcd_write_byte(0x08);
    lcd_write_byte(0x08);
    lcd_write_byte(0x26);
    lcd_write_byte(0x2A);

    lcd_write_cmd(0xF3);
    lcd_write_byte(0x43);
    lcd_write_byte(0x70);
    lcd_write_byte(0x72);
    lcd_write_byte(0x36);
    lcd_write_byte(0x37);
    lcd_write_byte(0x6F);

    lcd_write_cmd(0xED);
    lcd_write_byte(0x1B);
    lcd_write_byte(0x0B);

    lcd_write_cmd(0xAE);
    lcd_write_byte(0x77);

    lcd_write_cmd(0xCD);
    lcd_write_byte(0x63);

    lcd_write_cmd(0x70);
    lcd_write_byte(0x07);
    lcd_write_byte(0x07);
    lcd_write_byte(0x04);
    lcd_write_byte(0x0E);
    lcd_write_byte(0x0F);
    lcd_write_byte(0x09);
    lcd_write_byte(0x07);
    lcd_write_byte(0x08);
    lcd_write_byte(0x03);

    lcd_write_cmd(0xE8);
    lcd_write_byte(0x34);

    lcd_write_cmd(0x62);
    lcd_write_byte(0x18);
    lcd_write_byte(0x0D);
    lcd_write_byte(0x71);
    lcd_write_byte(0xED);
    lcd_write_byte(0x70);
    lcd_write_byte(0x70);
    lcd_write_byte(0x18);
    lcd_write_byte(0x0F);
    lcd_write_byte(0x71);
    lcd_write_byte(0xEF);
    lcd_write_byte(0x70);
    lcd_write_byte(0x70);

    lcd_write_cmd(0x63);
    lcd_write_byte(0x18);
    lcd_write_byte(0x11);
    lcd_write_byte(0x71);
    lcd_write_byte(0xF1);
    lcd_write_byte(0x70);
    lcd_write_byte(0x70);
    lcd_write_byte(0x18);
    lcd_write_byte(0x13);
    lcd_write_byte(0x71);
    lcd_write_byte(0xF3);
    lcd_write_byte(0x70);
    lcd_write_byte(0x70);

    lcd_write_cmd(0x64);
    lcd_write_byte(0x28);
    lcd_write_byte(0x29);
    lcd_write_byte(0xF1);
    lcd_write_byte(0x01);
    lcd_write_byte(0xF1);
    lcd_write_byte(0x00);
    lcd_write_byte(0x07);

    lcd_write_cmd(0x66);
    lcd_write_byte(0x3C);
    lcd_write_byte(0x00);
    lcd_write_byte(0xCD);
    lcd_write_byte(0x67);
    lcd_write_byte(0x45);
    lcd_write_byte(0x45);
    lcd_write_byte(0x10);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);

    lcd_write_cmd(0x67);
    lcd_write_byte(0x00);
    lcd_write_byte(0x3C);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);
    lcd_write_byte(0x01);
    lcd_write_byte(0x54);
    lcd_write_byte(0x10);
    lcd_write_byte(0x32);
    lcd_write_byte(0x98);

    lcd_write_cmd(0x74);
    lcd_write_byte(0x10);
    lcd_write_byte(0x85);
    lcd_write_byte(0x80);
    lcd_write_byte(0x00);
    lcd_write_byte(0x00);
    lcd_write_byte(0x4E);
    lcd_write_byte(0x00);

    lcd_write_cmd(0x98);
    lcd_write_byte(0x3e);
    lcd_write_byte(0x07);

    lcd_write_cmd(0x35);
    lcd_write_cmd(0x21);

    lcd_write_cmd(0x11);
    lcd_func.sleep(120);
    lcd_write_cmd(0x29);
    lcd_func.sleep(20);
}

void lcd_set_frame(lcd_frame frame)
{
    uint8_t data[4];

    lcd_write_cmd(LCD_CMD_COL_ADDR_SET);
    data[0] = (frame.start.X >> 8) & 0xFF;
    data[1] = frame.start.X & 0xFF;
    data[2] = (frame.end.X >> 8) & 0xFF;
    data[3] = frame.end.X & 0xFF;
    lcd_write_data(data, sizeof(data));

    lcd_write_cmd(LCD_CMD_ROW_ADDR_SET);
    data[0] = (frame.start.Y >> 8) & 0xFF;
    data[1] = frame.start.Y & 0xFF;
    data[2] = (frame.end.Y >> 8) & 0xFF;
    data[3] = frame.end.Y & 0xFF;
    lcd_write_data(data, sizeof(data));
}