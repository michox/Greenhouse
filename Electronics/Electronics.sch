EESchema Schematic File Version 4
EELAYER 30 0
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
L Electronics-rescue:SW_DIP_x01-Switch SW2
U 1 1 6037A0B2
P 7700 1600
F 0 "SW2" H 7700 1867 50  0000 C CNN
F 1 "WaterAvailable" H 7700 1776 50  0000 C CNN
F 2 "" H 7700 1600 50  0001 C CNN
F 3 "~" H 7700 1600 50  0001 C CNN
	1    7700 1600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:SW_DIP_x01-Switch SW4
U 1 1 6037B72A
P 7700 2600
F 0 "SW4" H 7700 2867 50  0000 C CNN
F 1 "ManualMode" H 7700 2776 50  0000 C CNN
F 2 "" H 7700 2600 50  0001 C CNN
F 3 "~" H 7700 2600 50  0001 C CNN
	1    7700 2600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:Fan-Motor M2
U 1 1 603837FE
P 7350 4250
F 0 "M2" H 7508 4346 50  0000 L CNN
F 1 "Fan" H 7508 4255 50  0000 L CNN
F 2 "" H 7350 4260 50  0001 C CNN
F 3 "~" H 7350 4260 50  0001 C CNN
	1    7350 4250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:Heater-Device R10
U 1 1 603845E1
P 9500 4150
F 0 "R10" H 9570 4196 50  0000 L CNN
F 1 "Heater" H 9570 4105 50  0000 L CNN
F 2 "" V 9430 4150 50  0001 C CNN
F 3 "~" H 9500 4150 50  0001 C CNN
	1    9500 4150
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:Motor_DC-Motor M3
U 1 1 603855E2
P 8450 4200
F 0 "M3" H 8608 4196 50  0000 L CNN
F 1 "Pump" H 8608 4105 50  0000 L CNN
F 2 "" H 8450 4110 50  0001 C CNN
F 3 "~" H 8450 4110 50  0001 C CNN
	1    8450 4200
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q2
U 1 1 60387FE8
P 7250 3750
F 0 "Q2" H 7454 3796 50  0000 L CNN
F 1 "IRF3708" H 7454 3705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7500 3675 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 7250 3750 50  0001 L CNN
	1    7250 3750
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q4
U 1 1 6038FA6E
P 8350 3800
F 0 "Q4" H 8554 3846 50  0000 L CNN
F 1 "IRF3708" H 8554 3755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8600 3725 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 8350 3800 50  0001 L CNN
	1    8350 3800
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R4
U 1 1 6039C8FC
P 7400 1750
F 0 "R4" H 7470 1796 50  0000 L CNN
F 1 "R" H 7470 1705 50  0000 L CNN
F 2 "" V 7330 1750 50  0001 C CNN
F 3 "~" H 7400 1750 50  0001 C CNN
	1    7400 1750
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R7
U 1 1 6039D6D3
P 8150 1600
F 0 "R7" V 7943 1600 50  0000 C CNN
F 1 "R" V 8034 1600 50  0000 C CNN
F 2 "" V 8080 1600 50  0001 C CNN
F 3 "~" H 8150 1600 50  0001 C CNN
	1    8150 1600
	0    1    1    0   
$EndComp
$Comp
L Electronics-rescue:R-Device R5
U 1 1 6039E986
P 7400 2250
F 0 "R5" H 7470 2296 50  0000 L CNN
F 1 "R" H 7470 2205 50  0000 L CNN
F 2 "" V 7330 2250 50  0001 C CNN
F 3 "~" H 7400 2250 50  0001 C CNN
	1    7400 2250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R8
U 1 1 6039F1FE
P 8150 2100
F 0 "R8" V 7943 2100 50  0000 C CNN
F 1 "R" V 8034 2100 50  0000 C CNN
F 2 "" V 8080 2100 50  0001 C CNN
F 3 "~" H 8150 2100 50  0001 C CNN
	1    8150 2100
	0    1    1    0   
$EndComp
$Comp
L Electronics-rescue:R-Device R6
U 1 1 6039FC18
P 7400 2750
F 0 "R6" H 7470 2796 50  0000 L CNN
F 1 "R" H 7470 2705 50  0000 L CNN
F 2 "" V 7330 2750 50  0001 C CNN
F 3 "~" H 7400 2750 50  0001 C CNN
	1    7400 2750
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R9
U 1 1 603A07A5
P 8150 2600
F 0 "R9" V 7943 2600 50  0000 C CNN
F 1 "R" V 8034 2600 50  0000 C CNN
F 2 "" V 8080 2600 50  0001 C CNN
F 3 "~" H 8150 2600 50  0001 C CNN
	1    8150 2600
	0    1    1    0   
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR040
U 1 1 603A66A8
P 8300 1600
F 0 "#PWR040" H 8300 1450 50  0001 C CNN
F 1 "+3.3V" H 8315 1773 50  0000 C CNN
F 2 "" H 8300 1600 50  0001 C CNN
F 3 "" H 8300 1600 50  0001 C CNN
	1    8300 1600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR041
U 1 1 603A740F
P 8300 2100
F 0 "#PWR041" H 8300 1950 50  0001 C CNN
F 1 "+3.3V" H 8315 2273 50  0000 C CNN
F 2 "" H 8300 2100 50  0001 C CNN
F 3 "" H 8300 2100 50  0001 C CNN
	1    8300 2100
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR042
U 1 1 603A7ABF
P 8300 2600
F 0 "#PWR042" H 8300 2450 50  0001 C CNN
F 1 "+3.3V" H 8315 2773 50  0000 C CNN
F 2 "" H 8300 2600 50  0001 C CNN
F 3 "" H 8300 2600 50  0001 C CNN
	1    8300 2600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR037
U 1 1 603A81B1
P 7400 2900
F 0 "#PWR037" H 7400 2650 50  0001 C CNN
F 1 "GND" H 7405 2727 50  0000 C CNN
F 2 "" H 7400 2900 50  0001 C CNN
F 3 "" H 7400 2900 50  0001 C CNN
	1    7400 2900
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR036
U 1 1 603A8AF1
P 7400 2400
F 0 "#PWR036" H 7400 2150 50  0001 C CNN
F 1 "GND" H 7405 2227 50  0000 C CNN
F 2 "" H 7400 2400 50  0001 C CNN
F 3 "" H 7400 2400 50  0001 C CNN
	1    7400 2400
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR035
U 1 1 603A91B9
P 7400 1900
F 0 "#PWR035" H 7400 1650 50  0001 C CNN
F 1 "GND" H 7405 1727 50  0000 C CNN
F 2 "" H 7400 1900 50  0001 C CNN
F 3 "" H 7400 1900 50  0001 C CNN
	1    7400 1900
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:SW_DIP_x01-Switch SW3
U 1 1 60378F25
P 7700 2100
F 0 "SW3" H 7700 2367 50  0000 C CNN
F 1 "WaterLow" H 7700 2276 50  0000 C CNN
F 2 "" H 7700 2100 50  0001 C CNN
F 3 "~" H 7700 2100 50  0001 C CNN
	1    7700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2600 7250 2600
Wire Wire Line
	7250 2600 7250 2850
Wire Wire Line
	7150 2750 7150 2100
Wire Wire Line
	7150 2100 7400 2100
Wire Wire Line
	7050 2650 7050 1600
Wire Wire Line
	7050 1600 7400 1600
$Comp
L Electronics-rescue:+12V-power #PWR047
U 1 1 603B657B
P 9500 3600
F 0 "#PWR047" H 9500 3450 50  0001 C CNN
F 1 "+12V" H 9515 3773 50  0000 C CNN
F 2 "" H 9500 3600 50  0001 C CNN
F 3 "" H 9500 3600 50  0001 C CNN
	1    9500 3600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR033
U 1 1 603B6B41
P 7350 3550
F 0 "#PWR033" H 7350 3400 50  0001 C CNN
F 1 "+12V" H 7365 3723 50  0000 C CNN
F 2 "" H 7350 3550 50  0001 C CNN
F 3 "" H 7350 3550 50  0001 C CNN
	1    7350 3550
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR043
U 1 1 603B726D
P 8450 3600
F 0 "#PWR043" H 8450 3450 50  0001 C CNN
F 1 "+12V" H 8465 3773 50  0000 C CNN
F 2 "" H 8450 3600 50  0001 C CNN
F 3 "" H 8450 3600 50  0001 C CNN
	1    8450 3600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR034
U 1 1 603CF377
P 7350 4450
F 0 "#PWR034" H 7350 4200 50  0001 C CNN
F 1 "GND" H 7355 4277 50  0000 C CNN
F 2 "" H 7350 4450 50  0001 C CNN
F 3 "" H 7350 4450 50  0001 C CNN
	1    7350 4450
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR048
U 1 1 603CFA9B
P 9500 4300
F 0 "#PWR048" H 9500 4050 50  0001 C CNN
F 1 "GND" H 9505 4127 50  0000 C CNN
F 2 "" H 9500 4300 50  0001 C CNN
F 3 "" H 9500 4300 50  0001 C CNN
	1    9500 4300
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR044
U 1 1 603D01BF
P 8450 4500
F 0 "#PWR044" H 8450 4250 50  0001 C CNN
F 1 "GND" H 8455 4327 50  0000 C CNN
F 2 "" H 8450 4500 50  0001 C CNN
F 3 "" H 8450 4500 50  0001 C CNN
	1    8450 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3200 9200 3200
$Comp
L Electronics-rescue:ADW11-Relay K3
U 1 1 603D4E1C
P 9450 5550
F 0 "K3" H 9880 5596 50  0000 L CNN
F 1 "Solenoid" H 9650 5200 50  0000 L CNN
F 2 "Relay_THT:Relay_1P1T_NO_10x24x18.8mm_Panasonic_ADW11xxxxW_THT" H 10775 5500 50  0001 C CNN
F 3 "https://www.panasonic-electric-works.com/pew/es/downloads/ds_dw_hl_en.pdf" H 9450 5550 50  0001 C CNN
	1    9450 5550
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q5
U 1 1 603DD001
P 9150 6050
F 0 "Q5" H 9354 6096 50  0000 L CNN
F 1 "IRF3708" H 9354 6005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9400 5975 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 9150 6050 50  0001 L CNN
	1    9150 6050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR045
U 1 1 603DD007
P 9250 5250
F 0 "#PWR045" H 9250 5100 50  0001 C CNN
F 1 "+12V" H 9265 5423 50  0000 C CNN
F 2 "" H 9250 5250 50  0001 C CNN
F 3 "" H 9250 5250 50  0001 C CNN
	1    9250 5250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR046
U 1 1 603DDD3C
P 9250 6250
F 0 "#PWR046" H 9250 6000 50  0001 C CNN
F 1 "GND" H 9255 6077 50  0000 C CNN
F 2 "" H 9250 6250 50  0001 C CNN
F 3 "" H 9250 6250 50  0001 C CNN
	1    9250 6250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:ADW11-Relay K2
U 1 1 603E2520
P 8450 5550
F 0 "K2" H 8880 5596 50  0000 L CNN
F 1 "Solenoid" H 8600 5150 50  0000 L CNN
F 2 "Relay_THT:Relay_1P1T_NO_10x24x18.8mm_Panasonic_ADW11xxxxW_THT" H 9775 5500 50  0001 C CNN
F 3 "https://www.panasonic-electric-works.com/pew/es/downloads/ds_dw_hl_en.pdf" H 8450 5550 50  0001 C CNN
	1    8450 5550
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q3
U 1 1 603E252A
P 8150 6050
F 0 "Q3" H 8354 6096 50  0000 L CNN
F 1 "IRF3708" H 8354 6005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8400 5975 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 8150 6050 50  0001 L CNN
	1    8150 6050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR038
U 1 1 603E2534
P 8250 5250
F 0 "#PWR038" H 8250 5100 50  0001 C CNN
F 1 "+12V" H 8265 5423 50  0000 C CNN
F 2 "" H 8250 5250 50  0001 C CNN
F 3 "" H 8250 5250 50  0001 C CNN
	1    8250 5250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR039
U 1 1 603E253E
P 8250 6250
F 0 "#PWR039" H 8250 6000 50  0001 C CNN
F 1 "GND" H 8255 6077 50  0000 C CNN
F 2 "" H 8250 6250 50  0001 C CNN
F 3 "" H 8250 6250 50  0001 C CNN
	1    8250 6250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:ADW11-Relay K4
U 1 1 603E6536
P 10450 5550
F 0 "K4" H 10880 5596 50  0000 L CNN
F 1 "Solenoid" H 10650 5200 50  0000 L CNN
F 2 "Relay_THT:Relay_1P1T_NO_10x24x18.8mm_Panasonic_ADW11xxxxW_THT" H 11775 5500 50  0001 C CNN
F 3 "https://www.panasonic-electric-works.com/pew/es/downloads/ds_dw_hl_en.pdf" H 10450 5550 50  0001 C CNN
	1    10450 5550
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q7
U 1 1 603E6540
P 10150 6050
F 0 "Q7" H 10354 6096 50  0000 L CNN
F 1 "IRF3708" H 10354 6005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10400 5975 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 10150 6050 50  0001 L CNN
	1    10150 6050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR049
U 1 1 603E654A
P 10250 5250
F 0 "#PWR049" H 10250 5100 50  0001 C CNN
F 1 "+12V" H 10265 5423 50  0000 C CNN
F 2 "" H 10250 5250 50  0001 C CNN
F 3 "" H 10250 5250 50  0001 C CNN
	1    10250 5250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR050
U 1 1 603E6554
P 10250 6250
F 0 "#PWR050" H 10250 6000 50  0001 C CNN
F 1 "GND" H 10255 6077 50  0000 C CNN
F 2 "" H 10250 6250 50  0001 C CNN
F 3 "" H 10250 6250 50  0001 C CNN
	1    10250 6250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:ADW11-Relay K1
U 1 1 603E9200
P 7450 5550
F 0 "K1" H 7880 5596 50  0000 L CNN
F 1 "Solenoid" H 7550 5150 50  0000 L CNN
F 2 "Relay_THT:Relay_1P1T_NO_10x24x18.8mm_Panasonic_ADW11xxxxW_THT" H 8775 5500 50  0001 C CNN
F 3 "https://www.panasonic-electric-works.com/pew/es/downloads/ds_dw_hl_en.pdf" H 7450 5550 50  0001 C CNN
	1    7450 5550
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q1
U 1 1 603E920A
P 7150 6050
F 0 "Q1" H 7354 6096 50  0000 L CNN
F 1 "IRF3708" H 7354 6005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7400 5975 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 7150 6050 50  0001 L CNN
	1    7150 6050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR031
U 1 1 603E9214
P 7250 5250
F 0 "#PWR031" H 7250 5100 50  0001 C CNN
F 1 "+12V" H 7265 5423 50  0000 C CNN
F 2 "" H 7250 5250 50  0001 C CNN
F 3 "" H 7250 5250 50  0001 C CNN
	1    7250 5250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR032
U 1 1 603E921E
P 7250 6250
F 0 "#PWR032" H 7250 6000 50  0001 C CNN
F 1 "GND" H 7255 6077 50  0000 C CNN
F 2 "" H 7250 6250 50  0001 C CNN
F 3 "" H 7250 6250 50  0001 C CNN
	1    7250 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 4750 9950 4750
Wire Wire Line
	9950 4750 9950 6050
Wire Wire Line
	8950 6050 8950 4850
Wire Wire Line
	8950 4850 6850 4850
Wire Wire Line
	7950 4950 7950 6050
Wire Wire Line
	7250 2950 7250 3200
Wire Wire Line
	7150 3050 7150 3300
Wire Wire Line
	7050 3150 7050 3750
Wire Wire Line
	6950 6050 6950 5050
Wire Wire Line
	6950 3250 6950 4750
Wire Wire Line
	6850 4850 6850 3350
$Comp
L SSD1306-128x64_OLED:SSD1306 Brd1
U 1 1 6043204F
P 6400 5500
F 0 "Brd1" H 6678 5604 50  0000 L CNN
F 1 "SSD1306" H 6300 5150 50  0000 L CNN
F 2 "" H 6400 5750 50  0001 C CNN
F 3 "" H 6400 5750 50  0001 C CNN
	1    6400 5500
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R1
U 1 1 6041B393
P 3150 5850
F 0 "R1" V 3357 5850 50  0000 C CNN
F 1 "10k" V 3266 5850 50  0000 C CNN
F 2 "" V 3080 5850 50  0001 C CNN
F 3 "~" H 3150 5850 50  0001 C CNN
	1    3150 5850
	0    -1   -1   0   
$EndComp
$Comp
L Electronics-rescue:R-Device R2
U 1 1 60416806
P 3300 6000
F 0 "R2" H 3370 6046 50  0000 L CNN
F 1 "10k" H 3370 5955 50  0000 L CNN
F 2 "" V 3230 6000 50  0001 C CNN
F 3 "~" H 3300 6000 50  0001 C CNN
	1    3300 6000
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR022
U 1 1 60410A96
P 3300 6150
F 0 "#PWR022" H 3300 5900 50  0001 C CNN
F 1 "GND" H 3305 5977 50  0000 C CNN
F 2 "" H 3300 6150 50  0001 C CNN
F 3 "" H 3300 6150 50  0001 C CNN
	1    3300 6150
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+5V-power #PWR018
U 1 1 6040EFC3
P 2700 5600
F 0 "#PWR018" H 2700 5450 50  0001 C CNN
F 1 "+5V" H 2715 5773 50  0000 C CNN
F 2 "" H 2700 5600 50  0001 C CNN
F 3 "" H 2700 5600 50  0001 C CNN
	1    2700 5600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR019
U 1 1 6040C751
P 2700 6100
F 0 "#PWR019" H 2700 5850 50  0001 C CNN
F 1 "GND" H 2705 5927 50  0000 C CNN
F 2 "" H 2700 6100 50  0001 C CNN
F 3 "" H 2700 6100 50  0001 C CNN
	1    2700 6100
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:Fan_Tacho_PWM-Motor M1
U 1 1 603FCCD2
P 2700 5900
F 0 "M1" H 2857 5996 50  0000 L CNN
F 1 "FlowMeter" H 2857 5905 50  0000 L CNN
F 2 "" H 2700 5910 50  0001 C CNN
F 3 "http://www.formfactors.org/developer%5Cspecs%5Crev1_2_public.pdf" H 2700 5910 50  0001 C CNN
	1    2700 5900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6650 3550 5950 3550
Wire Wire Line
	6650 5050 6650 3550
Wire Wire Line
	6950 5050 6650 5050
Wire Wire Line
	6750 4950 7950 4950
Wire Wire Line
	6750 3450 6750 4950
Wire Wire Line
	5950 3450 6750 3450
Wire Wire Line
	6850 3350 5950 3350
Wire Wire Line
	5950 3250 6950 3250
Wire Wire Line
	5950 3150 7050 3150
Wire Wire Line
	5950 3050 7150 3050
Wire Wire Line
	5950 2950 7250 2950
Wire Wire Line
	5950 2650 7050 2650
Wire Wire Line
	5950 2750 7150 2750
Wire Wire Line
	7250 2850 5950 2850
Wire Wire Line
	4350 3450 2450 3450
$Comp
L Electronics-rescue:R_POT-Device RV4
U 1 1 603742EC
P 1550 5200
F 0 "RV4" H 1480 5246 50  0000 R CNN
F 1 "Area4" H 1480 5155 50  0000 R CNN
F 2 "" H 1550 5200 50  0001 C CNN
F 3 "~" H 1550 5200 50  0001 C CNN
	1    1550 5200
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV3
U 1 1 603739F4
P 1550 4600
F 0 "RV3" H 1480 4646 50  0000 R CNN
F 1 "Area3" H 1480 4555 50  0000 R CNN
F 2 "" H 1550 4600 50  0001 C CNN
F 3 "~" H 1550 4600 50  0001 C CNN
	1    1550 4600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV8
U 1 1 603728AB
P 2000 4900
F 0 "RV8" H 1930 4946 50  0000 R CNN
F 1 "Area2" H 1930 4855 50  0000 R CNN
F 2 "" H 2000 4900 50  0001 C CNN
F 3 "~" H 2000 4900 50  0001 C CNN
	1    2000 4900
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV7
U 1 1 60371EA3
P 1950 4150
F 0 "RV7" H 1880 4196 50  0000 R CNN
F 1 "Area1" H 1880 4105 50  0000 R CNN
F 2 "" H 1950 4150 50  0001 C CNN
F 3 "~" H 1950 4150 50  0001 C CNN
	1    1950 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 3750 2050 3750
Wire Wire Line
	2050 3050 4350 3050
Wire Wire Line
	4350 3350 2350 3350
Wire Wire Line
	4350 3250 2250 3250
Wire Wire Line
	4350 3150 2150 3150
Wire Wire Line
	1950 2950 1950 3300
Wire Wire Line
	2050 3050 2050 3750
Wire Wire Line
	4350 2950 1950 2950
Wire Wire Line
	1650 2850 1650 2950
Wire Wire Line
	4350 2850 1650 2850
Wire Wire Line
	1900 2750 1900 2450
Wire Wire Line
	4350 2750 1900 2750
$Comp
L Electronics-rescue:+3.3V-power #PWR01
U 1 1 60342F93
P 1500 3600
F 0 "#PWR01" H 1500 3450 50  0001 C CNN
F 1 "+3.3V" H 1515 3773 50  0000 C CNN
F 2 "" H 1500 3600 50  0001 C CNN
F 3 "" H 1500 3600 50  0001 C CNN
	1    1500 3600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR04
U 1 1 60342F8D
P 1500 3900
F 0 "#PWR04" H 1500 3650 50  0001 C CNN
F 1 "GND" H 1505 3727 50  0000 C CNN
F 2 "" H 1500 3900 50  0001 C CNN
F 3 "" H 1500 3900 50  0001 C CNN
	1    1500 3900
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV2
U 1 1 60342F87
P 1500 3750
F 0 "RV2" H 1430 3796 50  0000 R CNN
F 1 "Hygrometer" H 1430 3705 50  0000 R CNN
F 2 "" H 1500 3750 50  0001 C CNN
F 3 "~" H 1500 3750 50  0001 C CNN
	1    1500 3750
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR010
U 1 1 60342A67
P 1800 3150
F 0 "#PWR010" H 1800 3000 50  0001 C CNN
F 1 "+3.3V" H 1815 3323 50  0000 C CNN
F 2 "" H 1800 3150 50  0001 C CNN
F 3 "" H 1800 3150 50  0001 C CNN
	1    1800 3150
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR011
U 1 1 60342A61
P 1800 3450
F 0 "#PWR011" H 1800 3200 50  0001 C CNN
F 1 "GND" H 1805 3277 50  0000 C CNN
F 2 "" H 1800 3450 50  0001 C CNN
F 3 "" H 1800 3450 50  0001 C CNN
	1    1800 3450
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV6
U 1 1 60342A5B
P 1800 3300
F 0 "RV6" H 1730 3346 50  0000 R CNN
F 1 "Hygrometer" H 1730 3255 50  0000 R CNN
F 2 "" H 1800 3300 50  0001 C CNN
F 3 "~" H 1800 3300 50  0001 C CNN
	1    1800 3300
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR02
U 1 1 6034184B
P 1500 2800
F 0 "#PWR02" H 1500 2650 50  0001 C CNN
F 1 "+3.3V" H 1515 2973 50  0000 C CNN
F 2 "" H 1500 2800 50  0001 C CNN
F 3 "" H 1500 2800 50  0001 C CNN
	1    1500 2800
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR03
U 1 1 60341845
P 1500 3100
F 0 "#PWR03" H 1500 2850 50  0001 C CNN
F 1 "GND" H 1505 2927 50  0000 C CNN
F 2 "" H 1500 3100 50  0001 C CNN
F 3 "" H 1500 3100 50  0001 C CNN
	1    1500 3100
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV1
U 1 1 6034183F
P 1500 2950
F 0 "RV1" H 1430 2996 50  0000 R CNN
F 1 "Hygrometer" H 1430 2905 50  0000 R CNN
F 2 "" H 1500 2950 50  0001 C CNN
F 3 "~" H 1500 2950 50  0001 C CNN
	1    1500 2950
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR08
U 1 1 6033A7BB
P 1750 2300
F 0 "#PWR08" H 1750 2150 50  0001 C CNN
F 1 "+3.3V" H 1765 2473 50  0000 C CNN
F 2 "" H 1750 2300 50  0001 C CNN
F 3 "" H 1750 2300 50  0001 C CNN
	1    1750 2300
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR09
U 1 1 60339D63
P 1750 2600
F 0 "#PWR09" H 1750 2350 50  0001 C CNN
F 1 "GND" H 1755 2427 50  0000 C CNN
F 2 "" H 1750 2600 50  0001 C CNN
F 3 "" H 1750 2600 50  0001 C CNN
	1    1750 2600
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R_POT-Device RV5
U 1 1 6032FD70
P 1750 2450
F 0 "RV5" H 1680 2496 50  0000 R CNN
F 1 "Hygrometer" H 1680 2405 50  0000 R CNN
F 2 "" H 1750 2450 50  0001 C CNN
F 3 "~" H 1750 2450 50  0001 C CNN
	1    1750 2450
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR029
U 1 1 604AC98C
P 6350 3850
F 0 "#PWR029" H 6350 3700 50  0001 C CNN
F 1 "+3.3V" V 6300 3900 50  0000 L CNN
F 2 "" H 6350 3850 50  0001 C CNN
F 3 "" H 6350 3850 50  0001 C CNN
	1    6350 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 3650 6550 4850
$Comp
L Electronics-rescue:GND-power #PWR028
U 1 1 604B4C52
P 6250 5150
F 0 "#PWR028" H 6250 4900 50  0001 C CNN
F 1 "GND" H 6255 4977 50  0000 C CNN
F 2 "" H 6250 5150 50  0001 C CNN
F 3 "" H 6250 5150 50  0001 C CNN
	1    6250 5150
	-1   0    0    1   
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR030
U 1 1 604B5C90
P 6350 5150
F 0 "#PWR030" H 6350 5000 50  0001 C CNN
F 1 "+3.3V" H 6350 5400 50  0000 C CNN
F 2 "" H 6350 5150 50  0001 C CNN
F 3 "" H 6350 5150 50  0001 C CNN
	1    6350 5150
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR012
U 1 1 604C5317
P 1950 4000
F 0 "#PWR012" H 1950 3850 50  0001 C CNN
F 1 "+3.3V" H 1965 4173 50  0000 C CNN
F 2 "" H 1950 4000 50  0001 C CNN
F 3 "" H 1950 4000 50  0001 C CNN
	1    1950 4000
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR07
U 1 1 604C6F93
P 1550 5050
F 0 "#PWR07" H 1550 4900 50  0001 C CNN
F 1 "+3.3V" H 1565 5223 50  0000 C CNN
F 2 "" H 1550 5050 50  0001 C CNN
F 3 "" H 1550 5050 50  0001 C CNN
	1    1550 5050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR05
U 1 1 604C8B8B
P 1550 4450
F 0 "#PWR05" H 1550 4300 50  0001 C CNN
F 1 "+3.3V" H 1565 4623 50  0000 C CNN
F 2 "" H 1550 4450 50  0001 C CNN
F 3 "" H 1550 4450 50  0001 C CNN
	1    1550 4450
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR014
U 1 1 604CA7FA
P 2000 4750
F 0 "#PWR014" H 2000 4600 50  0001 C CNN
F 1 "+3.3V" H 2015 4923 50  0000 C CNN
F 2 "" H 2000 4750 50  0001 C CNN
F 3 "" H 2000 4750 50  0001 C CNN
	1    2000 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3150 2150 4150
Wire Wire Line
	2150 4150 2100 4150
$Comp
L Electronics-rescue:GND-power #PWR013
U 1 1 604D971C
P 1950 4300
F 0 "#PWR013" H 1950 4050 50  0001 C CNN
F 1 "GND" H 1955 4127 50  0000 C CNN
F 2 "" H 1950 4300 50  0001 C CNN
F 3 "" H 1950 4300 50  0001 C CNN
	1    1950 4300
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR06
U 1 1 604DB458
P 1550 4750
F 0 "#PWR06" H 1550 4500 50  0001 C CNN
F 1 "GND" H 1555 4577 50  0000 C CNN
F 2 "" H 1550 4750 50  0001 C CNN
F 3 "" H 1550 4750 50  0001 C CNN
	1    1550 4750
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR015
U 1 1 604DD0C9
P 2000 5050
F 0 "#PWR015" H 2000 4800 50  0001 C CNN
F 1 "GND" H 2005 4877 50  0000 C CNN
F 2 "" H 2000 5050 50  0001 C CNN
F 3 "" H 2000 5050 50  0001 C CNN
	1    2000 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 3250 2250 4600
Wire Wire Line
	2250 4600 1700 4600
Wire Wire Line
	2350 4900 2150 4900
Wire Wire Line
	2350 3350 2350 4900
Wire Wire Line
	1700 5200 2450 5200
Wire Wire Line
	2450 3450 2450 5200
Wire Wire Line
	4350 3750 3300 3750
Wire Wire Line
	3300 3750 3300 5850
Wire Wire Line
	6550 3650 5950 3650
$Comp
L Electronics-rescue:SW_Push-Switch SW1
U 1 1 604AAD59
P 6150 3850
F 0 "SW1" H 6150 3800 50  0000 C CNN
F 1 "btn_wake" H 5950 3950 50  0000 C CNN
F 2 "" H 6150 4050 50  0001 C CNN
F 3 "~" H 6150 4050 50  0001 C CNN
	1    6150 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5950 3750 6450 3750
Wire Wire Line
	6450 3750 6450 4950
$Comp
L Electronics-rescue:GND-power #PWR027
U 1 1 603A8B7F
P 6250 4400
F 0 "#PWR027" H 6250 4150 50  0001 C CNN
F 1 "GND" H 6255 4227 50  0000 C CNN
F 2 "" H 6250 4400 50  0001 C CNN
F 3 "" H 6250 4400 50  0001 C CNN
	1    6250 4400
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:R-Device R3
U 1 1 603A8B79
P 6250 4250
F 0 "R3" H 6320 4296 50  0000 L CNN
F 1 "R" H 6320 4205 50  0000 L CNN
F 2 "" V 6180 4250 50  0001 C CNN
F 3 "~" H 6250 4250 50  0001 C CNN
	1    6250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 4100 6050 4100
Wire Wire Line
	6050 3950 5950 3850
Wire Wire Line
	7150 3300 8150 3300
Wire Wire Line
	8150 3300 8150 3800
Wire Wire Line
	9200 3200 9200 3800
$Comp
L Electronics-rescue:IRLB8721PBF-Transistor_FET Q6
U 1 1 60386A74
P 9400 3800
F 0 "Q6" H 9604 3846 50  0000 L CNN
F 1 "IRF3708" H 9604 3755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9650 3725 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 9400 3800 50  0001 L CNN
	1    9400 3800
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:L7805-Regulator_Linear U3
U 1 1 60F893B7
P 3600 1050
F 0 "U3" H 3600 1292 50  0000 C CNN
F 1 "L78S33" H 3600 1201 50  0000 C CNN
F 2 "" H 3625 900 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3600 1000 50  0001 C CNN
	1    3600 1050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR024
U 1 1 60F8BC2C
P 3600 1350
F 0 "#PWR024" H 3600 1100 50  0001 C CNN
F 1 "GND" H 3605 1177 50  0000 C CNN
F 2 "" H 3600 1350 50  0001 C CNN
F 3 "" H 3600 1350 50  0001 C CNN
	1    3600 1350
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR023
U 1 1 60F8D9F5
P 3300 1050
F 0 "#PWR023" H 3300 900 50  0001 C CNN
F 1 "+12V" H 3315 1223 50  0000 C CNN
F 2 "" H 3300 1050 50  0001 C CNN
F 3 "" H 3300 1050 50  0001 C CNN
	1    3300 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1050 3950 1050
$Comp
L Electronics-rescue:GND-power #PWR025
U 1 1 60F9028F
P 4350 3950
F 0 "#PWR025" H 4350 3700 50  0001 C CNN
F 1 "GND" V 4355 3777 50  0000 C CNN
F 2 "" H 4350 3950 50  0001 C CNN
F 3 "" H 4350 3950 50  0001 C CNN
	1    4350 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 3950 6050 4100
Connection ~ 5950 3850
$Comp
L Electronics-rescue:+3.3V-power #PWR026
U 1 1 60F97162
P 5950 4050
F 0 "#PWR026" H 5950 3900 50  0001 C CNN
F 1 "+3.3V" H 5965 4223 50  0000 C CNN
F 2 "" H 5950 4050 50  0001 C CNN
F 3 "" H 5950 4050 50  0001 C CNN
	1    5950 4050
	-1   0    0    1   
$EndComp
$Comp
L ESP32DEVKITV1:ESP32DEVKITV1 BOARD1
U 1 1 603274CE
P 4450 4450
F 0 "BOARD1" H 5173 6776 50  0000 C CNN
F 1 "ESP32DEVKITV1" H 4450 4450 50  0001 L BNN
F 2 "ESP32-DEVKITV1" H 4450 4450 50  0001 L BNN
F 3 "" H 4450 4450 50  0001 L BNN
	1    4450 4450
	1    0    0    -1  
$EndComp
$Comp
L Electronics-cache:+3.3V #PWR?
U 1 1 627F41DA
P 3950 1050
F 0 "#PWR?" H 3950 900 50  0001 C CNN
F 1 "+3.3V" H 3965 1223 50  0000 C CNN
F 2 "" H 3950 1050 50  0001 C CNN
F 3 "" H 3950 1050 50  0001 C CNN
	1    3950 1050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:L7805-Regulator_Linear U?
U 1 1 628016E8
P 4600 1050
F 0 "U?" H 4600 1292 50  0000 C CNN
F 1 "L78S05" H 4600 1201 50  0000 C CNN
F 2 "" H 4625 900 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4600 1000 50  0001 C CNN
	1    4600 1050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR?
U 1 1 628016EE
P 4600 1350
F 0 "#PWR?" H 4600 1100 50  0001 C CNN
F 1 "GND" H 4605 1177 50  0000 C CNN
F 2 "" H 4600 1350 50  0001 C CNN
F 3 "" H 4600 1350 50  0001 C CNN
	1    4600 1350
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR?
U 1 1 628016F4
P 4300 1050
F 0 "#PWR?" H 4300 900 50  0001 C CNN
F 1 "+12V" H 4315 1223 50  0000 C CNN
F 2 "" H 4300 1050 50  0001 C CNN
F 3 "" H 4300 1050 50  0001 C CNN
	1    4300 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1050 4950 1050
$Comp
L Electronics-rescue:+5V-power #PWR?
U 1 1 628016FB
P 4950 1050
F 0 "#PWR?" H 4950 900 50  0001 C CNN
F 1 "+5V-power" H 4965 1223 50  0000 C CNN
F 2 "" H 4950 1050 50  0001 C CNN
F 3 "" H 4950 1050 50  0001 C CNN
	1    4950 1050
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:+5V-power #PWR?
U 1 1 6280A309
P 4350 4050
F 0 "#PWR?" H 4350 3900 50  0001 C CNN
F 1 "+5V-power" V 4365 4177 50  0000 L CNN
F 2 "" H 4350 4050 50  0001 C CNN
F 3 "" H 4350 4050 50  0001 C CNN
	1    4350 4050
	0    -1   -1   0   
$EndComp
$Comp
L Device:Solar_Cell SC1
U 1 1 627C0760
P 1650 1100
F 0 "SC1" H 1300 1200 50  0000 L CNN
F 1 "Solar_Cell" H 1150 1300 50  0000 L CNN
F 2 "" V 1650 1160 50  0001 C CNN
F 3 "~" V 1650 1160 50  0001 C CNN
	1    1650 1100
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:SolarChargeController-Electronics-cache U1
U 1 1 627DB756
P 2150 950
F 0 "U1" H 2500 100 50  0000 L CNN
F 1 "SolarChargeController" H 2150 1000 50  0000 L CNN
F 2 "" H 2100 1000 50  0001 C CNN
F 3 "" H 2100 1000 50  0001 C CNN
	1    2150 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1100 2100 900 
Wire Wire Line
	2100 900  1650 900 
$Comp
L Device:Battery_Cell BT1
U 1 1 6280427B
P 1200 1300
F 0 "BT1" H 850 1400 50  0000 L CNN
F 1 "Battery_Cell" H 700 1500 50  0000 L CNN
F 2 "" V 1200 1360 50  0001 C CNN
F 3 "~" V 1200 1360 50  0001 C CNN
	1    1200 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1100 2200 1100
Wire Wire Line
	1650 1200 2200 1200
Wire Wire Line
	2200 1300 1500 1300
Wire Wire Line
	1500 1300 1500 1100
Wire Wire Line
	2200 1400 1200 1400
Wire Wire Line
	1500 1100 1200 1100
$Comp
L Electronics-rescue:GND-power #PWR?
U 1 1 6283A17B
P 2200 1600
F 0 "#PWR?" H 2200 1350 50  0001 C CNN
F 1 "GND" V 2205 1427 50  0000 C CNN
F 2 "" H 2200 1600 50  0001 C CNN
F 3 "" H 2200 1600 50  0001 C CNN
	1    2200 1600
	0    1    1    0   
$EndComp
$Comp
L Electronics-rescue:+12V-power #PWR?
U 1 1 6283BAD3
P 2200 1500
F 0 "#PWR?" H 2200 1350 50  0001 C CNN
F 1 "+12V" V 2215 1673 50  0000 C CNN
F 2 "" H 2200 1500 50  0001 C CNN
F 3 "" H 2200 1500 50  0001 C CNN
	1    2200 1500
	0    -1   -1   0   
$EndComp
$Comp
L Timer_RTC:DS3231M U?
U 1 1 627C827E
P 5550 5700
F 0 "U?" V 5504 5257 50  0000 R CNN
F 1 "DS3231M" V 5595 5257 50  0000 R CNN
F 2 "Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm" H 5550 5100 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS3231.pdf" H 5820 5750 50  0001 C CNN
	1    5550 5700
	0    1    1    0   
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR?
U 1 1 627C9B29
P 5150 5700
F 0 "#PWR?" H 5150 5450 50  0001 C CNN
F 1 "GND" H 5155 5527 50  0000 C CNN
F 2 "" H 5150 5700 50  0001 C CNN
F 3 "" H 5150 5700 50  0001 C CNN
	1    5150 5700
	-1   0    0    1   
$EndComp
$Comp
L Electronics-rescue:+3.3V-power #PWR?
U 1 1 627CA0DB
P 5950 5600
F 0 "#PWR?" H 5950 5450 50  0001 C CNN
F 1 "+3.3V" H 5950 5850 50  0000 C CNN
F 2 "" H 5950 5600 50  0001 C CNN
F 3 "" H 5950 5600 50  0001 C CNN
	1    5950 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4950 5750 4950
Wire Wire Line
	5750 4950 5750 5200
Connection ~ 6450 4950
Wire Wire Line
	6450 4950 6450 5150
Wire Wire Line
	6550 4850 5650 4850
Wire Wire Line
	5650 4850 5650 5200
Connection ~ 6550 4850
Wire Wire Line
	6550 4850 6550 5150
$Comp
L Electronics-cache:HTU31D U2
U 1 1 627D5180
P 4700 5200
F 0 "U2" V 4921 5178 50  0000 L CNN
F 1 "HTU31D" V 5012 5178 50  0000 L CNN
F 2 "" H 4700 5200 50  0001 C CNN
F 3 "" H 4700 5200 50  0001 C CNN
	1    4700 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 4850 4250 4850
Wire Wire Line
	4250 4850 4250 5250
Connection ~ 5650 4850
Wire Wire Line
	5750 4950 4350 4950
Wire Wire Line
	4350 4950 4350 5250
Connection ~ 5750 4950
$Comp
L Electronics-rescue:+3.3V-power #PWR?
U 1 1 627DC2C1
P 4450 5250
F 0 "#PWR?" H 4450 5100 50  0001 C CNN
F 1 "+3.3V" H 4450 5500 50  0000 C CNN
F 2 "" H 4450 5250 50  0001 C CNN
F 3 "" H 4450 5250 50  0001 C CNN
	1    4450 5250
	1    0    0    -1  
$EndComp
$Comp
L Electronics-rescue:GND-power #PWR?
U 1 1 627DCB3F
P 4550 5250
F 0 "#PWR?" H 4550 5000 50  0001 C CNN
F 1 "GND" H 4555 5077 50  0000 C CNN
F 2 "" H 4550 5250 50  0001 C CNN
F 3 "" H 4550 5250 50  0001 C CNN
	1    4550 5250
	-1   0    0    1   
$EndComp
Text Notes 6300 6000 0    50   ~ 0
Display
Text Notes 5250 6400 0    50   ~ 0
Real Time Clock
Text Notes 4100 6000 0    50   ~ 0
Temperature & \nHumidity\nSensor
$EndSCHEMATC
