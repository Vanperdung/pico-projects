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

    return ret;
}
