/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  seven_segma.H
 *       Module:  seven_segma
 *
 *  Description:  header file for the seven segams display driver     
 *  
 *********************************************************************************************************************/
#ifndef seven_segma_H_
#define seven_segma_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "gpio.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SIGAM_1                   1
#define SIGAM_2                   2

#define SIGAM_1_PORT_ID           PORTA_ID
#define SIGAM_1_BASE_BIN_ID       PIN0_ID


#define SIGAM_2_PORT_ID           PORTA_ID
#define SIGAM_2_BASE_BIN_ID       PIN4_ID


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/





 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SEVEN_SEGMA_init(uint8 sigma );
void SEVEN_SEGMA_write_value(uint8 sigma, uint8 value);

 
#endif  /* seven_segma_H_ */

/**********************************************************************************************************************
 *  END OF FILE: seven_segma_H_.h
 *********************************************************************************************************************/
