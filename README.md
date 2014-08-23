kl25z-bike-computer
===================

Code for hobby project of building a bike computer around the
Freescale FRDM-KL25z board.

Note that parts of this code are taken from the bare-metal-arm project
which is also licensed as MIT.  That project can be found at
https://github.com/payne92/bare-metal-arm

Setup
-----

Running on Ubuntu 14.04

    $ sudo apt-get install gcc-arm-none-eabi
    $ mkdir build
    $ cd build
    $ cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/frdm-kl25z-gcc.cmake
    $ make

This will generate a .bin file build/bike-computer.bin.  This file can
be uploaded to the device via the USB file device made available when
running the proper OpenSDA firmware.  See documentation on mbed.
