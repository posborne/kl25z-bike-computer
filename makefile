#
# Makefile using gcc4mbed infrastructure in order to build
# an executable for the kl25z linking against mbed
#
PROJECT         := BikeComputer
DEVICES         := KL25Z
GCC4MBED_DIR    := lib/gcc4mbed
SRC             := src
NO_FLOAT_SCANF  := 1
NO_FLOAT_PRINTF := 1

include $(GCC4MBED_DIR)/build/gcc4mbed.mk
