#include "main.h"




int  main(void) {


__IO uint16_t i=0;
	
SystemCoreClockUpdate();
SysTick_Config(SystemCoreClock/1000);	

//fff/ comment  ww
pin_ini();	

	while(1)
	{
	i++;
	delay_ms(1000);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delay_ms(1000);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
		
	}	
}


