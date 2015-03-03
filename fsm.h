/**
 * @file fsm.h
 * @author Ryan Rodriguez
 * @date 12/27/14
 * @brief Header for FSM base class implementations
 *
 * Declaration of the two structs *Event* and *FSM* which serve as
 * superclasses to FSM classes implemented by the us.
 */


#ifndef FSM_H
#define FSM_H


typedef struct Event Event;
typedef struct Fsm Fsm;

typedef short Signal;

/*
    This is, in essence, a variable of type 'function pointer'.
    It is used to represent the states of our machine.
    The FSM * argument is the current state.

    Therefore, in the FSM struct itself, we use the member variable 'State'
    to hold the current state of the FSM. State translates to the 'function being pointed to'
 */
typedef void (*State)(Fsm *, Event const *);


/** @brief Event base class
 * This struct is the base class for events. It has a single attribute,
 * state__ of type State, where State is defined .
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
    /*
       The function being pointed to, or the 'state'
     */
    State state__; /* the current state */
};


/** @brief Event base class
 * This struct is the base class for events. It has a single attribute
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
    Signal transition; /* Change to boolean value when supported, will be either true or false*/
};


/**
 * "inlined" selfthods of Fsm class
*/

/**
 * Constructor selfthod, initializes state
 * Translates to, the state, 'state__', pointed to by self (FSM) is equalt to RHS,
 * where State is of type 'function pointer'
 */
#define _FsmCtor_(self_, init_) ((self_)->state__ = (State)(init_))

/**
 * Initializes state machine, with some event
 */
#define FsmInit(self_, e_)     (*(self_)->state__)((self_), (e_))

/**
 * Dispatches events to the state machine
 */
#define FsmDispatch(self_, e_) (*(self_)->state__)((self_), (e_))

#define FunctionDispatch(self_, e) (*self_)(self, (e))
/**
 * This takes a state transition, i.e. updates the state
 * q+
 */
#define _FsmTran_(self_, targ_) ((self_)->state__ = (State)(targ_))

#endif
