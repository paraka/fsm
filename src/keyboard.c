#include <stdio.h>
#include <ctype.h>
#include "keyboard.h"

void keyboard_ctor(Keyboard *me)
{
    FSM_CTOR(&me->super_, &keyboard_initial);
}

void keyboard_initial(Keyboard *me, const Event *ev)
{
    printf("%s\n", __func__);
    FSM_TRANS((Fsm *)me, &keyboard_default);
}

void keyboard_default(Keyboard *me, const Event *ev)
{
    switch (ev->sig)
    {
        case KEYBOARD_SHIFT_PRESSED_SIGNAL:
            printf("KEYBOARD_SHIFT_PRESSED_SIGNAL\n");
            FSM_TRANS((Fsm *)me, &keyboard_shifted);
            break;
        case KEYBOARD_ANY_KEY_PRESSED:
            printf("KEYBOARD_ANY_KEY_PRESSED: %c\n", (char)tolower(((KeyboardEvt *)ev)->code));
            break;
    }

}

void keyboard_shifted(Keyboard *me, const Event *ev)
{
    switch (ev->sig)
    {
        case KEYBOARD_SHIFT_RELEASED_SIGNAL:
            printf("KEYBOARD_SHIFT_RELEASED_SIGNAL\n");
            FSM_TRANS((Fsm *)me, &keyboard_default);
            break;
        case KEYBOARD_ANY_KEY_PRESSED:
            printf("KEYBOARD_ANY_KEY_PRESSED: %c\n", (char)toupper(((KeyboardEvt *)ev)->code));
            break;
    }
}
