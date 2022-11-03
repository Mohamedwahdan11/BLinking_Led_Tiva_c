/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  seven_segma.c
 *        \brief   Source file for the seven segams display driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/




#include "Std_Types.h"
#include "seven_segma.h"
#include "gpio.h"
#include "tm4c123gh6pm.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /******************************************************************************
* \Syntax          : void SEVEN_SEGMA_init(uint8 sigma )        
* \Description     : initalaize tha 7-segma pins                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : sigma                  The number of the  7-sigma                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SEVEN_SEGMA_init(uint8 sigma )
{
    int i=0;
    if(sigma==SIGAM_1 )
    {
        for(i=0;i<4;i++)
    {
        Pin_Config sigma_conf ={SIGAM_1_BASE_BIN_ID+i, SIGAM_1_PORT_ID,PIN_OUTPUT};
	    GPIO_setupPinDirection(&sigma_conf);

    }
	
    }
    else if (sigma==SIGAM_2 )
    {
       
        for(i=0;i<4;i++)
        {
             Pin_Config sigma_conf ={SIGAM_2_BASE_BIN_ID+i,SIGAM_2_PORT_ID,PIN_OUTPUT};
             GPIO_setupPinDirection(&sigma_conf);

        }
	
    }
    
    
}


 /******************************************************************************
* \Syntax          : void SEVEN_SEGMA_write_value(uint8 sigma, uint8 value)      
* \Description     : display write the value on the 7-segma                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : sigma                  The number of the  7-sigma                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SEVEN_SEGMA_write_value(uint8 sigma, uint8 value)
{
    uint8 current=0;
	if(sigma==SIGAM_1 )
    {
        
        current= GPIO_readPort(SIGAM_1_PORT_ID);
        current=(current&0xF0)|(value<<SIGAM_1_BASE_BIN_ID);
        GPIO_writePort(SIGAM_1_PORT_ID,current);
    }
    else if (sigma==SIGAM_2 )
    {
        current= GPIO_readPort(SIGAM_2_PORT_ID);
        current=(current&0x0F)|(value<<SIGAM_2_BASE_BIN_ID);
        GPIO_writePort(SIGAM_2_PORT_ID,current);
     
    }
}
