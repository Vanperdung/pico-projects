#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"
#include "sw_clock.h"

void sw_measure_freqs(void)
{
	uint f_pll_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_PLL_SYS_CLKSRC_PRIMARY);
	uint f_pll_usb = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_PLL_USB_CLKSRC_PRIMARY);
	uint f_rosc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_ROSC_CLKSRC);
	uint f_clk_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS);
	uint f_clk_peri = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_PERI);
	uint f_clk_usb = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_USB);
	uint f_clk_adc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_ADC);
	uint f_clk_rtc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_RTC);

	printf("pll_sys  = %dkHz\n", f_pll_sys);
	printf("pll_usb  = %dkHz\n", f_pll_usb);
	printf("rosc     = %dkHz\n", f_rosc);
	printf("clk_sys  = %dkHz\n", f_clk_sys);
	printf("clk_peri = %dkHz\n", f_clk_peri);
	printf("clk_usb  = %dkHz\n", f_clk_usb);
	printf("clk_adc  = %dkHz\n", f_clk_adc);
	printf("clk_rtc  = %dkHz\n", f_clk_rtc);

	// Can't measure clk_ref / xosc as it is the ref
}

bool sw_set_sys_clock(void)
{
	bool ret = false;

	ret = set_sys_clock_khz(PLL_SYS_KHZ, true);
	if (ret == false)
	{
		// TODO: print error here
		return ret;
	}

	ret = clock_configure(clk_peri, 0, CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, PLL_SYS_KHZ * 1000, PLL_SYS_KHZ * 1000);
	if (ret == false)
	{
		// TODO: print error here
		return ret;
	}
	return true;
}
