/*
 * tca9548a.c
 *
 *  Created on: Dec 20, 2020
 *      Author: Vladimir Draga
 */

#include "tca9548a.h"
#include "i2c.h"
#include "gpio.h"

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
