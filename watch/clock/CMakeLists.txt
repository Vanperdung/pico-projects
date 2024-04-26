add_library(clock sw_clock.c)
target_link_libraries(clock pico_stdlib hardware_clocks)
