EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
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
LIBS:kicad-library-by-simlun
LIBS:i2c-weight-scale-kicad-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "I2C Weight Scale"
Date ""
Rev "0.1.0"
Comp "Simon Lundmark"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X12 P1
U 1 1 547B5E77
P 2100 1850
F 0 "P1" H 2100 2500 50  0000 C CNN
F 1 "4_STRAIN_GAUGES" V 2200 1850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12" H 2100 1850 60  0001 C CNN
F 3 "" H 2100 1850 60  0000 C CNN
	1    2100 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 2400 2650 2400
Wire Wire Line
	2650 2400 2650 1500
Wire Wire Line
	2650 1500 2300 1500
Wire Wire Line
	2300 2100 2500 2100
Wire Wire Line
	2500 2100 2500 1800
Wire Wire Line
	2500 1800 2300 1800
Wire Wire Line
	2300 1600 2500 1600
Wire Wire Line
	2500 1600 2500 1300
Wire Wire Line
	2500 1300 2300 1300
Wire Wire Line
	2300 2200 2400 2200
Wire Wire Line
	2400 2200 2400 1900
Wire Wire Line
	2400 1900 2300 1900
$Comp
L GND #PWR?
U 1 1 547BA03D
P 2900 1800
F 0 "#PWR?" H 2900 1800 30  0001 C CNN
F 1 "GND" H 2900 1730 30  0001 C CNN
F 2 "" H 2900 1800 60  0000 C CNN
F 3 "" H 2900 1800 60  0000 C CNN
	1    2900 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1700 2900 1700
Wire Wire Line
	2900 1700 2900 1800
$Comp
L LM336 D?
U 1 1 547BA8E5
P 3050 2500
F 0 "D?" H 3200 2650 50  0000 C CNN
F 1 "LM336" H 3150 2350 40  0000 C CNN
F 2 "" H 3050 2500 60  0000 C CNN
F 3 "" H 3050 2500 60  0000 C CNN
	1    3050 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 2300 3300 2300
NoConn ~ 2850 2500
$Comp
L GND #PWR?
U 1 1 547BA9CA
P 3050 2900
F 0 "#PWR?" H 3050 2900 30  0001 C CNN
F 1 "GND" H 3050 2830 30  0001 C CNN
F 2 "" H 3050 2900 60  0000 C CNN
F 3 "" H 3050 2900 60  0000 C CNN
	1    3050 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2900 3050 2700
$Comp
L +5V #PWR?
U 1 1 547BAA03
P 3800 1550
F 0 "#PWR?" H 3800 1640 20  0001 C CNN
F 1 "+5V" H 3800 1640 30  0000 C CNN
F 2 "" H 3800 1550 60  0000 C CNN
F 3 "" H 3800 1550 60  0000 C CNN
	1    3800 1550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 547BAA17
P 3800 2050
F 0 "R?" V 3880 2050 40  0000 C CNN
F 1 "1K" V 3807 2051 40  0000 C CNN
F 2 "" V 3730 2050 30  0000 C CNN
F 3 "" H 3800 2050 30  0000 C CNN
	1    3800 2050
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 547BAA9F
P 3550 2300
F 0 "R?" V 3630 2300 40  0000 C CNN
F 1 "1K5" V 3557 2301 40  0000 C CNN
F 2 "" V 3480 2300 30  0000 C CNN
F 3 "" H 3550 2300 30  0000 C CNN
	1    3550 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 1550 3800 1800
Connection ~ 3050 2300
$EndSCHEMATC
