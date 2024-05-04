#ifndef _SW_SPI_H_
#define _SW_SPI_H_

#include <stdio.h>

typedef unsigned int uint;

void sw_dma_irq_handler(void);
uint sw_spi_dma_init(uint baudrate);
uint sw_spi_init(uint baudrate);
void sw_spi_write_bytes(uint8_t *data, uint len);
void sw_spi_dma_write_byte(const volatile void *read_addr, uint transfer_count, bool trigger);
#endif
