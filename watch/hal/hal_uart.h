#ifndef _UART_H_
#define _UART_H_

#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "../devicetree.h"

void hal_uart_init(void);

#endif