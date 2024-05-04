#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "../timer/sw_timer.h"
#include "../lcd/sw_lcd.h"
#include "../lvgl/lvgl.h"
#include "../spi/sw_spi.h"
#include "hal_common.h"

static struct repeating_timer lvgl_timer;
extern uint dma_tx;
extern dma_channel_config dma_cfg;
uint16_t *draw_buf1 = NULL;
uint16_t *draw_buf2 = NULL;
static lv_display_t *disp = NULL;

/*
    Refresh image by transferring the color data to the SPI bus by DMA
*/
void hal_display_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    lcd_frame frame = {{area->x1, area->y1}, {area->x2, area->y2}};

    sw_lcd_set_screen(frame);
    sw_spi_dma_write_byte(px_map, ((area->x2 + 1 - area->x1) * (area->y2 + 1 - area->y1)) * 2, true);
}

void sw_dma_irq_handler(void)
{
    if (dma_channel_get_irq0_status(dma_tx)) 
    {
        dma_channel_acknowledge_irq0(dma_tx);    
        lv_display_flush_ready(disp);
    }
}

static bool hal_repeating_lvgl_timer_callback(struct repeating_timer *timer)
{
    lv_tick_inc(5);
    return true;
}

void hal_lvgl_init(void)
{
    draw_buf1 = (uint16_t *)malloc(LCD_HEIGHT * LCD_WIDTH * DRAW_BUFFER_RATIO);
#if defined(USE_SECOND_DRAW_BUFFER)
    draw_buf2 = (uint16_t *)malloc(LCD_HEIGHT * LCD_WIDTH * DRAW_BUFFER_RATIO);
#endif
    // Init timer for LVGL
    sw_repeating_timer_init(-5, hal_repeating_lvgl_timer_callback, NULL, &lvgl_timer);
    
    // Init LVGL core
    lv_init();

    // Init LVGL display
    disp = lv_display_create(LCD_WIDTH, LCD_HEIGHT);
    lv_display_set_flush_cb(disp, hal_display_flush_cb);
    lv_display_set_buffers(disp, draw_buf1, draw_buf2, sizeof(draw_buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
}

void hal_widget_init(void)
{
    
}