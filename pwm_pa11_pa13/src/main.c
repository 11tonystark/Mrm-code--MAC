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


    		TIM_SetCompare3(TIM4, 2700);

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

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	// Pin configuration of PWM

	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource13, GPIO_AF_10);


	TIM_TimeBaseStructure.TIM_Period = 4800-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);


	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4799;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);

	//enable the PWM output
	TIM_CtrlPWMOutputs(TIM4, ENABLE);
	TIM_Cmd(TIM4, ENABLE);


	TIM_SetCompare3(TIM4, 0);

}
