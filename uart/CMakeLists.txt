add_library(sw_uart sw_timer.c)
target_link_libraries(sw_uart pico_stdlib hardware_uart)