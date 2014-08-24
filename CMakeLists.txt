project(BIKE-COMPUTER)
cmake_minimum_required(VERSION 2.8)

SET( CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/lib/bare-metal-arm/mkl25z4.ld" )

#
# Helper function for making .bin files for the target (mbed)
#
function(make_mbed_firmware INPUT)
  add_custom_command(TARGET ${INPUT}
    COMMAND arm-none-eabi-objcopy -O binary ${INPUT} ${INPUT}.bin
    COMMENT "objcopying to make mbed compatible firmware")
  SET_DIRECTORY_PROPERTIES(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${INPUT}.bin)
endfunction(make_mbed_firmware)

#
# Create a library for and include files from the bare-metal-arm
# project which is from the git submodule at lib/bare-metal-arm
#
SET(BMA_DIR lib/bare-metal-arm)
include_directories(${BMA_DIR})
add_library(frdm-bare-metal STATIC
  ${BMA_DIR}/accel.c
  ${BMA_DIR}/delay.c
  ${BMA_DIR}/ring.c
  ${BMA_DIR}/_startup.c
  ${BMA_DIR}/syscalls.c
  ${BMA_DIR}/touch.c
  ${BMA_DIR}/uart.c
  ${BMA_DIR}/usb.c
)

#
# Demo App from bare-metal-arm
#
add_executable( frdm-bare-metal-demo
  ${BMA_DIR}/demo.c
  ${BMA_DIR}/tests.c )
target_link_libraries( frdm-bare-metal-demo frdm-bare-metal )


#
# Bike Computer
#
add_executable( bike-computer
  src/bikecomputer.c
  ${BMA_DIR}/tests.c
)
target_link_libraries( bike-computer frdm-bare-metal )


#
# Make .bin files to place on target
#
make_mbed_firmware( frdm-bare-metal-demo )
make_mbed_firmware( bike-computer )
