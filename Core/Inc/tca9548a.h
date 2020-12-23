/*
 * tca9548a.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Vladimir Draga
 */

#ifndef INC_TCA9548A_H_
#define INC_TCA9548A_H_

#ifdef __cplusplus
extern "C" {
#endif

#include  "main.h"

#define TCA9548_ADDR 0x70

#define CH0_EN 0x1
#define CH1_EN 0x2
#define CH2_EN 0x4
#define CH3_EN 0x8
#define CH4_EN 0x10
#define CH5_EN 0x20
#define CH6_EN 0x40
#define CH7_EN 0x80


HAL_StatusTypeDef SelectCh(uint8_t channel);

void Reset_TCA9548(void);

#endif /* INC_TCA9548A_H_ */
