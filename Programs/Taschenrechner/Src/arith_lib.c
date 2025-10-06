/**
 * @file arith_lib.c
 * @author Franz Korf, HAW Hamburg 
 * @date Sep 2023
 * @brief This modules contains some arithmetic functions
 */
 
#include "arith_lib.h"
#include "display.h"
#include <stdlib.h>
#include <limits.h>

#define PRT_BUF_SIZE    16
void printNumber(int v) {
   char buf[PRT_BUF_SIZE];
   int pos = PRT_BUF_SIZE - 1; // next free pos
   buf[pos--] = '\0';
   int t = v;
   do {
      buf[pos--] = '0' + abs(t % 10);
      t = t / 10;
   } while (t != 0);
   if (v < 0){
      buf[pos--] = '-';
   }
   printStdout(buf + pos + 1);
   printStdout("\n");
}

bool overflowMult(int arg1, int arg2) {
	 // if one factor == 0, no overflow
	 if ((0 == arg1) || (0 == arg2)) {return false;}
    // Both factors are not equal to 0 
	 // Due to the asymetric range of int = -2^31 ... 2^31-1 , two cases must be differed 
	 // case 1: result positiv : arg1 * arg2 <= INT_MAX <=> arg1 <= INT_MAX/arg2
	 if (((0 < arg1) && (0 < arg2)) || ((0 > arg1) && (0 > arg2))) {
       if ((arg1 == INT_MIN) || (arg2 == INT_MIN)){
          return true; // Since the second factor is not 0, multiplication always returns an overflow.
       }
       return (abs(arg1) > (INT_MAX / abs(arg2)));		 
	 }
    // one factor is negativ, the other one is positiv
	 int neg_arg = (arg1 > arg2) ? arg2 : arg1;
	 int pos_arg = (arg1 > arg2) ? arg1 : arg2;
	 return (neg_arg < (INT_MIN / pos_arg));	
}

bool overflowDiv(int arg1, int arg2) {
   // arg2 = 0 => overflow
   // arg2 = -1 und arg1 = MIN_INT => overflow - due to the asymmetric number range
   return (arg2 == 0) || (arg2 == -1) && (arg1 == INT_MIN);
}

bool overflowAdd(int arg1, int arg2) {
   // Bedingung für Overflow bei erg = arg2 + arg1
   // Deckt Asymmetrie der 2-Komplementdarstellung ab (MIN_INT = (-1)*MAX_INT - 1
	// arg1 == 0 oder arg2 == 0                         : kein Overflow
   // arg1 < 0 und arg2 > 0 oder arg1 > 0 and arg2 < 0 : kein Overflow
   // arg1 < 0 und arg2 < 0 und arg1 + arg2 > 0        : Overflow
   // arg1 > 0 und arg2 > 0 und arg1 + arg2 < 0        : Overflow
   int erg = arg2 + arg1;
   return ((arg1 > 0) && (arg2 > 0) && (erg < 0))||
          ((arg1 < 0) && (arg2 < 0) && (erg > 0));        
}

bool overflowSub(int arg1, int arg2) {
   // Deckt Asymmetrie der 2-Komplementdarstellung ab (MIN_INT = (-1)*MAX_INT - 1
   if (arg2 == INT_MIN) {
      return arg1 > -1;
   }
   return overflowAdd(arg1, -1 * arg2);
}

// EOF
