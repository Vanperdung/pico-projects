#include <stdio.h>
#include "pico/stdlib.h"
#include "../timer/sw_timer.h"

bool hal_repeating_timer_init(int32_t delay_ms, repeating_timer_callback_t timer_cb, void *user_data, repeating_timer_t *timer)
{  
    return repeating_timer_init(delay_ms, timer_cb, user_data, timer);
}