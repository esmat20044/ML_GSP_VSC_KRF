#include "stack.h"
#include "token.h"
#include "display.h"

void rechnen(char token)
{
    int a, b, result;

    switch ()
    {
        case NUMBER:
            push(number);
            break;

        case PLUS:
            if (pop(&a) == 0 && pop(&b) == 0) 
            {
                result = b + a;
                push(result);
            }
            break;

        case MINUS:
            if (pop(&a) == 0 && pop(&b) == 0) 
            {

                result = b - a;
                push(result);
            }
            break;

        case MULT:
            if (pop(&a) == 0 && pop(&b) == 0) 
            {
                result = b * a;
                push(result);
            }
            break;

        case DIV:
            if (pop(&a) == 0 && pop(&b) == 0) 
            {
                    result = b / a;
                    push(result);
                
            }
            break;

        case PRT:
            if (peek(&a) == 0) 
            {



                // wie soll ich ausgeben
        



            }
            break;

        case PRT_ALL:
            // Alle Werte anzeigen 
            


                    // wie soll ich ausgeben


            break;

        case CLEAR:
            clear_stack();
            break;

        case DOUBLE:
            duplicate();
            break;

        case SWAP:
            swap();
            break;

        default:
            break;
    }
}
