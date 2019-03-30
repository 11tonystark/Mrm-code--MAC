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


       		TIM_SetCompare1(TIM16,2700); // pa6
        	TIM_SetCompare1(TIM17,2700); //pa7



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



	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16, ENABLE);

	// Pin configuration of PWM

	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_7|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);




	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_1);



	TIM_TimeBaseStructure.TIM_Period = 4800-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM16, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM17, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4799;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM16, &TIM_OCInitStructure);
	TIM_OC1Init(TIM17, &TIM_OCInitStructure);


	//enable the PWM output
	TIM_CtrlPWMOutputs(TIM16, ENABLE);
	TIM_Cmd(TIM16, ENABLE);


	TIM_SetCompare1(TIM16, 0);

	TIM_CtrlPWMOutputs(TIM17, ENABLE);
	TIM_Cmd(TIM17, ENABLE);

	TIM_SetCompare1(TIM17, 0);




}
