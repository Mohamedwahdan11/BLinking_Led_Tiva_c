
#include "gpio.h"
#include "seven_segma.h"
#include "systick.h"
#include "interrupt.h"
#include "pwm_m0_pwm0.h"



/*variable count used to count the number of seconds  */
static uint8 count=0;
/*variable flag used to indicate which period as it is off or on*/
static uint8 count_flag=0;
/*the off time in seconds*/
static uint8 off_Time=0;
/*the on time in second*/
static uint8 on_Time=0;


void toggle(void);






int main(void)
{
	
	 /*set pin 0 port c as output pin for led*/
	 Pin_Config portF_pin0 ={PIN1_ID,PORTF_ID,PIN_OUTPUT};
	 /*set pin 1 port c as input pin for botton 1 */
	 Pin_Config portF_pin1 ={PIN4_ID,PORTF_ID,PIN_INPUT};
	 /*set pin 1 port c as input pin for botton 2 */
	 Pin_Config portF_pin2 ={PIN0_ID,PORTF_ID,PIN_INPUT};
	
	uint8 flag=1;
	uint8 botton_flag_1=0;
	uint8 botton_flag_2=0;

	 /*setup the output/input pins*/
	 GPIO_setupPinDirection(&portF_pin0);
	 GPIO_setupPinDirection(&portF_pin1);
	 GPIO_setupPinDirection(&portF_pin2);
	 
	  /*setup the seven segma*/
	SEVEN_SEGMA_init(SIGAM_1 );
	SEVEN_SEGMA_init(SIGAM_2 );
	
	/*setup the callback function*/
	SYSTICK_setCallBack(toggle);
	

	while(1)
	{
		
		if(GPIO_readPin(PORTF_ID,PIN4_ID))
		{
			if(botton_flag_1==0)
			{
				on_Time++;
				botton_flag_1=1;
			}
		}
		else
		{
			botton_flag_1=0;
		}
		
		
		
		if(GPIO_readPin(PORTF_ID,PIN0_ID))
		{
			if(botton_flag_2==0)
			{
				off_Time++;
				botton_flag_2=1;
			}
		}
		else
		{
			botton_flag_2=0;
		}
		
		
		
		if(on_Time>9)
		{
			on_Time=0;
		}
		if(off_Time>9)
		{
			off_Time=0;
		}
				
			SEVEN_SEGMA_write_value(SIGAM_1, off_Time);
			SEVEN_SEGMA_write_value(SIGAM_2, on_Time);
		
		if((on_Time!=0)&&(off_Time!=0)&&(flag!=0))
		{
			GPIO_writePin(PORTF_ID,PIN1_ID,STD_HIGH);
			/*PWM_M0_PWM0_init(100);*/
			flag=0;
			count_flag=0;
			count=on_Time;
			SYSTICK_init(12000000);
		}
		else if((on_Time!=0)&&(off_Time==0))
		{
			GPIO_writePin(PORTF_ID,PIN1_ID,STD_HIGH);
			/*PWM_M0_PWM0_init(100);*/
			flag=1;
			SYSTICK_deinit();
		}
		else if((on_Time==0)&&(off_Time!=0))
		{
			GPIO_writePin(PORTF_ID,PIN1_ID,STD_LOW);
			/*PWM_M0_PWM0_init(25);*/
			flag=1;
			SYSTICK_deinit();
		}
		else if((on_Time==0)&&(off_Time==0))
		{
			GPIO_writePin(PORTF_ID,PIN1_ID,STD_LOW);
			/*PWM_M0_PWM0_init(0);*/
			flag=1;
			SYSTICK_deinit();
		}
				
				
	}
	
	return 0;
}

void toggle(void)
{
	count--;
	if((count==0)&&(count_flag==0))
	{
		GPIO_writePin(PORTF_ID,PIN1_ID,STD_LOW);
		/*PWM_M0_PWM0_init(25);*/
		count=off_Time;
		count_flag=1;
	}
	else if((count==0)&&(count_flag==1))
	{
		GPIO_writePin(PORTF_ID,PIN1_ID,STD_HIGH);
		/*PWM_M0_PWM0_init(100);*/
		count=on_Time;
		count_flag=0;
	}
}
