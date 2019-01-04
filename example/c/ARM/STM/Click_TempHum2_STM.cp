#line 1 "D:/Clicks_git/Temp-Hum_2_Click/SW/example/c/ARM/STM/Click_TempHum2_STM.c"
#line 1 "d:/clicks_git/temp-hum_2_click/sw/example/c/arm/stm/click_temphum2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/temp-hum_2_click/sw/example/c/arm/stm/click_temphum2_config.h"
#line 1 "d:/clicks_git/temp-hum_2_click/sw/example/c/arm/stm/click_temphum2_types.h"
#line 3 "d:/clicks_git/temp-hum_2_click/sw/example/c/arm/stm/click_temphum2_config.h"
const uint32_t _TEMPHUM2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
extern const uint16_t _TEMPHUM2_REG_FIRMWARE_REVISION;
extern const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_1;
extern const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_2;
extern const uint8_t _TEMPHUM2_REG_SOFT_RESET;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_NORMAL_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_FAST_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_FAST_MODE;
extern const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP;
extern const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP1;
extern const uint8_t _TEMPHUM2_REG_WRITE_HEATER_CONTROL;
extern const uint8_t _TEMPHUM2_REG_READ_HEATER_CONTROL;


extern const uint8_t _QUERY_DEVICE_ERROR;
extern const uint8_t _QUERY_DEVICE_OK;


extern const uint8_t _TEMPHUM2_HEATER_ENABLE;
extern const uint8_t _TEMPHUM2_HEATER_DISABLE;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_6_4mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_9_7mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_13_1mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_19_6mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_32_4mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_53_5mA;


extern const uint8_t _TEMPHUM2_NO_HOLD_MODE;
extern const uint8_t _TEMPHUM2_HOLD_MODE;
extern const uint8_t _TEMPHUM2_NORMAL_MODE;
extern const uint8_t _TEMPHUM2_FAST_MODE;
#line 103 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temphum2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 110 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temphum2_gpioDriverInit( const uint8_t*  gpioObj);
#line 121 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temphum2_writeByte(uint8_t reg, uint8_t _data);
#line 129 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
uint8_t temphum2_readByte(uint8_t reg);
#line 137 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temphum2_setMode(uint8_t selectMode, uint8_t speedMode);
#line 148 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temphum2_getMeasurement( float *dataBuffer );
#line 156 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
uint8_t temphum2_readFirmwareRevision();
#line 163 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
void temhum2_getEletronicID(uint8_t *electronicID);
#line 171 "d:/clicks_git/temp-hum_2_click/sw/library/__temphum2_driver.h"
uint8_t temphum2_getQueryDevice();
#line 29 "D:/Clicks_git/Temp-Hum_2_Click/SW/example/c/ARM/STM/Click_TempHum2_STM.c"
char dataText[ 20 ];
float dataBuffer[ 2 ];

void systemInit()
{
 mikrobus_i2cInit( _MIKROBUS1, &_TEMPHUM2_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite( " --- System Init --- ", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 temphum2_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x70 );
 temphum2_setMode(_TEMPHUM2_NO_HOLD_MODE, _TEMPHUM2_NORMAL_MODE);
 temphum2_writeByte(_TEMPHUM2_REG_WRITE_HEATER_CONTROL, _TEMPHUM2_HEATER_ENABLE | _TEMPHUM2_HEATER_CURRENT_6_4mA);
}

void applicationTask()
{
 temphum2_getMeasurement( &dataBuffer[0] );

 mikrobus_logWrite( " --- Temperature : ", _LOG_TEXT);
 FloatToStr( dataBuffer[0] , dataText);
 mikrobus_logWrite(dataText, _LOG_TEXT);
 mikrobus_logWrite( " C", _LOG_LINE);

 mikrobus_logWrite( " --- Humidity : ", _LOG_TEXT);
 FloatToStr( dataBuffer[1] , dataText);
 mikrobus_logWrite(dataText, _LOG_TEXT);
 mikrobus_logWrite( " %RH", _LOG_LINE);

 Delay_ms( 500 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
