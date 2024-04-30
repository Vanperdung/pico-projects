add_library(sw_lcd lcd.c sw_lcd.c)
target_link_libraries(sw_lcd pico_stdlib sw_gpio)