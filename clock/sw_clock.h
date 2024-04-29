#ifndef _SW_CLOCK_H_
#define _SW_CLOCK_H_

#define PLL_SYS_KHZ (270 * 1000)

void sw_measure_freqs(void);
bool sw_set_sys_clock(void);

#endif
