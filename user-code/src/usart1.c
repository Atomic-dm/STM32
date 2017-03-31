#include "main.h"

void usart1_ini(void)
{
	
	USART_InitTypeDef USART1_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//USART_InitStruct USART1_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE);
	
	USART1_InitStructure.USART_BaudRate=19200;
	USART1_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART1_InitStructure.USART_StopBits=USART_StopBits_1 ;
	USART1_InitStructure.USART_Parity=USART_Parity_No;
	USART1_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART1_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	
	USART_Init(USART1, &USART1_InitStructure);
  USART_Cmd(USART1, ENABLE);
	
	NVIC_EnableIRQ (USART1_IRQn);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
}

void usart2_ini(void)
{
	
	USART_InitTypeDef USART2_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//USART_InitStruct USART1_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                     // TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                     //RX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);
	
	USART2_InitStructure.USART_BaudRate=10400;
	USART2_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART2_InitStructure.USART_StopBits=USART_StopBits_1 ;
	USART2_InitStructure.USART_Parity=USART_Parity_No;
	USART2_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART2_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//	USART_StructInit( &USART1_InitStructure);
	
	USART_Init(USART2, &USART2_InitStructure);
  USART_Cmd(USART2, ENABLE);
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
//	USART_ITConfig(USART2,USART_IT_TXE,ENABLE);
	NVIC_EnableIRQ (USART2_IRQn);
	
	
}

void usart3_ini(void)
{
	
	USART_InitTypeDef USART3_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//USART_InitStruct USART1_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                     // TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;                     //RX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3 , ENABLE);
	
	USART3_InitStructure.USART_BaudRate=10400;
	USART3_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART3_InitStructure.USART_StopBits=USART_StopBits_1 ;
	USART3_InitStructure.USART_Parity=USART_Parity_No;
	USART3_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART3_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//	USART_StructInit( &USART1_InitStructure);
	
	USART_Init(USART3, &USART3_InitStructure);
  USART_Cmd(USART3, ENABLE);
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
//	USART_ITConfig(USART2,USART_IT_TXE,ENABLE);
	NVIC_EnableIRQ (USART3_IRQn);
	
	
}

void SendStrtoPC(USART_TypeDef* USARTx,char* str_p)
	{
		uint16_t i=0;
	//	USART_ITConfig(USART2,USART_IT_RXNE,DISABLE);
		while(str_p[i] !=0)
		{ 
			while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==!SET){}
			USART_SendData(USARTx,str_p[i]);
			i++;
		}
  //	delay_ms(30);
		USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	}
	
void SendBytetoPC(USART_TypeDef* USARTx,char buffer[],uint16_t Send_count)
	{
				USART_SendData(USARTx,buffer[Send_count]);
				Send_count++;
				USART_ITConfig(USARTx,USART_IT_TXE,ENABLE);
			}
