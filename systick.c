
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  delay_timer32_0.c
 *        \brief   Source file for the tiva-c timer 0 driver used as delay driver
 *
 *      \details  this module is to use the timer as delay by polling on the interrupt flag
 * 					using 12 MHz clock source
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/





#include "systick.h"
#include "tm4c123gh6pm.h"
#include "Std_Types.h"








/* Global variables to hold the address of the call back function in the application */
	static volatile void (*g_callBackPtr_systick)(void) = NULL_PTR;
	

	/*******************************************************************************
	 *                       Interrupt Service Routines                            *
	 *******************************************************************************/



	void SysTick_Handler(void)
	{
		if(g_callBackPtr_systick != NULL_PTR)
		{
			/* Call the Call Back function in the application after the receiving data */
			(*g_callBackPtr_systick)(); /* another method to call the function using pointer to function g_callBackPtr(); */
		}
	}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*function to turn on the Systick with the required time*/



	void SYSTICK_init(uint32 load)
	{
		NVIC_ST_RELOAD_R =load;

		NVIC_ST_CURRENT_R=0;
		
		NVIC_ST_CTRL_R=NVIC_ST_CTRL_R|0x07;
		

	}



/*
 * function to turn off SysTick 
 * */

void SYSTICK_deinit(void)
{
	CLEAR_BIT(NVIC_ST_CTRL_R,0);
}



/*
 * function to set the call back address that will be called by the ISR
 * */

void SYSTICK_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr_systick = a_ptr;
}




