#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"

#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 16
#define UART_RX_PIN 17

int main(void)
{
	uart_init(UART_ID, BAUD_RATE);
	gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
	while (1)
	{
		// Send out a character without any conversions
		uart_putc_raw(UART_ID, 'A');

		// Send out a character but do CR/LF conversions
		uart_putc(UART_ID, 'B');

		// Send out a string, with CR/LF conversions
		uart_puts(UART_ID, " Hello, UART!\n");
		sleep_ms(1000);
	}
	return 0;
}
