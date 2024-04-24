add_library(hal hal_lcd.c hal_uart.c hal_timer.c)
target_link_libraries(hal pico_stdlib timer)