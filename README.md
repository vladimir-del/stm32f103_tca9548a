# stm32f103_tca9548a #

Connection NUCLEO-F103RB to TCA9548A using I2C protocol.
---
***
The Project was created in STM32CubeMX IDE v. 1.5.1

HAL Driver version number V1.1.7

*I2C configured to channel 1.*
*Reset pin configured to pin A0 CN8 Extention connector8*
In case of detection the fail, uses function _Send_err_uart()_. It sends error text to UART2 port. 
