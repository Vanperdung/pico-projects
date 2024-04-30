#ifndef _SW_GPIO_H_
#define _SW_GPIO_H_

void sw_gpio_mode_init(uint16_t pin, uint16_t mode);
void sw_gpio_write(uint16_t pin, uint8_t value);
uint8_t sw_gpio_read(uint16_t pin);
void sw_gpio_set_bl(bool value);
void sw_gpio_set_reset(bool value);
void sw_gpio_set_dc(bool value);
void sw_gpio_set_cs(bool value);
#endif