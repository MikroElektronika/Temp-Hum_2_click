/*
    __temphum2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__temphum2_driver.h"
#include "__temphum2_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */
const uint16_t _TEMPHUM2_REG_FIRMWARE_REVISION = 0x84F1;
const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_1   = 0xFA0F;
const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_2   = 0xFCC9;
const uint8_t  _TEMPHUM2_REG_SOFT_RESET        = 0xFE;
const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_NORMAL_MODE  = 0x7CA2;
const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE = 0x7866;
const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_FAST_MODE    = 0x6458;
const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_FAST_MODE   = 0x609C;
const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP       = 0xEFC8;
const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP1      = 0x805D;
const uint8_t _TEMPHUM2_REG_WRITE_HEATER_CONTROL = 0xE6;
const uint8_t _TEMPHUM2_REG_READ_HEATER_CONTROL = 0xE7;

/* QUERY Device flag */
const uint8_t _QUERY_DEVICE_ERROR = 1;
const uint8_t _QUERY_DEVICE_OK = 0;

/* Heater Control Register */
const uint8_t _TEMPHUM2_HEATER_ENABLE  = 0x10;
const uint8_t _TEMPHUM2_HEATER_DISABLE = 0x00;
const uint8_t _TEMPHUM2_HEATER_CURRENT_6_4mA  = 0x00;
const uint8_t _TEMPHUM2_HEATER_CURRENT_9_7mA  = 0x01;
const uint8_t _TEMPHUM2_HEATER_CURRENT_13_1mA = 0x02;
const uint8_t _TEMPHUM2_HEATER_CURRENT_19_6mA = 0x04;
const uint8_t _TEMPHUM2_HEATER_CURRENT_32_4mA = 0x08;
const uint8_t _TEMPHUM2_HEATER_CURRENT_53_5mA = 0x0F;

/* MODE */
const uint8_t _TEMPHUM2_NO_HOLD_MODE = 0x01;
const uint8_t _TEMPHUM2_HOLD_MODE    = 0x02;
const uint8_t _TEMPHUM2_NORMAL_MODE  = 0x01;
const uint8_t _TEMPHUM2_FAST_MODE    = 0x01;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __TEMPHUM2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t _speedMode = _TEMPHUM2_NORMAL_MODE;
static uint8_t _selectMode = _TEMPHUM2_NO_HOLD_MODE;
static uint16_t _dataRegister = _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __TEMPHUM2_DRV_SPI__

void temphum2_spiDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __TEMPHUM2_DRV_I2C__

void temphum2_i2cDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __TEMPHUM2_DRV_UART__

void temphum2_uartDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void temphum2_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t temphum2_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);
    
    return readReg[ 0 ];
}

uint8_t temphum2_readFirmwareRevision()
{
    uint8_t writeReg[ 2 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = (_TEMPHUM2_REG_FIRMWARE_REVISION >> 8) & 0x00FF;;
    writeReg[ 1 ] = _TEMPHUM2_REG_FIRMWARE_REVISION & 0x00FF;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);
    
    return readReg[ 0 ];
}

void temhum2_getEletronicID(uint8_t *electronicID)
{
    uint8_t writeReg[ 2 ];
    uint8_t readSNAReg[ 8 ];
    uint8_t readSNBReg[ 6 ];
    
    writeReg[ 0 ] = (_TEMPHUM2_REG_ELECTRONIC_ID_1 >> 8) & 0x00FF;
    writeReg[ 1 ] = _TEMPHUM2_REG_ELECTRONIC_ID_1 & 0x00FF;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readSNAReg, 8, END_MODE_STOP);
    
    electronicID[ 0 ] = readSNAReg[ 0 ];
    electronicID[ 1 ] = readSNAReg[ 2 ];
    electronicID[ 2 ] = readSNAReg[ 4 ];
    electronicID[ 3 ] = readSNAReg[ 6 ];
    
    writeReg[ 0 ] = (_TEMPHUM2_REG_ELECTRONIC_ID_2 >> 8) & 0x00FF;
    writeReg[ 1 ] = _TEMPHUM2_REG_ELECTRONIC_ID_2 & 0x00FF;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readSNBReg, 6, END_MODE_STOP);
    
    electronicID[ 4 ] = readSNBReg[ 0 ];
    electronicID[ 5 ] = readSNBReg[ 1 ];
    electronicID[ 6 ] = readSNBReg[ 3 ];
    electronicID[ 7 ] = readSNBReg[ 4 ];
}

uint8_t temphum2_getQueryDevice()
{
    uint8_t writeReg[ 2 ];
    uint8_t readReg[ 3 ];
    volatile uint32_t readData;
    
    writeReg[ 0 ] = (_TEMPHUM2_REG_QUERY_DEVICE_RESP >> 8) & 0x00FF;
    writeReg[ 1 ] =  _TEMPHUM2_REG_QUERY_DEVICE_RESP & 0x00FF;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_RESTART );
    hal_i2cRead(_slaveAddress, readReg, 3, END_MODE_STOP);

    readData = readReg[ 0 ];
    readData = readData << 8;
    readData = readData | readReg[ 1 ];
    readData = readData << 8;
    readData = readData | readReg[ 2 ];
    
    if (readData == 0x0000472B)
    {
        return _QUERY_DEVICE_OK;
    }
    else
    {
        return _QUERY_DEVICE_ERROR;
    }
}

void temphum2_setMode(uint8_t selectMode, uint8_t speedMode)
{
    _speedMode = speedMode;
    _selectMode = selectMode;
    
    if ((_speedMode == _TEMPHUM2_NORMAL_MODE) && (_selectMode == _TEMPHUM2_HOLD_MODE))
    {
        _dataRegister = _TEMPHUM2_REG_TEMPHUM_HM_NORMAL_MODE;
    }
    else if ((_speedMode == _TEMPHUM2_NORMAL_MODE) && (_selectMode == _TEMPHUM2_NO_HOLD_MODE))
    {
        _dataRegister = _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE;
    }
    else if ((_speedMode == _TEMPHUM2_FAST_MODE) && (_selectMode == _TEMPHUM2_HOLD_MODE))
    {
        _dataRegister = _TEMPHUM2_REG_TEMPHUM_HM_FAST_MODE;
    }
    else if ((_speedMode == _TEMPHUM2_FAST_MODE) && (_selectMode == _TEMPHUM2_NO_HOLD_MODE))
    {
        _dataRegister = _TEMPHUM2_REG_TEMPHUM_NHM_FAST_MODE;
    }
    else
    {
        _dataRegister = _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE;
    }
}

void temphum2_getMeasurement( float *dataBuffer )
{
    uint8_t writeReg[ 2 ];
    uint8_t readReg[ 6 ];
    uint16_t iTempData;
    uint16_t iHumData;
    float fHumData;
    float fTempData;
    
    writeReg[ 0 ] = (_dataRegister >> 8) & 0x00FF;
    writeReg[ 1 ] = (_dataRegister & 0x00FF);
    
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 2, END_MODE_RESTART);
    Delay_100ms();
    hal_i2cRead( _slaveAddress, readReg, 6, END_MODE_STOP);

    // Temperature
    iTempData = readReg[ 0 ];
    iTempData = iTempData << 8;
    iTempData = iTempData | readReg[ 1 ];
    
    fTempData = -45.0 + 175.0 * (iTempData / 65535.0);
    
    iHumData = readReg[ 3 ];
    iHumData = iHumData << 8;
    iHumData = iHumData | readReg[ 4 ];
    
    fHumData = 100.0 * ( iHumData / 65535.0);
    
    dataBuffer[ 0 ] = fTempData;
    dataBuffer[ 1 ] = fHumData;
}








/* -------------------------------------------------------------------------- */
/*
  __temphum2_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */