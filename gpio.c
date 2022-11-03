/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  gpio.c
 *        \brief   Source file for the tiva-c GPIO driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/




#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "gpio.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /******************************************************************************
* \Syntax          : void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)        
* \Description     : Setup the direction of the required pin input/output.
*                    If the input port number or pin number are not correct,
                     The function will not handle the request.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port_num               The number of the  port
                     pin_num                The number of the  pin
                     GPIO_PinDirectionType  The direction of the pin                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_setupPinDirection(const Pin_Config * config_ptr)
{
	uint8 i;
	RCGC2|=0x0003F;
	RCGCGPIO|=0X0003F;

	
	for ( i = 0; i < 4; i++);
	
	
	switch(config_ptr->Port_ID)
		{
		case PORTA_ID:
			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_A,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_A,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_A=0x4C4F434B;
			SET_BIT(GPIOCR_A,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_A,config_ptr->Pin_Id);

			SET_BIT(GPIODEN_A,config_ptr->Pin_Id);

			break;
		case PORTB_ID:

			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_B,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_B,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_B=0x4C4F434B;
			SET_BIT(GPIOCR_B,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_B,config_ptr->Pin_Id);


			SET_BIT(GPIODEN_B,config_ptr->Pin_Id);
			break;

		case PORTC_ID:

			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_C,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_C,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_C=0x4C4F434B;
			SET_BIT(GPIOCR_C,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_C,config_ptr->Pin_Id);


			SET_BIT(GPIODEN_C,config_ptr->Pin_Id);
			break;

		case PORTD_ID:

			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_D,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_D,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_D=0x4C4F434B;
			SET_BIT(GPIOCR_D,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_D,config_ptr->Pin_Id);



			SET_BIT(GPIODEN_D,config_ptr->Pin_Id);
			break;

		case PORTE_ID:

			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_E,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_E,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_E=0x4C4F434B;
			SET_BIT(GPIOCR_E,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_E,config_ptr->Pin_Id);


			SET_BIT(GPIODEN_E,config_ptr->Pin_Id);
			break;	
		case PORTF_ID:

			if(config_ptr->Direction==PIN_OUTPUT)
			{
			SET_BIT(GPIODIR_F,config_ptr->Pin_Id);
			}
			else if (config_ptr->Direction==PIN_INPUT)
			{
				CLEAR_BIT(GPIODIR_F,config_ptr->Pin_Id);
			}
			
			GPIOLOCK_F=0x4C4F434B;
			SET_BIT(GPIOCR_F,config_ptr->Pin_Id);

			CLEAR_BIT(GPIOAFSEL_F,config_ptr->Pin_Id);


			SET_BIT(GPIODEN_F,config_ptr->Pin_Id);
			break;				
		}




	
}


 /******************************************************************************
* \Syntax          : GPIO_writePin(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)        
* \Description     : Write the value Logic High or Logic Low on the required pin.
*                    If the input port number or pin number are not correct, The function will
*                    not handle the request.                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port_num               The number of the output port
                     pin_num                The number of the output pin
                     value                  The value to be output on the pin                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_A,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_A,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_B,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_B,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_C,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_C,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_D,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_D,pin_num);
			}
			break;
		case PORTE_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_E,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_E,pin_num);
			}
			break;
		case PORTF_ID:
			if(value == STD_HIGH)
			{
				SET_BIT(GPIODATA_F,pin_num) ;
			}
			else
			{
				CLEAR_BIT(GPIODATA_F,pin_num);
			}
			break;		
		}
	}
}


 /******************************************************************************
* \Syntax          : uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)       
* \Description     : Read and return the value for the required pin, it should be Logic High or Logic Low.
*					 If the input port number or pin number are not correct, 
*					 The function will return Logic Low.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = STD_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(GPIODATA_A,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(GPIODATA_B,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(GPIODATA_C,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(GPIODATA_D,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;
		case PORTE_ID:
			if(BIT_IS_SET(GPIODATA_E,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;
		case PORTF_ID:
			if(BIT_IS_SET(GPIODATA_F,pin_num))
			{
				pin_value = STD_HIGH;
			}
			else
			{
				pin_value = STD_LOW;
			}
			break;		
		}
	}

	return pin_value;
}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
 /******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port_num         the number equivelent to the port
*                    value            the value to be output                   
* \Parameters (out): None                                                      
*******************************************************************************/
void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			GPIODATA_A = value;
			break;
		case PORTB_ID:
			GPIODATA_B = value;
			break;
		case PORTC_ID:
			GPIODATA_C = value;
			break;
		case PORTD_ID:
			GPIODATA_D = value;
			break;
		case PORTE_ID:
			GPIODATA_F = value;
			break;
		case PORTF_ID:
			GPIODATA_F = value;		
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
 /******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port_num   number equivelent to thw port                     
* \Parameters (out): uint8 value with the port value                                                                                      
*******************************************************************************/
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = STD_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = (uint8)GPIODATA_A;
			break;
		case PORTB_ID:
			value = (uint8)GPIODATA_B;
			break;
		case PORTC_ID:
			value = (uint8)GPIODATA_C;
			break;
		case PORTD_ID:
			value = (uint8)GPIODATA_D;
			break;
		case PORTE_ID:
			value = (uint8)GPIODATA_E;
			break;
		case PORTF_ID:
			value = (uint8)GPIODATA_F;
			break;	
		}
	}

	return value;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
