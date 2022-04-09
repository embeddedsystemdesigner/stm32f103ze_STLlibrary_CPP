#include <stm32f10x.h>
#include "usart.h"
#include <stdio.h>


// telegram id --->    @eneeir
// github --->  https://github.com/embeddedsystemdesigner
// website  ---> www.enee.ir

volatile uint32_t msTicks;             



void SysTick_Handler(void)
{
  msTicks++;
}
//////////////////////////////////////////////////////////////////////




void Delay (uint32_t dlyTicks)
{                                              

  msTicks=0;
  while (msTicks< dlyTicks);
	
}
//////////////////////////////////////////////////////////////////////






int main(void)
{
	
usart2_init(9600);

SystemCoreClockUpdate(); 

if (SysTick_Config(SystemCoreClock / 1000))     /* SysTick 1 msec interrupts  */
{ 
while (1);                         
}

	
	
	
while(1)
{


usart2_puts("if you see this message so the usart is working good\r\n");	
Delay(1000);
	
	

}



	
}

