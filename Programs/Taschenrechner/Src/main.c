/**
  * @file    	main.c 
  * @author  	Franz Korf
  *        	  HAW-Hamburg
  * @version V0.5
  * @date    2020-08-17
  * @brief   Main program body and control module of RPN calculator. 
  *          Modules are structured according to MVC (model view control) design.
  *          This solution bases on the RPN calculatr for the old TI Board.
  */

/* Includes ------------------------------------------------------------------*/
#include "init.h"
#include "scanner.h"
#include "display.h"
#include "arith_lib.h"
#include "int_stack.h"

static void clearSystem(void) {
	 initStack();
	 setNormalMode();
}

static void errHandler(char * msg) {
	 setErrMode();
    printStdout(msg);
    printStdout("\n");
    printStdout("Reset calculator (press C)");
	 while(1) {
		  T_token token = nextToken();
		  if (CLEAR == token.tok) {
				 clearSystem();
				 return;
		  }
	 }
}

/*
 ****************************************************************************************
 *  @brief      This function handles one token.
 *
 *  @return     void 
 ****************************************************************************************/
static void handleToken(void){
   T_token tok = nextToken();
   int arg1, arg2;
   int stackStatus = 0; // in case of an error: negativ number and errno set
   switch (tok.tok) {
      case PLUS: case MINUS: case MULT: case DIV: case SWAP: 
         // all binary operators arg1 op arg2
         stackStatus = pop(&arg2);
         stackStatus = stackStatus + pop(&arg1);
         if (SWAP  == tok.tok) {
            stackStatus = push(arg2);
            stackStatus = stackStatus + push(arg1);
         }
         if (stackStatus != 0) {
            break;
         }
         if ((PLUS  == tok.tok) && overflowAdd(arg1, arg2) ||
             (MINUS == tok.tok) && overflowSub(arg1, arg2) ||
             (MULT  == tok.tok) && overflowMult(arg1,arg2) ||
			    (DIV   == tok.tok) && overflowDiv(arg1,arg2)) {
            errHandler("Arithmetic overflow");
            break;
         }
         stackStatus = (PLUS   == tok.tok) ? push(arg1 + arg2) : stackStatus;
         stackStatus = (MINUS  == tok.tok) ? push(arg1 - arg2) : stackStatus;
         stackStatus = (MULT   == tok.tok) ? push(arg1 * arg2) : stackStatus;
         stackStatus = (DIV    == tok.tok) ? push(arg1 / arg2) : stackStatus;
         break;         
      case NUMBER: case DOUBLE: // unary operators
         arg1 = tok.val;
         if (DOUBLE == tok.tok){
             stackStatus = elemAt(0, &arg1);
         }
         stackStatus = stackStatus + push(arg1);
         break;
      case CLEAR:
         clearSystem();
		   break;
	   case OVERFLOW:
		   errHandler("Overflow during input of number");
		   break;
	   case UNEXPECTED:
		   errHandler("Internal error: unexpected input key");
		   break;
      case PRT: case PRT_ALL:
         clearStdout();
         if (0 != elemAt(0,&arg1)){
            printStdout("empty stack\n");
            break;
         }
         printNumber(arg1);
         int i = 1;
         while((PRT_ALL == tok.tok) && (0 == elemAt(i++,&arg1))){
            printNumber(arg1);
            if (isBottomLine()) {
				   printStdout("Press P to continue\n");
				   while (PRT_ALL != nextToken().tok) {}
               setNormalMode();
            }                  
         }
         break;         
      default: // ENTER token not expected, is whitespace
         errHandler("Internal error: unexpected token");
   }
   // report stack error
   if (stackStatus != 0) {
      errHandler("Stack overflow or stack underflow");   
   }
}
	
int main(void) {
   initITSboard();
   initDisplay();
   errHandler("RPN-Demo-Korf");
	while (1) {
		 handleToken();
	}
}
// EOF
