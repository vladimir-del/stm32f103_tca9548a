/*
 * tca9548a.c
 *
 *  Created on: Dec 20, 2020
 *      Author: Vladimir Draga
 */

#include "tca9548a.h"
#include "i2c.h"
#include "gpio.h"

/**
  * @brief  Setting control register .
  * @param  Channel: select a Channel to turn on.
			This parametr defined in macros into tca9548.h CH0_EN ... CH7_EN. 
			Can used bool operation. CH0_EN | CH3_EN == 0000 1001 == 0x9
  * @retval hal status.
  */

HAL_StatusTypeDef Tca9548SelectCh(uint8_t Channel)
{
	uint8_t StatusReg = 0x0;
	uint8_t Temp[1] = {Channel};
	HAL_I2C_Master_Transmit(&hi2c1, TCA9548_ADDR << 1, Temp, 1, 100);
	HAL_Delay(50);
	HAL_I2C_Master_Receive(&hi2c1, TCA9548_ADDR << 1, Temp, 1, 100);
	if (StatusReg == Channel)
		return HAL_ERROR;
	else
		return HAL_OK;
	
}

/**
  * @brief  Getting control register .
  *
  * @retval The value of the control register of type uint8_t.
 */

uint8_t Tca9548GetControlReg(void)
{
	uint8_t StatusReg = 0;
	if (HAL_I2C_Master_Receive(&hi2c1, TCA9548_ADDR << 1, &StatusReg, 1, 100) != HAL_OK)
		return HAL_ERROR;
	else
		return StatusReg;
}

/**
  * @brief  Reset control register .
  * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
			GPIOx port configured for this function.
  * @param  GPIO_Pin: GPIO_Pin: specifies the port bit to be toggled.
			Pin configured for this function.
  * @retval hal status.
  */
  
HAL_StatusTypeDef Tca9548ResetInput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	uint8_t StatusReg = 0x0;
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	HAL_Delay(100);
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	
	HAL_I2C_Master_Receive(&hi2c1, TCA9548_ADDR << 1, &StatusReg, 1, 100);
	if (StatusReg == 0x0)
		return HAL_OK;
	else
		return HAL_ERROR;
}
