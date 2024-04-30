#ifndef _LCD_H_
#define _LCD_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define LCD_SLPIN 0x10  ///< Enter Sleep Mode
#define LCD_SLPOUT 0x11 ///< Sleep Out
#define LCD_PTLON 0x12  ///< Partial Mode ON
#define LCD_NORON 0x13  ///< Normal Display Mode ON

#define LCD_INVOFF 0x20  ///< Display Inversion OFF
#define LCD_INVON 0x21   ///< Display Inversion ON
#define LCD_DISPOFF 0x28 ///< Display OFF
#define LCD_DISPON 0x29  ///< Display ON

#define LCD_CASET 0x2A ///< Column Address Set
#define LCD_PASET 0x2B ///< Page Address Set
#define LCD_RAMWR 0x2C ///< Memory Write

#define LCD_PTLAR 0x30    ///< Partial Area
#define LCD_VSCRDEF 0x33  ///< Vertical Scrolling Definition
#define LCD_TEOFF 0x34    ///< Tearing effect line off
#define LCD_TEON 0x35     ///< Tearing effect line on
#define LCD_MADCTL 0x36   ///< Memory Access Control
#define LCD_VSCRSADD 0x37 ///< Vertical Scrolling Start Address
#define LCD_PIXFMT 0x3A   ///< COLMOD: Pixel Format Set

#define LCD1_DFUNCTR 0xB6 ///< Display Function Control

#define LCD1_VREG1A 0xC3 ///< Vreg1a voltage control
#define LCD1_VREG1B 0xC4 ///< Vreg1b voltage control
#define LCD1_VREG2A 0xC9 ///< Vreg2a voltage control

#define LCD_RDID1 0xDA ///< Read ID 1
#define LCD_RDID2 0xDB ///< Read ID 2
#define LCD_RDID3 0xDC ///< Read ID 3

#define LCD1_GMCTRP1 0xE0  ///< Positive Gamma Correction
#define LCD1_GMCTRN1 0xE1  ///< Negative Gamma Correction
#define LCD_FRAMERATE 0xE8 ///< Frame rate control

#define LCD_INREGEN2 0xEF ///< Inter register enable 2
#define LCD_GAMMA1 0xF0   ///< Set gamma 1
#define LCD_GAMMA2 0xF1   ///< Set gamma 2
#define LCD_GAMMA3 0xF2   ///< Set gamma 3
#define LCD_GAMMA4 0xF3   ///< Set gamma 4

#define LCD_INREGEN1 0xFE ///< Inter register enable 1

#define MADCTL_MY 0x80  ///< Bottom to top
#define MADCTL_MX 0x40  ///< Right to left
#define MADCTL_MV 0x20  ///< Reverse Mode
#define MADCTL_ML 0x10  ///< LCD refresh Bottom to top
#define MADCTL_RGB 0x00 ///< Red-Green-Blue pixel order
#define MADCTL_BGR 0x08 ///< Blue-Green-Red pixel order
#define MADCTL_MH 0x04  ///< LCD refresh right to left

#define DISPLAY_WIDTH DT_INST_PROP(0, width)
#define DISPLAY_HEIGHT DT_INST_PROP(0, height)

#define LCD_OFF 0
#define LCD_ON 1

#define HORIZONTAL 0
#define VERTICAL 1

#define LCD_HEIGHT 240
#define LCD_WIDTH 240

#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40
#define BRRED 0XFC07
#define GRAY 0X8430
#define DARKBLUE 0X01CF
#define LIGHTBLUE 0X7D7C
#define GRAYBLUE 0X5458
#define LIGHTGREEN 0X841F
#define LGRAY 0XC618
#define LGRAYBLUE 0XA651
#define LBBLUE 0X2B12

// Command codes:
#define LCD_CMD_COL_ADDR_SET 0x2A
#define LCD_CMD_ROW_ADDR_SET 0x2B
#define LCD_CMD_MEM_WR 0x2C
#define LCD_CMD_MEM_WR_CONT 0x3C
#define LCD_CMD_COLOR_MODE 0x3A
#define LCD_CMD_COLOR_MODE_12_BIT 0x03
#define LCD_CMD_COLOR_MODE_16_BIT 0x05
#define LCD_CMD_COLOR_MODE_18_BIT 0x06
#define LCD_CMD_SLPIN 0x10
#define LCD_CMD_SLPOUT 0x11

#define SET_LCD_FUNC(control_blanking_func,                     \
                     control_reset_func, control_data_cmd_func, \
                     control_chip_select_func, sleep_func,      \
                     spi_tx_func, spi_rx_func)                  \
    {                                                           \
        .control_blanking = control_blanking_func,              \
        .control_reset = control_reset_func,                    \
        .control_data_cmd = control_data_cmd_func,              \
        .control_chip_select = control_chip_select_func,        \
        .sleep = sleep_func,                                    \
        .spi_tx = spi_tx_func,                                  \
        .spi_rx = spi_rx_func,                                  \
    }

#define SET_LCD_IO(reset, dc, cs, bl) \
    {                                 \
        .reset_pin = reset,           \
        .dc_pin = dc,                 \
        .cs_pin = cs,                 \
        .bl_pin = bl                  \
    }

typedef unsigned int uint;

typedef struct
{
    uint reset_pin;
    uint dc_pin;
    uint cs_pin;
    uint bl_pin;
} lcd_io_cfg;

typedef struct
{
    uint X;
    uint Y;
} lcd_position;

typedef struct
{
    lcd_position start;
    lcd_position end;
} lcd_frame;

struct lcd_func_cfg; // similar typedef struct lcd_func_cfg { ... } lcd_func_cfg;
typedef struct
{
    void (*control_blanking)(bool val);
    void (*control_reset)(bool val);
    void (*control_data_cmd)(bool val);
    void (*control_chip_select)(bool val);
    void (*sleep)(uint32_t ms);
    void (*spi_tx)(uint8_t *data, uint len);
    void (*spi_rx)(uint8_t *data, uint len);
    // get_framebuffer
    // set_brightness
    // set_contrast
    // get_capabilities
    // set_pixel_format
    // set_orientation
} lcd_func_cfg;

void lcd_set_func(const lcd_func_cfg *p_lcd_func);
void lcd_set_io(const lcd_io_cfg *p_lcd_io);
void lcd_write_cmd(uint8_t cmd);
void lcd_write_data(uint8_t *data, size_t len);
void lcd_write_byte(uint8_t val);
void lcd_write(uint8_t *data, size_t len);
void lcd_write_continuos(uint8_t *data, size_t len);
void lcd_init_reg(void);
void lcd_init(uint8_t scan_dir);
void lcd_set_frame(lcd_frame frame);
void lcd_display_point(uint16_t X, uint16_t Y, uint16_t color);
void lcd_display_partial(lcd_frame frame, uint16_t *image);
void lcd_display_fullscreen(lcd_frame frame, uint16_t *image);
void lcd_clear_screen(lcd_frame frame, uint16_t color);
void lcd_set_attributes(uint8_t scan_dir);
#endif