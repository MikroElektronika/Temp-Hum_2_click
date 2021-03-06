/*
Example for TempHum2 Click

    Date          : apr 2018.
    Author        : Katarina Perendic

Test configuration CEC :
    
    MCU              : CEC1702
    Dev. Board       : Clicker 2 for CEC1702
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init, set work mode and Heater
- Application Task - (code snippet) - Reads temperature and humidity and logs values on usbuart for every 500ms.
*/

#include "Click_TempHum2_types.h"
#include "Click_TempHum2_config.h"

char dataText[ 20 ];
float dataBuffer[ 2 ];

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_TEMPHUM2_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite( " --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    temphum2_i2cDriverInit( (T_TEMPHUM2_P)&_MIKROBUS1_GPIO, (T_TEMPHUM2_P)&_MIKROBUS1_I2C, 0x70 );
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