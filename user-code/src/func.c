#include "main.h"

__IO uint16_t delay_count;

void SysTick_Handler(void) //1ms
{
	
	

	if (delay_count>0)
	{		delay_count--;	}	
	
}

void delay_ms(uint16_t delay_temp)
{
	//disk_timerproc();   /* Disk timer process */
	delay_count=delay_temp;
	while (delay_count) {}
	
}

void pin_ini(void)
{ uint8_t i=6;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; ;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	
	
	while (i>0){
	delay_ms(100);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delay_ms(50);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	i--;
	}
}

