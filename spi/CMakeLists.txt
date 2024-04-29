add_library(sw_spi sw_spi.c)
target_link_libraries(sw_spi pico_stdlib hardware_spi hardware_dma)