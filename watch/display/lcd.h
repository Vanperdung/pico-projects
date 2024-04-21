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

// Command codes:
#define COL_ADDR_SET 0x2A
#define ROW_ADDR_SET 0x2B
#define MEM_WR 0x2C
#define MEM_WR_CONT 0x3C
#define COLOR_MODE 0x3A
#define COLOR_MODE_12_BIT 0x03
#define COLOR_MODE_16_BIT 0x05
#define COLOR_MODE_18_BIT 0x06
#define SLPIN 0x10
#define SLPOUT 0x11


#define SET_LCD_FUNC(blanking_on_func, blanking_off_func, write_cmd_func, \
                    write_data_func, control_reset_func, control_data_cmd_func, \
                    control_chip_select_func) \
{ \
    .blanking_on = blanking_on_func, \
    .blanking_off = blanking_off_func, \
    .write_cmd = write_cmd_func, \
    .write_data = write_data_func, \
    .control_reset = control_reset_func, \
    .control_data_cmd = control_data_cmd_func, \
    .control_chip_select = control_chip_select_func \
} 

typedef unsigned int uint;

typedef struct
{
    uint reset_pin;
    uint dc_pin;
    uint cs_pin;
} lcd_io_cfg;

typedef struct 
{
    void (*blanking_on)(const lcd_io_cfg *config);
    void (*blanking_off)(const lcd_io_cfg *config);
    void (*write_cmd)(const lcd_io_cfg *lcd_io, const lcd_func_cfg *lcd_func, uint cmd);
    void (*write_data)(const lcd_io_cfg *lcd_io, const lcd_func_cfg *lcd_func, uint cmd, size_t len);
    void (*control_reset)(const lcd_io_cfg *lcd_io, bool val);
    void (*control_data_cmd)(const lcd_io_cfg *lcd_io, bool val);
    void (*control_chip_select)(const lcd_io_cfg *lcd_io, bool val);
    // get_framebuffer
    // set_brightness
    // set_contrast
    // get_capabilities
    // set_pixel_format
    // set_orientation
} lcd_func_cfg;


#endif