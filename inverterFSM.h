#ifndef INVERTERFSM_H
#define INVERTERFSM_H

//////////////////////////////////////////
// Declaration of FSM and Event objects //
//////////////////////////////////////////

typedef struct Inverter Inverter;
typedef struct InverterEvent InverterEvent;

/**************************************************************************
Inverter FSM - Public Type Definitions for Inverter FSM and Inverter Events
***************************************************************************/
/**
* @brief 'type naming' of the FSM object
*
* The 'Inverter' struct is a container for the FSM base class.
* Other attributes of the class are included. Class methods are
* implemented following this.
*/
struct Inverter {
    Fsm super_; /* extend the Fsm class */
    //Attributes
};

struct InverterEvent {
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
*     Inverter inverter;
*     InverterCtor(&inverter);
* @endcode
* InverterCtor is a wrapper function for a call to:
* @code
*     _FsmCtor_(&self->super_, &Inverter_initial);
* @endcode
* which uses the 'super class'
*
* @param self
*/
void InverterCtor(Inverter *self);
/**
* @brief Entry state to be used for initialization and setup of the state machine.
*
* Implements the initial transition of the inverter FSM. To be used for initializations
* and setup of the machine. Can also serve no function but to transition to the default or
* zero states.
*
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_initial(Inverter *self, Event const *e);

/**
* Implements the default transition
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_default(Inverter *self, Event const *e);

/**
* This is the state we should enter upon power up, i.e. switch is thrown on, or we are recovering from sleep.
*
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_PowerOn(Inverter *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying zero volts DC to the input of the RLC filter.
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_OutOfParameters(Inverter *self, Event const *e);

/**
* If the panel is at an acceptable voltage, this is a valid state. Produce power here
* by running the hBridge Fsm.
*
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_WithinParameters(Inverter *self, Event const *e);

/**
* We should have transitioned here from Within_Parameters; this indicates we were within acceptable limits,
* but are steadily moving out of acceptable parameters for power generation. Perform necessary preparation here.
*
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_AlmostOutOfParameters(Inverter *self, Event const *e);

/**
* Implements the state handler for an Inverter that is about to shut down.
* Right now I'm not exactly sure what needs to happen here.
*
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_ShutDown(Inverter *self, Event const *e);

char InverterTransitionFunction(Inverter self, InverterEvent *e);

#endif

