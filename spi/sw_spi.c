#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/dma.h"
#include "sw_spi.h"
#include "../devicetree.h"

uint dma_tx;
dma_channel_config dma_cfg;

__attribute__((weak)) void sw_dma_irq_handler(void)
{
    
}

uint sw_spi_dma_init(uint baudrate)
{
    uint ret;
    ret = spi_init(SPI_ID, baudrate);

    if (ret != baudrate)
    {
        printf("Failed in spi_init\r\n");
        return ret;
    }

    gpio_set_function(LCD_SPI_CLK, GPIO_FUNC_SPI);
    gpio_set_function(LCD_SPI_MOSI, GPIO_FUNC_SPI);

    dma_tx = dma_claim_unused_channel(true);
    dma_cfg = dma_channel_get_default_config(dma_tx);
    channel_config_set_transfer_data_size(&dma_cfg, DMA_SIZE_8); 
    channel_config_set_dreq(&dma_cfg, spi_get_dreq(SPI_ID, true));

    // Init DMA for transmit data from memory to SPI
    dma_channel_set_irq0_enabled(dma_tx, true);
    irq_set_exclusive_handler(DMA_IRQ_0, sw_dma_irq_handler);
    irq_set_enabled(DMA_IRQ_0, true);
    return ret;
}

uint sw_spi_init(uint baudrate)
{
    uint ret;
    ret = spi_init(SPI_ID, baudrate);
    printf("SPI baudrate = %d\r\n", ret);

    gpio_set_function(LCD_SPI_CLK, GPIO_FUNC_SPI);
    gpio_set_function(LCD_SPI_MOSI, GPIO_FUNC_SPI);
    return ret;
}

void sw_spi_write_bytes(uint8_t *data, uint len)
{
    spi_write_blocking(SPI_ID, data, len);
}

void sw_spi_dma_write_byte(const volatile void *read_addr, uint transfer_count, bool trigger)
{
    dma_channel_configure(dma_tx, &dma_cfg, &spi_get_hw(SPI_ID)->dr, read_addr, transfer_count, trigger);
}