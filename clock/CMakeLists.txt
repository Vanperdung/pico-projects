add_library(sw_clock sw_clock.c)
target_link_libraries(sw_clock pico_stdlib hardware_clocks)
