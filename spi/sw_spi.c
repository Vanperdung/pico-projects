#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/dma.h"
#include "sw_spi.h"
#include "../devicetree.h"

uint sw_spi_init(uint baudrate)
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

    
}

