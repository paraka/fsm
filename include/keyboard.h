#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "fsm.h"

typedef struct Keyboard Keyboard;
struct Keyboard
{
    Fsm super_; /* extend the Fsm class */

    /* others */
};

extern void keyboard_ctor(Keyboard *me);
extern void keyboard_initial(Keyboard *me, const Event *ev);
extern void keyboard_default(Keyboard *me, const Event *ev);
extern void keyboard_shifted(Keyboard *me, const Event *ev);

typedef struct KeyboardEvt KeyboardEvt;
struct KeyboardEvt
{
    Event super_; /* extend the Event class */
    char code;
};

/* signals used by the Keyboard FSM */
enum
{
    KEYBOARD_SHIFT_PRESSED_SIGNAL,
    KEYBOARD_SHIFT_RELEASED_SIGNAL,
    KEYBOARD_ANY_KEY_PRESSED,
};

#endif /* KEYBOARD_H_ */
