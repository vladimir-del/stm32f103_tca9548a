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
  * @param  channel: select a channel to turn on.
			This parametr defined in macros into tca9548.h CH0_EN ... CH7_EN. 
			Can used bool operation. CH0_EN | CH7_EN == 1000 0001
  * @retval hal status.
  */

HAL_StatusTypeDef Tca9548SelectCh(uint8_t channel)
{
	uint8_t StatusReg = 0;
	HAL_I2C_Mem_Write(&hi2c1, TCA9548_ADDR << 1, channel, I2C_MEMADD_SIZE_8BIT, (void*)0, 0, 100)
	
	HAL_I2C_Mem_Read(&hi2c1, TCA9548_ADDR << 1, channel, I2C_MEMADD_SIZE_8BIT, StatusReg, 0, 100)
	
	if (StatusReg == channel)
		return HAL_ERROR;
	else 
		return HAL_OK;
	
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
	uint8_t StatusReg = 0;
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	HAL_Delay(10);
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	
	HAL_I2C_Mem_Read(&hi2c1, TCA9548_ADDR << 1, channel, I2C_MEMADD_SIZE_8BIT, StatusReg, 0, 100)
	if (StatusReg == 0x0)
		return HAL_OK;
	else
		return HAL_ERROR;
}

/**
  * @brief  Reset control register .
  * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
			GPIOx port configured for this function.
  * @param  GPIO_Pin: GPIO_Pin: specifies the port bit to be toggled.
			Pin configured for this function.
  * @retval hal status.
  */
  
HAL_StatusTypeDef Tca9548ResetPOR(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	HAL_Delay(10);
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	
	HAL_I2C_Mem_Read(&hi2c1, TCA9548_ADDR << 1, channel, I2C_MEMADD_SIZE_8BIT, StatusReg, 0, 100)
	if (StatusReg == 0x0)
		return HAL_OK;
	else
		return HAL_ERROR;
}
