/*
    __temphum2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __temphum2_driver.h
@brief    TempHum2 Driver
@mainpage TempHum2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   TEMPHUM2
@brief      TempHum2 Click Driver
@{

| Global Library Prefix | **TEMPHUM2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **apr 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _TEMPHUM2_H_
#define _TEMPHUM2_H_

/** 
 * @macro T_TEMPHUM2_P
 * @brief Driver Abstract type 
 */
#define T_TEMPHUM2_P    const uint8_t*

/** @defgroup TEMPHUM2_COMPILE Compilation Config */              /** @{ */

//  #define   __TEMPHUM2_DRV_SPI__                            /**<     @macro __TEMPHUM2_DRV_SPI__  @brief SPI driver selector */
   #define   __TEMPHUM2_DRV_I2C__                            /**<     @macro __TEMPHUM2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __TEMPHUM2_DRV_UART__                           /**<     @macro __TEMPHUM2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup TEMPHUM2_VAR Variables */                           /** @{ */

/* Register */
extern const uint16_t _TEMPHUM2_REG_FIRMWARE_REVISION;
extern const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_1;
extern const uint16_t _TEMPHUM2_REG_ELECTRONIC_ID_2;
extern const uint8_t  _TEMPHUM2_REG_SOFT_RESET;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_NORMAL_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_NORMAL_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_HM_FAST_MODE;
extern const uint16_t _TEMPHUM2_REG_TEMPHUM_NHM_FAST_MODE;
extern const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP;
extern const uint16_t _TEMPHUM2_REG_QUERY_DEVICE_RESP1;
extern const uint8_t _TEMPHUM2_REG_WRITE_HEATER_CONTROL;
extern const uint8_t _TEMPHUM2_REG_READ_HEATER_CONTROL;

/* QUERY Device flag */
extern const uint8_t _QUERY_DEVICE_ERROR;
extern const uint8_t _QUERY_DEVICE_OK;

/* Heater Control Register */
extern const uint8_t _TEMPHUM2_HEATER_ENABLE;
extern const uint8_t _TEMPHUM2_HEATER_DISABLE;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_6_4mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_9_7mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_13_1mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_19_6mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_32_4mA;
extern const uint8_t _TEMPHUM2_HEATER_CURRENT_53_5mA;

/* MODE */
extern const uint8_t _TEMPHUM2_NO_HOLD_MODE;
extern const uint8_t _TEMPHUM2_HOLD_MODE;
extern const uint8_t _TEMPHUM2_NORMAL_MODE;
extern const uint8_t _TEMPHUM2_FAST_MODE;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup TEMPHUM2_INIT Driver Initialization */              /** @{ */

#ifdef   __TEMPHUM2_DRV_SPI__
void temphum2_spiDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P spiObj);
#endif
#ifdef   __TEMPHUM2_DRV_I2C__
void temphum2_i2cDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P i2cObj, uint8_t slave);
#endif
#ifdef   __TEMPHUM2_DRV_UART__
void temphum2_uartDriverInit(T_TEMPHUM2_P gpioObj, T_TEMPHUM2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void temphum2_gpioDriverInit(T_TEMPHUM2_P gpioObj);
                                                                       /** @} */
/** @defgroup TEMPHUM2_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void temphum2_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] reg    Register in which the data will be written
 * @retval one byte data which is read from the register
 */
uint8_t temphum2_readByte(uint8_t reg);

/**
 * @brief Functions for set measurement mode
 *
 * @param[in] selectMode  _TEMPHUM2_NO_HOLD_MODE(default) or _TEMPHUM2_HOLD_MODE
 * @param[in] speendMode  _TEMPHUM2_NORMAL_MODE(default) or _TEMPHUM2_FAST_MODE
 */
void temphum2_setMode(uint8_t selectMode, uint8_t speedMode);

/**
 * @brief Functions for mesurement
 *
 * @param[out] dataBuffer  buffer that will be written Temperature and Humidity data
 *
 * Data:
     dataBuffer[0] - Temperature
     dataBuffer[1] - Humidity
 */
void temphum2_getMeasurement( float *dataBuffer );


/**
 * @brief This function for reads Firmware Revision
 *
 * @return Firmware Revision ( 0x10 = Firmware version 1.0 )
 */
uint8_t temphum2_readFirmwareRevision();

/**
 * @brief This function for reads Eletronic ID
 *
 * @param[ out ] electronicID  buffer that will be written 8 elements Eletronic ID
 */
void temhum2_getEletronicID(uint8_t *electronicID);

/**
 * @brief This function for reads Query Device
 *
 * @return _QUERY_DEVICE_OK - if the read the response is 0x00 0x47 0x2B
           _QUERY_DEVICE_ERROR - if the read data is not good
 */
uint8_t temphum2_getQueryDevice();


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_TempHum2_STM.c
    @example Click_TempHum2_TIVA.c
    @example Click_TempHum2_CEC.c
    @example Click_TempHum2_KINETIS.c
    @example Click_TempHum2_MSP.c
    @example Click_TempHum2_PIC.c
    @example Click_TempHum2_PIC32.c
    @example Click_TempHum2_DSPIC.c
    @example Click_TempHum2_AVR.c
    @example Click_TempHum2_FT90x.c
    @example Click_TempHum2_STM.mbas
    @example Click_TempHum2_TIVA.mbas
    @example Click_TempHum2_CEC.mbas
    @example Click_TempHum2_KINETIS.mbas
    @example Click_TempHum2_MSP.mbas
    @example Click_TempHum2_PIC.mbas
    @example Click_TempHum2_PIC32.mbas
    @example Click_TempHum2_DSPIC.mbas
    @example Click_TempHum2_AVR.mbas
    @example Click_TempHum2_FT90x.mbas
    @example Click_TempHum2_STM.mpas
    @example Click_TempHum2_TIVA.mpas
    @example Click_TempHum2_CEC.mpas
    @example Click_TempHum2_KINETIS.mpas
    @example Click_TempHum2_MSP.mpas
    @example Click_TempHum2_PIC.mpas
    @example Click_TempHum2_PIC32.mpas
    @example Click_TempHum2_DSPIC.mpas
    @example Click_TempHum2_AVR.mpas
    @example Click_TempHum2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __temphum2_driver.h

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