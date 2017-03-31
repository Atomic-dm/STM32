#ifndef MAIN_H
#define MAIN_H

#include "stm32f10x.h"


#include "diskio.h"
#include "ff.h"



void SysTick_Handler(void) ;//1ms
void delay_ms(uint16_t delay_temp);
void pin_ini(void);
void timer_ini(void);
extern void disk_timerproc (void);


#endif

