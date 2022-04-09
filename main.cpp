#include "stm32f10x.h"
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <stddef.h>
#include <set>



// telegram id --->    @eneeir
// github --->  https://github.com/embeddedsystemdesigner
// website  ---> www.enee.ir




using namespace std;

void delay_us(unsigned int time);
void delay_ms(unsigned int time);
void GPIO_INIT(void);


set<int> num1;
set<int>num2;


set<int>::iterator count;


class flasher
{
	public:
	unsigned int speed;
  void GPIO_CONFIG(void);
	void set(void);
	void reset(void);
	void flash(void){ set();  delay_ms(speed);    reset();  delay_ms(speed); }
};



int main (void)
{

flasher flash;


for(int c=0; c<10; c++)
	num1.insert(c);
	
	
num1.insert(30);
num1.insert(40);	
num1.insert(50);	
	
for(int i=5; i<20; i++)
 num1.insert(i);


for(count = num1.begin();  count!= num1.end(); count++)
	cout<<*count<<endl;
	
	
cout<<"the numer is found is:"<<*num1.find(60)<<endl;	// if find return the value and if does not return 0



cout<<"*****************************"<<endl;


num1.erase(1);// delete the value from set
num1.erase(2);


for(count = num1.begin();  count!= num1.end(); count++)
	cout<<*count<<endl;


flash.GPIO_CONFIG();
flash.speed=300;

while(1)
{
	
flash.flash();	

}


	
	
}

















void flasher::set(void)
{

GPIO_SetBits(GPIOF,GPIO_Pin_4);	
	
}



void flasher::reset(void)
{
	
GPIO_ResetBits(GPIOF,GPIO_Pin_4);	
	
}






void flasher::GPIO_CONFIG(void)
{

GPIO_InitTypeDef GPIO;
	
	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);	

	
GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO.GPIO_Pin = GPIO_Pin_4;
GPIO.GPIO_Speed = GPIO_Speed_2MHz;

GPIO_Init(GPIOF,&GPIO);		
	
}



void delay_us(unsigned int time)
{
	
	while(time--)	
		{
			
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();	
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();	
    __NOP();__NOP();	

		}
	
}




void delay_ms(unsigned int time)
{
	
	while(time--)	
		{
			
delay_us(1000);
			
		}

}



