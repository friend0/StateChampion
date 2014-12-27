#ifndef FSM_H
#define FSM_H

typedef struct Event Event;
typedef struct Fsm Fsm;

typedef short Signal;
typedef void (*State)(Fsm *, Event const *);

/** @brief Event base class
*This struct is the base class for events. It has a single attribute
* called signal.
*
* We should note that the signal 's' in set K is an invariant, for an
* input voltage Vin.
* \f$
* s \in K, \\
* K = [0,Vin]
* \f$
* More accurately, Vin will be scaled corresponding to the reference voltage
* at the ADC.
*/
struct Event
{
Signal signal;
};

/** @brief Event base class
*This struct is the base class for events. It has a single attribute
* called signal.
*
* We should note that the signal 's' in set K is an invariant, for an
* input voltage Vin.
* \f$
* s \in K, \\
* K = [0,Vin]
* \f$
* More accurately, Vin will be scaled corresponding to the reference voltage
* at the ADC.
*/
/* Finite State Machine base class */
struct Fsm
{
State state__; /* the current state */
};


/**
* "inlined" selfthods of Fsm class
* */

/**
* Constructor selfthod, initializes state
*/
#define _FsmCtor_(self_, init_) ((self_)->state__ = (State)(init_))

/**
* Initializes state machine
*/
#define FsmInit(self_, e_)     (*(self_)->state__)((self_), (e_))

/**
* Dispatches events to the state machine
*/
#define FsmDispatch(self_, e_) (*(self_)->state__)((self_), (e_))

/**
* This takes a state transition, i.e. updates the state
* q+
*/
#define _FsmTran_(self_, targ_) ((self_)->state__ = (State)(targ_))

#endif