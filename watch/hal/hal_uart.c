#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "hal_uart.h"

void hal_uart_init(void)
{
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
}

