/**
 * @file arith_lib.h
 * @author Franz Korf, HAW Hamburg 
 * @date Sep 2023
 * @brief This module contains some arithmetic functions. 
 */

#ifndef ARITH_LIB_H
#define ARITH_LIB_H

#include <stdbool.h>

/*
 ****************************************************************************************
 *  @brief      This function checks overflow for int addition
 *
 *  @param      arg1 first summand
 *  @param      arg2 second summand
 *
 *  @return     This function returns true, when arg1 + arg2 leads to an overflow.
 ****************************************************************************************/
bool overflowAdd(int arg1, int arg2);

/*
 ****************************************************************************************
 *  @brief      This function checks overflow for int subtraction
 *
 *  @param      arg1 minuend
 *  @param      arg2 subtrahend
 *
 *  @return     This function returns true, when arg1 - arg2 leads to an overflow.
 ****************************************************************************************/
bool overflowSub(int arg1, int arg2);

/*
 ****************************************************************************************
 *  @brief      This function checks overflow for int multiplication
 *
 *  @param      arg1 first factor
 *  @param      arg2 second factor
 *
 *  @return     This function returns true, when arg1 * arg2 leads to an overflow.
 ****************************************************************************************/
extern bool overflowMult(int arg1, int arg2);

/*
 ****************************************************************************************
 *  @brief      This function checks overflow for int division
 *
 *  @param      arg1 dividend
 *  @param      arg2 divisor
 *
 *  @return     This function returns true, when arg1 / arg2 leads to an overflow.
 ****************************************************************************************/
extern bool overflowDiv(int arg1, int arg2);
   
/*
 ****************************************************************************************
 *  @brief      This function prints an int variable on the display. It uses modulo- 
 *              division method with base 10. This method returns the rightmost digit first. 
 *              But the output expects the leftmost digit first. This can be solved with a 
 *              recursive function, but in the area of embedded systems with little stack size
 *              this approach has the disadvantage that the stack grows depending on the 
 *              recursion depth. 
 *              Using a while loop this function computes digits from right to left and 
 *              stores them temporarily in a field. 
 *              Furthermore, this function takes care for the fact that the number range of 
 *              2-complement is asymmetrical. 
 *
 *  @param      v number to be printed
 *
 *  @return     None
 ****************************************************************************************/
extern void printNumber(int v);

#endif /* ARITH_LIB_H */
// EOF
