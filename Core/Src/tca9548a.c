/*
 * tca9548a.c
 *
 *  Created on: Dec 20, 2020
 *      Author: Vladimir Draga
 */

#include "tca9548a.h"
#include "i2c.h"

HAL_StatusTypeDef SelectCh(uint8_t channel)
{
	if (HAL_I2C_Mem_Write(&hi2c1, TCA9548_ADDR << 1, channel, I2C_MEMADD_SIZE_8BIT, (void*)0, 0, 100) != HAL_OK)
		return HAL_ERROR;
	else
		return HAL_OK;
}


void Reset_TCA9548(void)
{
	HAL_GPIO_TogglePin(Reset_TCA9548_GPIO_Port, Reset_TCA9548_Pin);
	HAL_Delay(10);
	HAL_GPIO_TogglePin(Reset_TCA9548_GPIO_Port, Reset_TCA9548_Pin);
}
