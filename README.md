![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# TempHum2 Click

- **CIC Prefix**  : TEMPHUM2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : apr 2018.

---

### Software Support

We provide a library for the TempHum2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2409/temp-amp-hum-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function for reads query device, eletronic ID, firmware revision, temperature and humidity data.
The user can select the measurement mode and set the Heater.

Key functions :

- ``` void temphum2_setMode(uint8_t selectMode, uint8_t speedMode) ``` - Functions for set measurement mode
- ``` void temphum2_getMeasurement( float *dataBuffer ) ``` - Functions for mesurement 
- ``` void temphum2_writeByte(uint8_t reg, uint8_t _data) ``` - Functions for write one byte in register

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init, set work mode and Heater
- Application Task - (code snippet) - Reads temperature and humidity and logs values on usbuart for every 500ms.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2409/temp-amp-hum-2-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
