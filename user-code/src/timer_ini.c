#include "main.h"

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
	{
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	
		disk_timerproc(); /* Disk timer process */	
		
	}
	
}

void timer_ini(void)
{	
TIM_TimeBaseInitTypeDef TIM_Time_user;	
	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  // 
	TIM_Time_user.TIM_ClockDivision=TIM_CKD_DIV1 ;
	TIM_Time_user.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_Time_user.TIM_Period=10;
	TIM_Time_user.TIM_Prescaler=36000-1;
	TIM_TimeBaseInit(TIM2,&TIM_Time_user);
	
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE); 
	TIM_Cmd(TIM2, ENABLE);
}

