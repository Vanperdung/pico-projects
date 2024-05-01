#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
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

void lcd_write_cmd(uint8_t cmd)
{
    lcd_func.control_data_cmd(LCD_OFF);
    lcd_func.control_chip_select(LCD_OFF);
    lcd_func.spi_tx(&cmd, 1);
    lcd_func.control_chip_select(LCD_ON);
}

void lcd_write_data(uint8_t *data, size_t len)
{
    lcd_func.control_data_cmd(LCD_ON);
    lcd_func.control_chip_select(LCD_OFF);
    lcd_func.spi_tx(data, len);
    lcd_func.control_chip_select(LCD_ON);
}

void lcd_write_byte(uint8_t val)
{
    lcd_write_data(&val, 1);
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

void lcd_reset(void)
{
    lcd_func.control_reset(LCD_ON);
    lcd_func.sleep(100);
    lcd_func.control_reset(LCD_OFF);
    lcd_func.sleep(100);
    lcd_func.control_reset(LCD_ON);
    lcd_func.control_chip_select(LCD_OFF);
    lcd_func.sleep(100);
}

void lcd_init_reg(void)
{
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
    lcd_write_byte(0x20);

    lcd_write_cmd(0x36);
    lcd_write_byte(0x08);

    lcd_write_cmd(LCD_CMD_COLOR_MODE);
    lcd_write_byte(LCD_CMD_COLOR_MODE_16_BIT);

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

    lcd_write_cmd(LCD_CMD_MEM_WR);
    lcd_func.control_data_cmd(LCD_ON);
}

/*
    Set resolution and scaning method of the screen
*/
void lcd_set_attributes(uint8_t scan_dir)
{
    uint8_t mem_access_reg = 0x08;

    if (scan_dir == HORIZONTAL)
    {
        mem_access_reg = 0xc8;
    }
    else 
    {
        mem_access_reg = 0x68;
    }

    lcd_write_cmd(0x36);
    lcd_write_byte(mem_access_reg);
}

void lcd_clear_screen(lcd_frame frame, uint16_t color)
{
    uint16_t row_pixels[LCD_WIDTH] = {0};

    color = ((color << 8) & 0xFF00) | (color >> 8);

    for (uint32_t j = 0; j < LCD_WIDTH; j++)
    {
        row_pixels[j] = color;
    }

    lcd_set_frame(frame);

    for (uint32_t j = 0; j < LCD_HEIGHT; j++)
    {
        lcd_write_data((uint8_t *)row_pixels, LCD_WIDTH * 2);
    }
}

void lcd_display_fullscreen(lcd_frame frame, uint16_t *image)
{
    lcd_set_frame(frame);
    for (uint32_t j = 0; j < LCD_HEIGHT; j++) 
    {
        lcd_write_data((uint8_t *)&image[j * LCD_WIDTH], LCD_WIDTH * 2);
    }
}

void lcd_display_partial(lcd_frame frame, uint16_t *image)
{
    uint32_t addr;

    lcd_set_frame(frame);
    for (uint32_t j = frame.start.Y; j < frame.end.Y; j++) 
    {
        addr = frame.start.X + j * LCD_WIDTH;
        lcd_write_data((uint8_t *)&image[addr], (frame.end.X - frame.start.X) * 2);
    }
}

void lcd_display_point(uint16_t X, uint16_t Y, uint16_t color)
{
    lcd_frame frame = {{X, Y}, {X, Y}};

    lcd_set_frame(frame);
    lcd_write_data((uint8_t *)&color, sizeof(color));
}

void lcd_init(uint8_t scan_dir)
{
    lcd_reset();
    lcd_set_attributes(scan_dir);
    lcd_init_reg();
}