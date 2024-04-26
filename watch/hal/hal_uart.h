#ifndef _UART_H_
#define _UART_H_

#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"

#define UART_ID uart0
#define BAUD_RATE 912000

#define UART_TX_PIN 16
#define UART_RX_PIN 17

void hal_uart_init(void);

#endif