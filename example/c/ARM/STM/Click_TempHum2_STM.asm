_systemInit:
;Click_TempHum2_STM.c,32 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_TempHum2_STM.c,34 :: 		mikrobus_i2cInit( _MIKROBUS1, &_TEMPHUM2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__TEMPHUM2_I2C_CFG+0)
MOVT	R0, #hi_addr(__TEMPHUM2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_TempHum2_STM.c,35 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_TempHum2_STM.c,36 :: 		mikrobus_logWrite( " --- System Init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_TempHum2_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_TempHum2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,37 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_TempHum2_STM.c,38 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_TempHum2_STM.c,40 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_TempHum2_STM.c,42 :: 		temphum2_i2cDriverInit( (T_TEMPHUM2_P)&_MIKROBUS1_GPIO, (T_TEMPHUM2_P)&_MIKROBUS1_I2C, 0x70 );
MOVS	R2, #112
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_temphum2_i2cDriverInit+0
;Click_TempHum2_STM.c,43 :: 		temphum2_setMode(_TEMPHUM2_NO_HOLD_MODE, _TEMPHUM2_NORMAL_MODE);
MOVS	R1, __TEMPHUM2_NORMAL_MODE
MOVS	R0, __TEMPHUM2_NO_HOLD_MODE
BL	_temphum2_setMode+0
;Click_TempHum2_STM.c,44 :: 		temphum2_writeByte(_TEMPHUM2_REG_WRITE_HEATER_CONTROL, _TEMPHUM2_HEATER_ENABLE | _TEMPHUM2_HEATER_CURRENT_6_4mA);
MOVS	R0, __TEMPHUM2_HEATER_ENABLE
ORR	R0, R0, __TEMPHUM2_HEATER_CURRENT_6_4mA
UXTB	R1, R0
MOVS	R0, __TEMPHUM2_REG_WRITE_HEATER_CONTROL
BL	_temphum2_writeByte+0
;Click_TempHum2_STM.c,45 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_TempHum2_STM.c,47 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_TempHum2_STM.c,49 :: 		temphum2_getMeasurement( &dataBuffer[0] );
MOVW	R0, #lo_addr(_dataBuffer+0)
MOVT	R0, #hi_addr(_dataBuffer+0)
BL	_temphum2_getMeasurement+0
;Click_TempHum2_STM.c,51 :: 		mikrobus_logWrite( " --- Temperature : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_TempHum2_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_TempHum2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,52 :: 		FloatToStr( dataBuffer[0] , dataText);
MOVW	R0, #lo_addr(_dataBuffer+0)
MOVT	R0, #hi_addr(_dataBuffer+0)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_TempHum2_STM.c,53 :: 		mikrobus_logWrite(dataText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,54 :: 		mikrobus_logWrite( " C", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_TempHum2_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_TempHum2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,56 :: 		mikrobus_logWrite( " --- Humidity : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_TempHum2_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_TempHum2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,57 :: 		FloatToStr( dataBuffer[1] , dataText);
MOVW	R0, #lo_addr(_dataBuffer+4)
MOVT	R0, #hi_addr(_dataBuffer+4)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_TempHum2_STM.c,58 :: 		mikrobus_logWrite(dataText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,59 :: 		mikrobus_logWrite( " %RH", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_TempHum2_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_TempHum2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_TempHum2_STM.c,61 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_TempHum2_STM.c,62 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_TempHum2_STM.c,64 :: 		void main()
;Click_TempHum2_STM.c,66 :: 		systemInit();
BL	_systemInit+0
;Click_TempHum2_STM.c,67 :: 		applicationInit();
BL	_applicationInit+0
;Click_TempHum2_STM.c,69 :: 		while (1)
L_main4:
;Click_TempHum2_STM.c,71 :: 		applicationTask();
BL	_applicationTask+0
;Click_TempHum2_STM.c,72 :: 		}
IT	AL
BAL	L_main4
;Click_TempHum2_STM.c,73 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
