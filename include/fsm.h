#ifndef FSM_H_
#define FSM_H_

#include <stdint.h>

typedef uint32_t Signal;
typedef struct Event Event;
typedef struct Fsm Fsm;
typedef void (*State)(Fsm *, const Event *);

/* Event base class */
struct Event
{
    Signal sig;
};

/* Finite State Machine base class */
struct Fsm
{
    State state__; /* the current state */
};

/* "inlined" methods of Fsm class */

#define FSM_CTOR(me_, init_)    ((me_)->state__ = (State)(init_))
#define FSM_INIT(me_, e_)       (*(me_)->state__)((me_), (e_))
#define FSM_DISPATCH(me_, e_)   (*(me_)->state__)((me_), (e_))
#define FSM_TRANS(me_, targ_)   ((me_)->state__ = (State)(targ_))

#endif /* FSM_H_ */
