#ifndef _HAL_TIMER_H_
#define _HAL_TIMER_H_

#include <stdio.h>
#include "pico/stdlib.h"

bool hal_repeating_timer_init(int32_t delay_ms, repeating_timer_callback_t timer_cb, void *user_data, repeating_timer_t *timer);

#endif