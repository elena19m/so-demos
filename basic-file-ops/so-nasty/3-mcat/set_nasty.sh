#!/bin/bash

##
# SO, 2017
# Lab #2, Operatii I/O simple
#


cd ../nasty
sudo rmmod nasty.ko

make clean; make

sudo insmod nasty.ko
# wait until the device is initialized
sleep 1
sudo chmod 666 /dev/nasty
