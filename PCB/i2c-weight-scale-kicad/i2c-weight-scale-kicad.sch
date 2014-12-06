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
P 1750 3200
F 0 "P1" H 1750 3850 50  0000 C CNN
F 1 "4_STRAIN_GAUGES" V 1850 3200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12" H 1750 3200 60  0001 C CNN
F 3 "" H 1750 3200 60  0000 C CNN
	1    1750 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1950 3750 2300 3750
Wire Wire Line
	2300 3750 2300 2850
Wire Wire Line
	2300 2850 1950 2850
Wire Wire Line
	1950 3450 2150 3450
Wire Wire Line
	2150 3450 2150 3150
Wire Wire Line
	2150 3150 1950 3150
Wire Wire Line
	1950 2950 2150 2950
Wire Wire Line
	2150 2950 2150 2650
Wire Wire Line
	2150 2650 1950 2650
Wire Wire Line
	1950 3550 2050 3550
Wire Wire Line
	2050 3550 2050 3250
Wire Wire Line
	2050 3250 1950 3250
$Comp
L GND #PWR01
U 1 1 547BA03D
P 2550 3150
F 0 "#PWR01" H 2550 3150 30  0001 C CNN
F 1 "GND" H 2550 3080 30  0001 C CNN
F 2 "" H 2550 3150 60  0000 C CNN
F 3 "" H 2550 3150 60  0000 C CNN
	1    2550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3050 2550 3050
Wire Wire Line
	2550 3050 2550 3150
$Comp
L LM336 D1
U 1 1 547BA8E5
P 2700 3950
F 0 "D1" H 2850 4100 50  0000 C CNN
F 1 "LM336" H 2800 3800 40  0000 C CNN
F 2 "" H 2700 3950 60  0000 C CNN
F 3 "" H 2700 3950 60  0000 C CNN
	1    2700 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 3650 2950 3650
$Comp
L GND #PWR02
U 1 1 547BA9CA
P 2700 4350
F 0 "#PWR02" H 2700 4350 30  0001 C CNN
F 1 "GND" H 2700 4280 30  0001 C CNN
F 2 "" H 2700 4350 60  0000 C CNN
F 3 "" H 2700 4350 60  0000 C CNN
	1    2700 4350
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 547BAA17
P 3800 3650
F 0 "R2" V 3880 3650 40  0000 C CNN
F 1 "1K" V 3807 3651 40  0000 C CNN
F 2 "" V 3730 3650 30  0000 C CNN
F 3 "" H 3800 3650 30  0000 C CNN
	1    3800 3650
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 547BAA9F
P 3200 3650
F 0 "R1" V 3280 3650 40  0000 C CNN
F 1 "1K5" V 3207 3651 40  0000 C CNN
F 2 "" V 3130 3650 30  0000 C CNN
F 3 "" H 3200 3650 30  0000 C CNN
	1    3200 3650
	0    1    1    0   
$EndComp
Connection ~ 2700 3650
Wire Wire Line
	2700 4150 2700 4350
Wire Wire Line
	2700 3750 2700 3650
$Comp
L INA126 U1
U 1 1 5480C719
P 4850 3100
F 0 "U1" H 4850 2900 60  0000 C CNN
F 1 "INA126" H 4850 3300 60  0000 C CNN
F 2 "" H 4900 3100 60  0000 C CNN
F 3 "" H 4900 3100 60  0000 C CNN
	1    4850 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3650 3550 3650
$Comp
L GND #PWR03
U 1 1 5480CA2A
P 4850 3850
F 0 "#PWR03" H 4850 3850 30  0001 C CNN
F 1 "GND" H 4850 3780 30  0001 C CNN
F 2 "" H 4850 3850 60  0000 C CNN
F 3 "" H 4850 3850 60  0000 C CNN
	1    4850 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3700 4850 3850
$Comp
L R R3
U 1 1 5480CF0C
P 4050 3100
F 0 "R3" V 4130 3100 40  0000 C CNN
F 1 "82" V 4057 3101 40  0000 C CNN
F 2 "" V 3980 3100 30  0000 C CNN
F 3 "" H 4050 3100 30  0000 C CNN
	1    4050 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2850 4150 2850
Wire Wire Line
	4150 2850 4150 2900
Wire Wire Line
	4150 2900 4250 2900
Wire Wire Line
	4050 3350 4150 3350
Wire Wire Line
	4150 3350 4150 3250
Wire Wire Line
	4150 3250 4250 3250
Wire Wire Line
	1950 3350 3950 3350
Wire Wire Line
	3950 3350 3950 3400
Wire Wire Line
	3950 3400 4250 3400
Wire Wire Line
	1950 2750 4250 2750
$Comp
L R R4
U 1 1 5480CFE5
P 5600 3100
F 0 "R4" V 5680 3100 40  0000 C CNN
F 1 "1K" V 5607 3101 40  0000 C CNN
F 2 "" V 5530 3100 30  0000 C CNN
F 3 "" H 5600 3100 30  0000 C CNN
	1    5600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2850 5850 2850
Wire Wire Line
	5600 3350 5450 3350
Wire Wire Line
	5450 3350 5450 3300
NoConn ~ 2500 3950
$Comp
L PIC12F1822 U2
U 1 1 5480DD29
P 7450 3100
F 0 "U2" H 7450 2800 39  0000 C CNN
F 1 "PIC12F1822" H 7450 3500 39  0000 C CNN
F 2 "" H 7450 3100 60  0000 C CNN
F 3 "" H 7450 3100 60  0000 C CNN
	1    7450 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5480E276
P 5600 3850
F 0 "#PWR04" H 5600 3850 30  0001 C CNN
F 1 "GND" H 5600 3780 30  0001 C CNN
F 2 "" H 5600 3850 60  0000 C CNN
F 3 "" H 5600 3850 60  0000 C CNN
	1    5600 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3350 5600 3850
Wire Wire Line
	6900 3200 5850 3200
Wire Wire Line
	5850 3200 5850 2850
Connection ~ 5600 2850
NoConn ~ 6900 3300
NoConn ~ 6900 2800
$Comp
L R R5
U 1 1 5480FBAB
P 6700 3700
F 0 "R5" V 6780 3700 40  0000 C CNN
F 1 "10K" V 6707 3701 40  0000 C CNN
F 2 "" V 6630 3700 30  0000 C CNN
F 3 "" H 6700 3700 30  0000 C CNN
	1    6700 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3450 6700 3100
Wire Wire Line
	6700 3100 6900 3100
$Comp
L VDD #PWR05
U 1 1 5482FF68
P 4150 3650
F 0 "#PWR05" H 4150 3750 30  0001 C CNN
F 1 "VDD" H 4150 3760 30  0000 C CNN
F 2 "" H 4150 3650 60  0000 C CNN
F 3 "" H 4150 3650 60  0000 C CNN
	1    4150 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 3650 4150 3650
$Comp
L VDD #PWR06
U 1 1 54830066
P 4850 2350
F 0 "#PWR06" H 4850 2450 30  0001 C CNN
F 1 "VDD" H 4850 2460 30  0000 C CNN
F 2 "" H 4850 2350 60  0000 C CNN
F 3 "" H 4850 2350 60  0000 C CNN
	1    4850 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2350 4850 2450
$Comp
L VDD #PWR07
U 1 1 5483013A
P 8100 2700
F 0 "#PWR07" H 8100 2800 30  0001 C CNN
F 1 "VDD" H 8100 2810 30  0000 C CNN
F 2 "" H 8100 2700 60  0000 C CNN
F 3 "" H 8100 2700 60  0000 C CNN
	1    8100 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2700 8100 2800
Wire Wire Line
	8100 2800 8000 2800
$Comp
L GND #PWR08
U 1 1 548301EC
P 8100 3400
F 0 "#PWR08" H 8100 3400 30  0001 C CNN
F 1 "GND" H 8100 3330 30  0001 C CNN
F 2 "" H 8100 3400 60  0000 C CNN
F 3 "" H 8100 3400 60  0000 C CNN
	1    8100 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3400 8100 3300
Wire Wire Line
	8100 3300 8000 3300
$Comp
L VDD #PWR09
U 1 1 54830309
P 6700 4100
F 0 "#PWR09" H 6700 4200 30  0001 C CNN
F 1 "VDD" H 6700 4210 30  0000 C CNN
F 2 "" H 6700 4100 60  0000 C CNN
F 3 "" H 6700 4100 60  0000 C CNN
	1    6700 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6700 4100 6700 3950
$Comp
L I2C_RJ14 J1
U 1 1 5483054C
P 6100 2050
F 0 "J1" H 6600 2850 60  0000 C CNN
F 1 "I2C_RJ14" H 6250 2850 60  0000 C CNN
F 2 "" H 7500 2450 60  0000 C CNN
F 3 "" H 7500 2450 60  0000 C CNN
	1    6100 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 548305D9
P 6500 2400
F 0 "#PWR010" H 6500 2400 30  0001 C CNN
F 1 "GND" H 6500 2330 30  0001 C CNN
F 2 "" H 6500 2400 60  0000 C CNN
F 3 "" H 6500 2400 60  0000 C CNN
	1    6500 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2400 6500 2200
$Comp
L VDD #PWR011
U 1 1 54830627
P 6650 2350
F 0 "#PWR011" H 6650 2450 30  0001 C CNN
F 1 "VDD" H 6650 2460 30  0000 C CNN
F 2 "" H 6650 2350 60  0000 C CNN
F 3 "" H 6650 2350 60  0000 C CNN
	1    6650 2350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6650 2350 6650 2200
Wire Wire Line
	6900 2900 6200 2900
Wire Wire Line
	6200 2900 6200 2200
Wire Wire Line
	6350 2200 6350 3000
Wire Wire Line
	6350 3000 6900 3000
$EndSCHEMATC
