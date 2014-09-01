kl25z-bike-computer
===================

Code for hobby project of building a bike computer around the
Freescale FRDM-KL25z board.  The mbed library and gcc4mbed
projects are utilized to ease this development.

Setup
-----

First, install an appropriate cross-compiler

    $ sudo apt-get install gcc-arm-none-eabi

Then, we need to build the mbed libraries and the application.  The
details should be handled by gcc4mbed.

    $ make

This will generate a .bin file KL25Z/BikeComputer.bin.  This file can
be uploaded to the device via the USB file device made available when
running the proper OpenSDA firmware.  See documentation on mbed.

