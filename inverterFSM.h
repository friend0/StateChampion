#ifndef INVERTERFSM_H
#define INVERTERFSM_H

//////////////////////////////////////////
// Declaration of FSM and Event objects //
//////////////////////////////////////////

typedef struct Inverter Inverter;
typedef struct InverterEvent InverterEvent;

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
* Implements the state handler for the case that the H-Bridge
* is supplying +Vdc to the input of the RLC filter.
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
* Implements the state handler for the case that the H-Bridge
* is supplying -Vdc to the input of the RLC filter.
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_WithinParameters(Inverter *self, Event const *e);

/**
* Implements the state handler for a source that has a trajectory
* headed outside the allowable parameters for the inverter to deliver the
* desired voltage and current
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

