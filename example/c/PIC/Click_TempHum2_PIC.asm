
_systemInit:

;Click_TempHum2_PIC.c,32 :: 		void systemInit()
;Click_TempHum2_PIC.c,34 :: 		mikrobus_i2cInit( _MIKROBUS1, &_TEMPHUM2_I2C_CFG[0] );
	CLRF        FARG_mikrobus_i2cInit_bus+0 
	MOVLW       __TEMPHUM2_I2C_CFG+0
	MOVWF       FARG_mikrobus_i2cInit_cfg+0 
	MOVLW       hi_addr(__TEMPHUM2_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+1 
	MOVLW       higher_addr(__TEMPHUM2_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+2 
	CALL        _mikrobus_i2cInit+0, 0
;Click_TempHum2_PIC.c,35 :: 		mikrobus_logInit( _LOG_USBUART, 9600 );
	MOVLW       16
	MOVWF       FARG_mikrobus_logInit_port+0 
	MOVLW       128
	MOVWF       FARG_mikrobus_logInit_baud+0 
	MOVLW       37
	MOVWF       FARG_mikrobus_logInit_baud+1 
	MOVLW       0
	MOVWF       FARG_mikrobus_logInit_baud+2 
	MOVWF       FARG_mikrobus_logInit_baud+3 
	CALL        _mikrobus_logInit+0, 0
;Click_TempHum2_PIC.c,36 :: 		mikrobus_logWrite( " --- System Init --- ", _LOG_LINE);
	MOVLW       ?lstr1_Click_TempHum2_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr1_Click_TempHum2_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,37 :: 		Delay_ms( 100 );
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_systemInit0:
	DECFSZ      R13, 1, 1
	BRA         L_systemInit0
	DECFSZ      R12, 1, 1
	BRA         L_systemInit0
	DECFSZ      R11, 1, 1
	BRA         L_systemInit0
	NOP
;Click_TempHum2_PIC.c,38 :: 		}
L_end_systemInit:
	RETURN      0
; end of _systemInit

_applicationInit:

;Click_TempHum2_PIC.c,40 :: 		void applicationInit()
;Click_TempHum2_PIC.c,42 :: 		temphum2_i2cDriverInit( (T_TEMPHUM2_P)&_MIKROBUS1_GPIO, (T_TEMPHUM2_P)&_MIKROBUS1_I2C, 0x70 );
	MOVLW       __MIKROBUS1_GPIO+0
	MOVWF       FARG_temphum2_i2cDriverInit_gpioObj+0 
	MOVLW       hi_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_temphum2_i2cDriverInit_gpioObj+1 
	MOVLW       higher_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_temphum2_i2cDriverInit_gpioObj+2 
	MOVLW       __MIKROBUS1_I2C+0
	MOVWF       FARG_temphum2_i2cDriverInit_i2cObj+0 
	MOVLW       hi_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_temphum2_i2cDriverInit_i2cObj+1 
	MOVLW       higher_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_temphum2_i2cDriverInit_i2cObj+2 
	MOVLW       112
	MOVWF       FARG_temphum2_i2cDriverInit_slave+0 
	CALL        _temphum2_i2cDriverInit+0, 0
;Click_TempHum2_PIC.c,43 :: 		temphum2_setMode(_TEMPHUM2_NO_HOLD_MODE, _TEMPHUM2_NORMAL_MODE);
	MOVLW       __TEMPHUM2_NO_HOLD_MODE
	MOVWF       FARG_temphum2_setMode_selectMode+0 
	MOVLW       __TEMPHUM2_NORMAL_MODE
	MOVWF       FARG_temphum2_setMode_speedMode+0 
	CALL        _temphum2_setMode+0, 0
;Click_TempHum2_PIC.c,44 :: 		temphum2_writeByte(_TEMPHUM2_REG_WRITE_HEATER_CONTROL, _TEMPHUM2_HEATER_ENABLE | _TEMPHUM2_HEATER_CURRENT_6_4mA);
	MOVLW       __TEMPHUM2_REG_WRITE_HEATER_CONTROL
	MOVWF       FARG_temphum2_writeByte_reg+0 
	MOVLW       __TEMPHUM2_HEATER_ENABLE
	MOVWF       R0 
	MOVLW       __TEMPHUM2_HEATER_CURRENT_6_4mA
	IORWF       R0, 0 
	MOVWF       FARG_temphum2_writeByte__data+0 
	CALL        _temphum2_writeByte+0, 0
;Click_TempHum2_PIC.c,45 :: 		}
L_end_applicationInit:
	RETURN      0
; end of _applicationInit

_applicationTask:

;Click_TempHum2_PIC.c,47 :: 		void applicationTask()
;Click_TempHum2_PIC.c,49 :: 		temphum2_getMeasurement( &dataBuffer[0] );
	MOVLW       _dataBuffer+0
	MOVWF       FARG_temphum2_getMeasurement_dataBuffer+0 
	MOVLW       hi_addr(_dataBuffer+0)
	MOVWF       FARG_temphum2_getMeasurement_dataBuffer+1 
	CALL        _temphum2_getMeasurement+0, 0
;Click_TempHum2_PIC.c,51 :: 		mikrobus_logWrite( " --- Temperature : ", _LOG_TEXT);
	MOVLW       ?lstr2_Click_TempHum2_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr2_Click_TempHum2_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,52 :: 		FloatToStr( dataBuffer[0] , dataText);
	MOVF        _dataBuffer+0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        _dataBuffer+1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        _dataBuffer+2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        _dataBuffer+3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_TempHum2_PIC.c,53 :: 		mikrobus_logWrite(dataText, _LOG_TEXT);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,54 :: 		mikrobus_logWrite( " C", _LOG_LINE);
	MOVLW       ?lstr3_Click_TempHum2_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr3_Click_TempHum2_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,56 :: 		mikrobus_logWrite( " --- Humidity : ", _LOG_TEXT);
	MOVLW       ?lstr4_Click_TempHum2_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr4_Click_TempHum2_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,57 :: 		FloatToStr( dataBuffer[1] , dataText);
	MOVF        _dataBuffer+4, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        _dataBuffer+5, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        _dataBuffer+6, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        _dataBuffer+7, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_TempHum2_PIC.c,58 :: 		mikrobus_logWrite(dataText, _LOG_TEXT);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,59 :: 		mikrobus_logWrite( " %RH", _LOG_LINE);
	MOVLW       ?lstr5_Click_TempHum2_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr5_Click_TempHum2_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_TempHum2_PIC.c,61 :: 		Delay_ms( 500 );
	MOVLW       41
	MOVWF       R11, 0
	MOVLW       150
	MOVWF       R12, 0
	MOVLW       127
	MOVWF       R13, 0
L_applicationTask1:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask1
;Click_TempHum2_PIC.c,62 :: 		}
L_end_applicationTask:
	RETURN      0
; end of _applicationTask

_main:

;Click_TempHum2_PIC.c,64 :: 		void main()
;Click_TempHum2_PIC.c,66 :: 		systemInit();
	CALL        _systemInit+0, 0
;Click_TempHum2_PIC.c,67 :: 		applicationInit();
	CALL        _applicationInit+0, 0
;Click_TempHum2_PIC.c,69 :: 		while (1)
L_main2:
;Click_TempHum2_PIC.c,71 :: 		applicationTask();
	CALL        _applicationTask+0, 0
;Click_TempHum2_PIC.c,72 :: 		}
	GOTO        L_main2
;Click_TempHum2_PIC.c,73 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
