EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC18F14K50-E/SS MCU1
U 1 1 5A935CB6
P 4850 2950
F 0 "MCU1" H 3550 3650 50  0000 C CNN
F 1 "PIC18F14K50-E/SS" H 5750 2250 50  0000 C CNN
F 2 "Housings_SSOP:SSOP-20_5.3x7.2mm_Pitch0.65mm" H 4850 2950 50  0001 C CIN
F 3 "" H 4850 3050 50  0001 C CNN
	1    4850 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A935D65
P 4850 3850
F 0 "#PWR01" H 4850 3600 50  0001 C CNN
F 1 "GND" H 4850 3700 50  0000 C CNN
F 2 "" H 4850 3850 50  0001 C CNN
F 3 "" H 4850 3850 50  0001 C CNN
	1    4850 3850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 5A935E0A
P 4850 2100
F 0 "#PWR02" H 4850 1950 50  0001 C CNN
F 1 "+5V" H 4850 2240 50  0000 C CNN
F 2 "" H 4850 2100 50  0001 C CNN
F 3 "" H 4850 2100 50  0001 C CNN
	1    4850 2100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 5A935E21
P 2600 2650
F 0 "#PWR03" H 2600 2500 50  0001 C CNN
F 1 "+5V" H 2600 2790 50  0000 C CNN
F 2 "" H 2600 2650 50  0001 C CNN
F 3 "" H 2600 2650 50  0001 C CNN
	1    2600 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 2150 4850 2100
Wire Wire Line
	4850 3850 4850 3750
$Comp
L R 10k1
U 1 1 5A93621A
P 3000 2650
F 0 "10k1" V 3080 2650 50  0000 C CNN
F 1 "R" V 3000 2650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0922_L20.0mm_D9.0mm_P25.40mm_Horizontal" V 2930 2650 50  0001 C CNN
F 3 "" H 3000 2650 50  0001 C CNN
	1    3000 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 2650 3350 2650
Wire Wire Line
	2850 2650 2600 2650
$EndSCHEMATC
