/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: interrupt.H
 *       Module:  Source file for the tiva-c interrupt driver
 *
 *  Description:  header file for the Tiva-C interrupt driver     
 *  
 *********************************************************************************************************************/




#ifndef INTERRUPT_H_
#define INTERRUPT_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define PERIORITY_GROUP_LEVEL     0


/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )



/*This defines are not define in the library "tm4c123gh6pm"    */

#define INT_Memory_Managment_Fault 4    
#define INT_Bus_Fault              5
#define INT_Usage_Fault            6
#define INT_SVcall                 11
#define INT_Debug_Monitor          12
#define INT_Pend_SV                14
#define INT_sys_tick               15


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/




void interrupt_enable(uint8 interrupt_name);




#endif /* INTERRUPT_H_ */
