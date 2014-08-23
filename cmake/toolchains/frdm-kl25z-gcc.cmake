INCLUDE(CMakeForceCompiler)

SET( CMAKE_SYSTEM_NAME Generic )
SET( CMAKE_SYSTEM_VERSION 1 )

# specify cross compiler
CMAKE_FORCE_C_COMPILER( arm-none-eabi-gcc GNU )
CMAKE_FORCE_CXX_COMPILER( arm-none-eabi-g++ GNU )

SET(COMMON_FLAGS "-mcpu=cortex-m0 -ffunction-sections -fdata-sections -Wall -fmessage-length=0 -mthumb -mfloat-abi=soft -Os -g3 -gdwarf-2 -gstrict-dwarf")
SET(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -std=gnu++0x")
SET(CMAKE_C_FLAGS "${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS "-Wl,-gc-sections")
