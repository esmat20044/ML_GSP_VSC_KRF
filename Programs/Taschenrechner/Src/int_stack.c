/**
 * @file int_stack.c
 * @author Franz Korf, HAW Hamburg 
 * @date Mar 2016
 * @brief This modules implements t simple stack for integer 
 *        values. The number of elements is fixed.
 *        Error handling will be implemented via standard errno
 *        concept of UNIX.
 */
 
#include "int_stack.h"
#include <errno.h>

#define MAXANZELEMS    64      //!< Maximal number of elements that can be stored in the stack

static int top = 0;            //!< next free element in stack array, 
                               //   top == 0:  empty stack, 
                               //   top == MAXANZELEMS: full stack

static int stack[MAXANZELEMS]; //!< An array of fixed size implements the stack.

void initStack (void){
   top = 0;
}

#define CHECK_AND_RETURN(cond,err) { if (cond) { errno = (err); return -1; }}

int push(int value){
   CHECK_AND_RETURN((top >= MAXANZELEMS),ERANGE)
   stack[top++] = value;
   return 0;
}

int pop(int *value){
   CHECK_AND_RETURN((top <= 0), ERANGE)
   *value = stack[--top];
   return 0;
}

int elemAt(int pos, int *value){
    CHECK_AND_RETURN((pos < 0),ERANGE)
    CHECK_AND_RETURN(top -1 - pos < 0,ERANGE)
    *value = stack[top - 1 - pos];
    return 0;  
}
// EOF
