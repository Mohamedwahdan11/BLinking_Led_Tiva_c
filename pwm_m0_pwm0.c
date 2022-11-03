/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  pwm_m0_pwm0.c
 *        \brief   Source file for the tiva-c pwm 0 module 0 driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/




#include "Std_Types.h"
#include "tm4c123gh6pm.h"
#include "pwm_m0_pwm0.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /******************************************************************************
* \Syntax          : PWM_M0_PWM0_init(uint8 duty)        
* \Description     : this function is to initialize the Module 0 PWM0 channel A .                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Duty               the initialize duty cycle                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PWM_M0_PWM0_init(uint8 duty)
{
    int i=0;
    /*Set The Clock To The PWM And GPIO*/
    SET_BIT(SYSCTL_RCGC0_R,20); 
	  SYSCTL_RCGCPWM_R=0x02;
	
	for(i=0;i<4;i++);
	
    SYSCTL_RCGC2_R|=0x0003F;
	SYSCTL_RCGCGPIO_R|=0X0003F;

    for(i=0;i<4;i++);
    /*Select pin 6 in port b as pwm output*/
    GPIO_PORTB_LOCK_R=0x4C4F434B;
    SET_BIT(GPIO_PORTB_CR_R,6);
    SET_BIT(GPIO_PORTB_AFSEL_R,6); 
    GPIO_PORTB_PCTL_R=(GPIO_PORTB_PCTL_R & 0xF0FFFFFF)|0X04000000;
    SET_BIT(GPIO_PORTB_DEN_R,6);

    /*activate the clock soucre divider and divide it by 2 where the ententerd
    frq. is 12 MHz to the sustem so the PWM clock will be 6 MHz  */
    
    SET_BIT(SYSCTL_RCC_R,20);
    SYSCTL_RCC_R=(SYSCTL_RCC_R & 0xFFF0FFFF)|0X00000000;

    /*configure the PWM */
    PWM0_0_CTL_R=0x000000000;
    PWM0_0_GENA_R=0x0000008C;

    /*Set the  PWM to be work with 25KHz
    the system work with 12 MHz after clock divition clock equal 6 MHz
    so to get 25 KHz we need 240-1 tick*/

    PWM0_0_LOAD_R=240-1;
    /*Set the intial duty cyle*/
    PWM_M0_PWM0_set_duty_cycle(duty );
    /*start the timer*/
    PWM0_0_CTL_R=0x00000001;

    PWM_M0_PWM0_start();


}

/******************************************************************************
* \Syntax          : PWM_M0_PWM0_init(uint8 duty)        
* \Description     : this function is to set the duty cycle the Module 0 PWM0 channel A .                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Duty               the  duty cycle                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


void PWM_M0_PWM0_set_duty_cycle(uint8 duty )
{
    PWM0_0_CMPA_R=(240*(duty/100))-1;
}

/******************************************************************************
* \Syntax          : PWM_M0_PWM0_init(uint8 duty)        
* \Description     : this function is to start the Module 0 PWM0 channel A .                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PWM_M0_PWM0_start(void)
{
    SET_BIT(PWM0_ENABLE_R,0);
}
/******************************************************************************
* \Syntax          : PWM_M0_PWM0_init(uint8 duty)        
* \Description     : this function is to stop the Module 0 PWM0 channel A .                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PWM_M0_PWM0_stop(void)
{
    CLEAR_BIT(PWM0_ENABLE_R,0);
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
