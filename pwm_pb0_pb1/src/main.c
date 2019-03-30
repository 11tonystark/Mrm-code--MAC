#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#include <stm32f30x_gpio.h>
#include "stm32f30x_tim.h"

/* #function prototypes goes here ---------- */
void PWM_Init(void);




int main(void)
{
	PWM_Init();

    while(1)
    {
    	TIM_SetCompare3(TIM3, 2200); //PB0
    	TIM_SetCompare4(TIM3, 2200); //PB1

    }
}


void PWM_Init(void)
{

	//structure for GPIO setup
	GPIO_InitTypeDef            GPIO_InitStructure;
	//structure for TIM Time Base
	TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
	//structure for TIM Output Compare
	TIM_OCInitTypeDef			TIM_OCInitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// Pin configuration of PWM

	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_2);

	TIM_TimeBaseStructure.TIM_Period = 4800-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4799;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);

	//enable the PWM output
	TIM_CtrlPWMOutputs(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);

	TIM_SetCompare3(TIM3, 0);
	TIM_SetCompare4(TIM3, 0);

}
