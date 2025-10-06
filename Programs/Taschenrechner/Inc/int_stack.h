/**
 * @file int_stack.h
 * @author Franz Korf, HAW Hamburg 
 * @date Mar 2016
 * @brief Header file of the int_stack module. 
 */

#ifndef INT_STACK_H
#define INT_STACK_H

/**
 *****************************************************************************************
 *  @brief      This function initializes / resets the stack
 *
 *  @return     void 
 ****************************************************************************************/
extern void initStack (void);

/**
 *****************************************************************************************
 *  @brief      This function pushs an int value on the stack.
 *
 *  @param      value The value that will be pushed on the stack.
 *
 *  @return     Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 
 *              is returned and the global integer variable errno is set to indicate the error.
 ****************************************************************************************/
extern int push(int value);

/**
 *****************************************************************************************
 *  @brief      This function pops an element for the stack.
 *
 *  @param      value The address to which pop should write the top element of the stack.
 *
 *  @return     Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 
 *              is returned and the global integer variable errno is set to indicate the error.
 ****************************************************************************************/
extern int pop(int *value);

/**
 *****************************************************************************************
 *  @brief      This function assigns stack element at position pos to *value.
 *
 *  @param      pos Position of element to be selected (pos == 0 : top of stack will be assigned).
 *  @param      value The address to which the element will be written.
 *
 *  @return     Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 
 *              is returned and the global integer variable errno is set to indicate the error.
 ****************************************************************************************/
extern int elemAt(int pos, int *value);

#endif /* INT_STACK_H */
// EOF
