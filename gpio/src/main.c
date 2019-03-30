#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#include <stm32f30x_gpio.h>

int main(void)
{

	//Enable clock for GPIOE

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

	// Initialization of GPIO PORTE PIN 13
	GPIO_Init(GPIOB,&GPIO_InitStruct);

    while(1)
    {

   GPIO_ResetBits(GPIOB,GPIO_Pin_2);
   GPIO_ResetBits(GPIOB,GPIO_Pin_3);

    }
}
