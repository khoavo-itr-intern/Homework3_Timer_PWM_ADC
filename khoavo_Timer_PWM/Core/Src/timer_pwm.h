#ifndef __TIMER_PWM_H__
#define __TIMER_PWM_H__

/*
 * timer_pwm.h
 * _TIM_: ex : &htim1
 * CHANNEL: ex : CH1
 * _PRESCALER_: bo chia tan
 * _MAX_: gia tri count max
 * _VAR_: do rong xung: 0-100%
 *
 */

#include "main.h"

#define CH1		TIM_CHANNEL_1
#define CH2		TIM_CHANNEL_2
#define CH3		TIM_CHANNEL_3
#define CH4		TIM_CHANNEL_4

#define PWM_Get(_TIM_,CHANNEL)				__HAL_TIM_GET_COMPARE(_TIM_,CHANNEL)
#define PWM_Start(_TIM_,CHANNEL)			HAL_TIM_PWM_Start(_TIM_,CHANNEL)
#define TIM_Set(_TIM_,_PRESCALER_,_MAX_)	PWM_Set(_TIM_,_PRESCALER_,_MAX_)
#define TIM_Get(_TIM_,CHANNEL)				__HAL_TIM_SET_COUNTER(_TIM_,CHANNEL)

void TIM_Set(TIM_HandleTypeDef* _TIM_,uint32_t _PRESCALER_, uint32_t _PERIOD_)
{
	__HAL_TIM_SET_AUTORELOAD(_TIM_,_PERIOD_);
	__HAL_TIM_SET_PRESCALER(_TIM_,_PRESCALER_);
}

uint16_t PWM_Write(TIM_HandleTypeDef* __HANDLE__,uint32_t CHANNEL,uint8_t _VAR_)
{
	uint16_t COMPARE = (((__HANDLE__)->Instance->ARR/100)*(_VAR_));
	__HAL_TIM_SET_COMPARE(__HANDLE__,CHANNEL,COMPARE);
	return COMPARE;

}

#endif



#ifndef SRC_TIMER_PWM_H_
#define SRC_TIMER_PWM_H_



#endif /* SRC_TIMER_PWM_H_ */
