/**************************************************************************
*@File inverterFSM.C                                                      *
*@author Ryan Rodriguez                                                   *
*@date 12/27/14                                                           *
*@brief This module implements the inverter state machine                 *
*This module is the software implementation of the inverter state machine, *
*and is intended for research purposes at this moment.                    *
**************************************************************************/

#include "fsm.h"
#include "inverterFSM.h"
#include <stdio.h>
#include <ctype.h>


/****************************************************************
Inverter FSM
****************************************************************/
/**
* @brief 'type naming' of the FSM object
*
* The 'Inverter' struct is a container for the FSM base class.
* Other attributes of the class are included. Class methods are
* implemented following this.
*/
struct Inverter
{
    Fsm super_; /* extend the Fsm class */
    //Attributes
};

struct InverterEvent
{
    Event super_; /* extend the Event class */
    //Attributes
    char code;
};

/****************************************************************
Events
****************************************************************/
/* signals used by the Inverter FSM */
enum
{
    SHIFT_DEPRESSED_SIG,
    SHIFT_RELEASED_SIG,
    ANY_KEY_SIG,
    NEG_VDC,    //q = -1
    ZERO_VDC,   //q = 0
    VDC,        //q = 1
    NO_EVENT,
};

/* signals used by the Inverter FSM *//*
enum
{
    NEG_VDC,    //q = -1
    ZERO_VDC,   //q = 0
    VDC,        //q = 1
    NO_EVENT,
};*/

/****************************************************************
States
****************************************************************/

void InverterCtor(Inverter *self)
{
    _FsmCtor_(&self->super_, &Inverter_initial);
}

void Inverter_initial(Inverter *self, Event const *e)
{
/* ... initialization of Inverter attributes */
    printf("Inverter initialized");
    _FsmTran_((Fsm *)self, &Inverter_default);
}

void Inverter_default(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case SHIFT_DEPRESSED_SIG:
            printf("defaultSHIFT_DEPRESSED");
            _FsmTran_((Fsm *)self, &Inverter_shifted);
            break;
        case ANY_KEY_SIG:
            printf("key %c", (char)tolower(((InverterEvent *)e)->code));
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_Zero);
            break;
    }
}

void Inverter_shifted(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case SHIFT_RELEASED_SIG:
            printf("shiftedSHIFT_RELEASED");
            _FsmTran_((Fsm *)self, &Inverter_default);
            break;
        case ANY_KEY_SIG:
            printf("key %c", (char)toupper(((InverterEvent *)e)->code));
            break;
    }
}


void Inverter_VDC(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case NEG_VDC:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_negVDC);
            break;
        case ZERO_VDC:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_Zero);
            break;
        default:
            break;
    }
}

void Inverter_Zero(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case VDC:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_VDC);
            break;
        case NEG_VDC:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_negVDC);
            break;

        default:
            break;

    }
}

void Inverter_negVDC(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case VDC:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_VDC);
            break;
        case ZERO_VDC:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_Zero);
            break;

        default:
            break;
    }
}

int main()
{
    Inverter k;
    InverterCtor(&k);
    FsmInit((Fsm *)&k, 0);
    for (;;)
    {
        InverterEvent ke;                   //make a new event on every cycle
        printf("\nSignal<-");             //output the signal attribute of the event object

        //ke.code should be the value sampled at ADC for actual implementation
        ke.code = getc(stdin);            //obtain user input, use the data attribute 'code' to store it
        getc(stdin);                      /* discard newline '\n' */
        switch (ke.code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case '^' : ke.super_.signal = SHIFT_DEPRESSED_SIG; break;
            case '6' : ke.super_.signal = SHIFT_RELEASED_SIG; break;
            case '.' : return 0;          /* terminate the test */
            case '+' : ke.super_.signal = VDC; break;
            case '-' : ke.super_.signal = NEG_VDC; break;
            case '0' : ke.super_.signal = ZERO_VDC; break;

            //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : ke.super_.signal = NO_EVENT; break;

        }
        FsmDispatch((Fsm *)&k, (Event *)&ke);  /* dispatch */
    }
    return 0;
}