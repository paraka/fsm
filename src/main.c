#include <stdio.h>
#include "keyboard.h"

/*
 * Simulate SHIFT PRESS WITH '^' and SHIFT release with '6'
 * To finish the infinite loop just type '.' character
 */
int main(void)
{
    Keyboard k;
    keyboard_ctor(&k);

    FSM_INIT((Fsm *)&k, 0);
    
    for (;;)
    {
        KeyboardEvt ke;
        printf("\nSIGNAL:");
        ke.code = getc(stdin); 
        getc(stdin); /* discard '\n' */

        switch (ke.code)
        {
            case '^': ke.super_.sig = KEYBOARD_SHIFT_PRESSED_SIGNAL; break;
            case '6': ke.super_.sig = KEYBOARD_SHIFT_RELEASED_SIGNAL; break;
            case '.': return 0;          /* terminate the test */
            default: ke.super_.sig = KEYBOARD_ANY_KEY_PRESSED; break;
        }

        FSM_DISPATCH((Fsm *)&k, (Event *)&ke);  /* dispatch */
    }

    return 0;
}
