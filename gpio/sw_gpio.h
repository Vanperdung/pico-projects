#ifndef _SW_GPIO_H_
#define _SW_GPIO_H_

void sw_gpio_mode_init(uint16_t pin, uint16_t mode);
void sw_gpio_write(uint16_t pin, uint8_t value);
uint8_t sw_gpio_read(uint16_t pin);

#endif