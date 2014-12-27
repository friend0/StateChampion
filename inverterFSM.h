#ifndef INVERTERFSM_H
#define INVERTERFSM

typedef struct Inverter Inverter;
typedef struct InverterEvent InverterEvent;

/**
* @brief Constructor Function
* This function is to be used for 'instantiating' state machines
* @code(.c)
*     Inverter k;
*     InverterCtor(&k);
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
* Implements the initial transition of inverterFSM
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
* Implements the state handler for
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_shifted(Inverter *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying +Vdc to the input of the RLC filter.
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_VDC(Inverter *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying zero volts DC to the input of the RLC filter.
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_Zero(Inverter *self, Event const *e);

/**
* Implements the state handler for the case that the H-Bridge
* is supplying -Vdc to the input of the RLC filter.
* @param self self reference to inverterFSM
* @param e    event
*/
void Inverter_negVDC(Inverter *self, Event const *e);



#endif

