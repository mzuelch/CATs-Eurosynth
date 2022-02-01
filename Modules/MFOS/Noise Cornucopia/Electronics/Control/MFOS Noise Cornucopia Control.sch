EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
L Connector_Generic:Conn_01x04 J3
U 1 1 60FB53BB
P 2450 9700
F 0 "J3" H 2368 10017 50  0000 C CNN
F 1 "Signal" H 2368 9926 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2450 9700 50  0001 C CNN
F 3 "~" H 2450 9700 50  0001 C CNN
	1    2450 9700
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 60FC6935
P 2450 10500
F 0 "J2" H 2368 10817 50  0000 C CNN
F 1 "Power" H 2368 10726 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2450 10500 50  0001 C CNN
F 3 "~" H 2450 10500 50  0001 C CNN
	1    2450 10500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2650 10400 2850 10400
Wire Wire Line
	2650 10500 2950 10500
Wire Wire Line
	2650 10600 2750 10600
$Comp
L power:GND #PWR0101
U 1 1 60FD2E54
P 2950 10700
F 0 "#PWR0101" H 2950 10450 50  0001 C CNN
F 1 "GND" H 2955 10527 50  0000 C CNN
F 2 "" H 2950 10700 50  0001 C CNN
F 3 "" H 2950 10700 50  0001 C CNN
	1    2950 10700
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0102
U 1 1 60FD3654
P 2750 10700
F 0 "#PWR0102" H 2750 10800 50  0001 C CNN
F 1 "-12V" H 2765 10873 50  0000 C CNN
F 2 "" H 2750 10700 50  0001 C CNN
F 3 "" H 2750 10700 50  0001 C CNN
	1    2750 10700
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0103
U 1 1 60FD41F0
P 2850 10300
F 0 "#PWR0103" H 2850 10150 50  0001 C CNN
F 1 "+12V" H 2865 10473 50  0000 C CNN
F 2 "" H 2850 10300 50  0001 C CNN
F 3 "" H 2850 10300 50  0001 C CNN
	1    2850 10300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 10700 2750 10600
Wire Wire Line
	2850 10300 2850 10400
Wire Wire Line
	2950 10500 2950 10700
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 60FE3F51
P 950 10050
F 0 "H1" H 1050 10099 50  0001 L CNN
F 1 "MountingHole_Pad" H 1050 10008 50  0001 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_DIN965_Pad" H 950 10050 50  0001 C CNN
F 3 "~" H 950 10050 50  0001 C CNN
	1    950  10050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 60FE4488
P 1150 10050
F 0 "H2" H 1250 10099 50  0001 L CNN
F 1 "MountingHole_Pad" H 1250 10008 50  0001 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_DIN965_Pad" H 1150 10050 50  0001 C CNN
F 3 "~" H 1150 10050 50  0001 C CNN
	1    1150 10050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 60FE46F9
P 1050 10350
F 0 "#PWR0104" H 1050 10100 50  0001 C CNN
F 1 "GND" H 1055 10177 50  0000 C CNN
F 2 "" H 1050 10350 50  0001 C CNN
F 3 "" H 1050 10350 50  0001 C CNN
	1    1050 10350
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  10150 950  10250
Wire Wire Line
	950  10250 1050 10250
Wire Wire Line
	1150 10250 1150 10150
Wire Wire Line
	1050 10250 1050 10350
Connection ~ 1050 10250
Wire Wire Line
	1050 10250 1150 10250
$Comp
L Connector_Generic:Conn_01x04 J6
U 1 1 60FEDA5D
P 1950 9700
F 0 "J6" H 2030 9692 50  0000 L CNN
F 1 "Potis" H 2030 9601 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1950 9700 50  0001 C CNN
F 3 "~" H 1950 9700 50  0001 C CNN
	1    1950 9700
	1    0    0    -1  
$EndComp
Text GLabel 1650 9600 0    50   Input ~ 0
GRNS1
Text GLabel 1650 9700 0    50   Input ~ 0
GRNS2
Text GLabel 1650 9900 0    50   Input ~ 0
GTF2
Text GLabel 1650 9800 0    50   Input ~ 0
GTF1
Wire Wire Line
	1650 9600 1750 9600
Wire Wire Line
	1650 9700 1750 9700
Wire Wire Line
	1650 9800 1750 9800
Wire Wire Line
	1650 9900 1750 9900
$Comp
L Connector_Generic:Conn_01x04 J7
U 1 1 6100C2EE
P 1950 10500
F 0 "J7" H 2030 10492 50  0000 L CNN
F 1 "Jacks" H 2030 10401 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1950 10500 50  0001 C CNN
F 3 "~" H 1950 10500 50  0001 C CNN
	1    1950 10500
	1    0    0    -1  
$EndComp
Text GLabel 1650 10400 0    50   Input ~ 0
GNS
Text GLabel 1650 10500 0    50   Input ~ 0
GHP
Text GLabel 1650 10600 0    50   Input ~ 0
LEDA
Text GLabel 1650 10700 0    50   Input ~ 0
RNGT
Wire Wire Line
	1650 10400 1750 10400
Wire Wire Line
	1650 10500 1750 10500
Wire Wire Line
	1650 10600 1750 10600
Wire Wire Line
	1650 10700 1750 10700
Text GLabel 2750 9600 2    50   Input ~ 0
WNS
Text GLabel 2750 9700 2    50   Input ~ 0
LPNS
Text GLabel 2750 9800 2    50   Input ~ 0
HPNS
Wire Wire Line
	2650 9600 2750 9600
Wire Wire Line
	2650 9700 2750 9700
Wire Wire Line
	2650 9800 2750 9800
$Comp
L Device:R_POT R18
U 1 1 60F7ACC4
P 1500 2650
F 0 "R18" H 1430 2696 50  0000 R CNN
F 1 "B100k" H 1430 2605 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 1500 2650 50  0001 C CNN
F 3 "~" H 1500 2650 50  0001 C CNN
	1    1500 2650
	-1   0    0    -1  
$EndComp
Text GLabel 1600 2900 2    50   Input ~ 0
GRNS2
Text GLabel 1600 2400 2    50   Input ~ 0
GRNS1
Wire Wire Line
	1600 2400 1500 2400
Wire Wire Line
	1500 2400 1500 2500
Wire Wire Line
	1600 2900 1500 2900
Wire Wire Line
	1500 2900 1500 2800
Wire Wire Line
	1500 2900 1250 2900
Wire Wire Line
	1250 2900 1250 2650
Wire Wire Line
	1250 2650 1350 2650
Connection ~ 1500 2900
$Comp
L Device:R_POT R28
U 1 1 60F7D769
P 1500 3350
F 0 "R28" H 1430 3396 50  0000 R CNN
F 1 "B100k" H 1430 3305 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 1500 3350 50  0001 C CNN
F 3 "~" H 1500 3350 50  0001 C CNN
	1    1500 3350
	-1   0    0    -1  
$EndComp
Text GLabel 1600 3600 2    50   Input ~ 0
GTF1
Text GLabel 1600 3100 2    50   Input ~ 0
GTF2
Wire Wire Line
	1600 3100 1500 3100
Wire Wire Line
	1500 3100 1500 3200
Wire Wire Line
	1600 3600 1500 3600
Wire Wire Line
	1500 3600 1500 3500
Wire Wire Line
	1500 3100 1250 3100
Wire Wire Line
	1250 3100 1250 3350
Wire Wire Line
	1250 3350 1350 3350
Connection ~ 1500 3100
$Comp
L Connector:AudioJack2_SwitchT J1
U 1 1 60F801AB
P 3550 2700
F 0 "J1" H 3370 2633 50  0000 R CNN
F 1 "WNS" H 3370 2724 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 2700 50  0001 C CNN
F 3 "~" H 3550 2700 50  0001 C CNN
	1    3550 2700
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack2_SwitchT J4
U 1 1 60F80E1F
P 3550 3150
F 0 "J4" H 3370 3083 50  0000 R CNN
F 1 "LPNS" H 3370 3174 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 3150 50  0001 C CNN
F 3 "~" H 3550 3150 50  0001 C CNN
	1    3550 3150
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack2_SwitchT J5
U 1 1 60F811CA
P 3550 3600
F 0 "J5" H 3370 3533 50  0000 R CNN
F 1 "HPNS" H 3370 3624 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 3600 50  0001 C CNN
F 3 "~" H 3550 3600 50  0001 C CNN
	1    3550 3600
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack2_SwitchT J8
U 1 1 60F8156F
P 3550 4050
F 0 "J8" H 3370 3983 50  0000 R CNN
F 1 "GNS" H 3370 4074 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 4050 50  0001 C CNN
F 3 "~" H 3550 4050 50  0001 C CNN
	1    3550 4050
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack2_SwitchT J9
U 1 1 60F818AB
P 3550 4500
F 0 "J9" H 3370 4433 50  0000 R CNN
F 1 "GHP" H 3370 4524 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 4500 50  0001 C CNN
F 3 "~" H 3550 4500 50  0001 C CNN
	1    3550 4500
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack2_SwitchT J10
U 1 1 60F81CC2
P 3550 4950
F 0 "J10" H 3370 4883 50  0000 R CNN
F 1 "RNGT" H 3370 4974 50  0000 R CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3550 4950 50  0001 C CNN
F 3 "~" H 3550 4950 50  0001 C CNN
	1    3550 4950
	-1   0    0    1   
$EndComp
Text GLabel 3150 2700 0    50   Input ~ 0
WNS
Text GLabel 3150 3150 0    50   Input ~ 0
LPNS
Text GLabel 3150 3600 0    50   Input ~ 0
HPNS
Text GLabel 3150 4050 0    50   Input ~ 0
GNS
Text GLabel 3150 4500 0    50   Input ~ 0
GHP
Text GLabel 3150 4950 0    50   Input ~ 0
RNGT
Wire Wire Line
	3150 2700 3350 2700
Wire Wire Line
	3150 3150 3350 3150
Wire Wire Line
	3150 3600 3350 3600
Wire Wire Line
	3150 4050 3350 4050
Wire Wire Line
	3150 4500 3350 4500
Wire Wire Line
	3150 4950 3350 4950
$Comp
L power:GND #PWR0105
U 1 1 60F860C8
P 3250 5450
F 0 "#PWR0105" H 3250 5200 50  0001 C CNN
F 1 "GND" H 3255 5277 50  0000 C CNN
F 2 "" H 3250 5450 50  0001 C CNN
F 3 "" H 3250 5450 50  0001 C CNN
	1    3250 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2800 3250 2800
Wire Wire Line
	3250 2800 3250 3250
Wire Wire Line
	3350 5050 3250 5050
Connection ~ 3250 5050
Wire Wire Line
	3250 5050 3250 5350
Wire Wire Line
	3350 4600 3250 4600
Connection ~ 3250 4600
Wire Wire Line
	3250 4600 3250 5050
Wire Wire Line
	3350 4150 3250 4150
Connection ~ 3250 4150
Wire Wire Line
	3250 4150 3250 4600
Wire Wire Line
	3350 3700 3250 3700
Connection ~ 3250 3700
Wire Wire Line
	3250 3700 3250 4150
Wire Wire Line
	3350 3250 3250 3250
Connection ~ 3250 3250
Wire Wire Line
	3250 3250 3250 3700
$Comp
L Device:LED D1
U 1 1 60F8B518
P 3000 5350
F 0 "D1" H 2993 5095 50  0000 C CNN
F 1 "LED" H 2993 5186 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 3000 5350 50  0001 C CNN
F 3 "~" H 3000 5350 50  0001 C CNN
	1    3000 5350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3150 5350 3250 5350
Connection ~ 3250 5350
Wire Wire Line
	3250 5350 3250 5450
Text GLabel 2750 5350 0    50   Input ~ 0
LEDA
Wire Wire Line
	2750 5350 2850 5350
$EndSCHEMATC
