#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "sw_uart.h"
#include "../devicetree.h"

void hal_uart_init(void)
{
    uart_init(LCD_UART_ID, LCD_UART_BAUDRATE);
    gpio_set_function(LCD_UART_TX, GPIO_FUNC_UART);
}