add_library(sw_uart sw_uart.c)
target_link_libraries(sw_uart pico_stdlib hardware_uart)