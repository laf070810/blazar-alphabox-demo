# blazar_alphabox_demo
This keil project features a blazar lib for convenient access of peripherals on the Blazar Alpha-Box board. 

## Libs Used in This Project
1. NXP's MCUXpresso SDK with FreeRTOS
2. uGfx, an open-source GUI lib for MCU

## Folder Structure
[blazar/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/blazar), [shell/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/shell) and [source/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/source) contain customized codes, while others are libs used in this project. 

[blazar/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/blazar) is the blazar lib featured in this project. 

[shell/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/shell) contains codes of shell commands developed for debugging. 

[source/](https://github.com/laf070810/blazar_alphabox_demo/tree/master/source) contains config files of the libs, main.c with the main function inside and main.py for ESP8266 with MicroPython firmware to allow the MCU to establish network connections. 

## Usage of This Project
Clone this project and write your code in it. When you use the blazar lib, just read the API descriptions in the head files and use them directly after calling corresponding init functions. 

## TODO
1. Design and implement more APIs for the blazar lib. 
2. Detach the blazar lib from this specific board and add porting layer to make the lib more universal. 
