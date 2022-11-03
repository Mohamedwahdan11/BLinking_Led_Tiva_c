/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  interrupt.c
 *        \brief   Source file for the tiva-c interrupt driver
 *
 *      \details  this module is use set the interrupt enable  and set periority group
 * 				  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/





#include "interrupt.h"
#include "tm4c123gh6pm.h"
#include "Std_Types.h"







/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



 /******************************************************************************
* \Syntax          : void interrupt_enable(uint8 interrupt_name)        
* \Description     : function used to enable interrupt and set the periority groub level
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : intterrupt_name   the name of the interrupt which need to be enabled                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/




	void interrupt_enable(uint8 interrupt_name)
	{
        static uint8 first_int_enable =0;

        /*Conndition to set the periority group levels */
        if(first_int_enable==0)
        {
            #if(PERIORITY_GROUP_LEVEL==0x07)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_7_1;
            #elif(PERIORITY_GROUP_LEVEL==0x06)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_6_2;
            #elif(PERIORITY_GROUP_LEVEL==0x05)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_5_3;
            #elif(PERIORITY_GROUP_LEVEL==0x04)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_4_4;
            #elif(PERIORITY_GROUP_LEVEL==0x03)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_3_5;
            #elif(PERIORITY_GROUP_LEVEL==0x02)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_2_6;
            #elif(PERIORITY_GROUP_LEVEL==0x01)
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_1_7;
            #else
            NVIC_APINT_R=(NVIC_APINT_R&0X0000F0FF)|(0xFA05)|NVIC_APINT_PRIGROUP_0_8;
            #endif
            first_int_enable++;
        }



        if((interrupt_name>=INT_GPIOA)&&(interrupt_name<=INT_GPIOF))
        {
            SET_BIT(NVIC_EN0_R,(interrupt_name-16));
        }
        else if((interrupt_name>=INT_UART2)&&(interrupt_name<=INT_UART7))
        {
            SET_BIT(NVIC_EN1_R,(interrupt_name-16-(32*1)));
        } 
         else if((interrupt_name>=INT_I2C2)&&(interrupt_name<=INT_WTIMER0B))
        {
            SET_BIT(NVIC_EN2_R,(interrupt_name-16-(32*2)));
        } 
         else if((interrupt_name>=INT_WTIMER1A)&&(interrupt_name<=INT_SYSEXC))
        {
            SET_BIT(NVIC_EN3_R,(interrupt_name-16-(32*3)));
        } 
         else if((interrupt_name>=INT_PWM1_0)&&(interrupt_name<=INT_PWM1_FAULT))
        {
            SET_BIT(NVIC_EN4_R,(interrupt_name-16-(32*4)));
        }
        else if(interrupt_name== INT_Memory_Managment_Fault) 
        {
            SET_BIT(NVIC_SYS_HND_CTRL_R,16);
        }
        else if(interrupt_name== INT_Bus_Fault) 
        {
            SET_BIT(NVIC_SYS_HND_CTRL_R,17);
        }
        else if(interrupt_name== INT_Usage_Fault) 
        {
            SET_BIT(NVIC_SYS_HND_CTRL_R,18);
        }
        
	}








