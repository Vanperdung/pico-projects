add_library(hal hal_lcd.c hal_uart.c)
target_link_libraries(hal pico_stdlib)