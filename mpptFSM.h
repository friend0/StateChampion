#ifndef MPPT_FSM_H
#define MPPT_FSM_H

//////////////////////////////////////////
// Declaration of FSM and Event objects //
//////////////////////////////////////////

typedef struct Mppt Mppt;
typedef struct MpptEvent MpptEvent;

/****************************************************************
Events
****************************************************************/
/* signals used by the Mppt FSM - Algorithm either runs, or it does not. This is a submachine of the inverterFSM.*/
enum {
    EXECUTE,
    DISABLE,
    NO_EVENT,
};


/**************************************************************************
Mppt FSM - Public Type Definitions for Mppt FSM and Mppt Events
***************************************************************************/
/**
* @brief 'type naming' of the FSM object
*
* The 'Mppt' struct is a container for the FSM base class.
* Other attributes of the class are included. Class methods are
* implemented following this.
*/
struct Mppt {
    Fsm super_; /* extend the Fsm class */
    //Attributes
};

struct MpptEvent {
    Event super_; /* extend the Event class */
    //Attributes
    char code;
};

////////////////////////////////////
// Declaration of state functions //
////////////////////////////////////

/**
* @brief Constructor Function
* This function is to be used for 'instantiating' state machines
* @code(.c)
*     Mppt Mppt;
*     MpptCtor(&Mppt);
* @endcode
* MpptCtor is a wrapper function for a call to:
* @code
*     _FsmCtor_(&self->super_, &Mppt_initial);
* @endcode
* which uses the 'super class'
*
* @param self
*/
void MpptCtor(Mppt *self);

/**
* @brief Entry state to be used for initialization and setup of the state machine.
*
* Implements the initial transition of the Mppt FSM. To be used for initializations
* and setup of the machine. Can also serve no function but to transition to the default or
* zero states.
*
* @param self self reference to MpptFSM
* @param e    event
*/
void Mppt_initial(Mppt *self, Event const *e);

/**
* Implements the default transition
* @param self self reference to MpptFSM
* @param e    event
*/
void Mppt_Execute(Mppt *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying +Vdc to the input of the RLC filter.
* @param self self reference to MpptFSM
* @param e    event
*/
void Mppt_Blink(Mppt *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying zero volts DC to the input of the RLC filter.
* @param self self reference to MpptFSM
* @param e    event
*/
void Mppt_Disable(Mppt *self, Event const *e);


char MpptTransitionFunction(Mppt self, MpptEvent *e);

#endif