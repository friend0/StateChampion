/**************************************************************************
*@File inverterFSM.C                                                      *
*@author Ryan Rodriguez                                                   *
*@date 12/27/14                                                           *
*@brief This module implements the inverter state machine                 *
*This module is the software implementation of the inverter state machine,*
*and is intended for research purposes at this moment.                    *
**************************************************************************/

#include "fsm.h"
#include "inverterFSM.h"
#include <stdio.h>
#include <ctype.h>
#include <execinfo.h>


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
States
****************************************************************/
/**
enum{
Inverter_initial,
Inverter_default,
Inverter_PowerOn,
Inverter_OutOfParameters,
Inverter_WithinParameters,
Inverter_AlmostOutOfParameters,
Inverter_ShutDown,
};
**/

/****************************************************************
Events
****************************************************************/
/* signals used by the Inverter FSM */
enum
{
    POWER_ON,
    OUTSIDE_PARAMETERS,
    INSIDE_PARAMETERS,
    ALMOST_OUT_OF_PARAMETERS,
    SHUT_DOWN,
    NO_EVENT,
};

/**
* Begin State Defintiions
*/

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
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;
    }
}


void Inverter_PowerOn(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;
    }
}

void Inverter_OutOfParameters(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;

    }
}

void Inverter_WithinParameters(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;
    }
}

void Inverter_AlmostOutOfParameters(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;
    }
}

void Inverter_ShutDown(Inverter *self, Event const *e)
{
    switch (e->signal)
    {
        case POWER_ON:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *)self, &Inverter_PowerOn);
            break;

        case OUTSIDE_PARAMETERS:
            printf("H-bridge to zero");
            _FsmTran_((Fsm *)self, &Inverter_OutOfParameters);
            break;

        case INSIDE_PARAMETERS:
            printf("H-bridge to VDC");
            _FsmTran_((Fsm *)self, &Inverter_WithinParameters);
            break;

        case ALMOST_OUT_OF_PARAMETERS:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_AlmostOutOfParameters);
            break;

        case SHUT_DOWN:
            printf("defaultNOEVENT");
            _FsmTran_((Fsm *)self, &Inverter_ShutDown);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            ;
            break;
    }
}

/**
* @brief Used to determine the event that should be passed to the FsmDispatch function
*
* Using the InverterEvent class, we utilize the data variable 'code' to switch the signal
* of the Event super-class. Next, we take the updated Event signal and dispatch it to
* the current state function pointed to by Fsm of the class Inverter.
*
*
* @param self [description]
* @param e    [description]
*/

char InverterTransitionFunction(Inverter self, InverterEvent *e)
{
    //InverterEvent e is a wrapper structure containing members Char code, and Event super_.
    //  Code is just a data variable used to switch the signal attribute of the super_ Event. 
    //  In our case, code should be a tuple of Il and Vc, used to switch the signal of the Event structure.
    //  The super_ Event is then passed to the dispatch function which calls the state function. 
    //  The state function reads the signal and responds with the appropriate transition.        

    //First, get the event pointed to by inverter event
    //Next, get the signal pointed to by the event in inverterEvent

    //printf("InverterState:%d\n", self.super_.state__);

    void    *funptr = self.super_.state__;
    //backtrace_symbols_fd(&funptr, 1, 1);

    if(funptr == &Inverter_default){
        printf("\nInverter Default\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {

            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else if(funptr  == &Inverter_PowerOn){
        printf("\nInverter Power On!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else if(funptr  == &Inverter_OutOfParameters){
        printf("\nInverter Out of Parameters!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else if(funptr  == &Inverter_WithinParameters){
        printf("\nInverter Within Parameters!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else if(funptr  == &Inverter_AlmostOutOfParameters){
        printf("\nInverter VDC!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else if(funptr  == &Inverter_ShutDown){
        printf("\nInverter Shut Down!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Inverter Event
        {
            case 'P' : e->super_.signal = POWER_ON; break;
            case 'S' : e->super_.signal = SHUT_DOWN; break;
            case 'W' : e->super_.signal = INSIDE_PARAMETERS; break;
            case 'O' : e->super_.signal = OUTSIDE_PARAMETERS; break;
            case 'A' : e->super_.signal = ALMOST_OUT_OF_PARAMETERS; break;
            case '.' : return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default : e->super_.signal = NO_EVENT; break;
        }
    }
    else ;


    //FsmDispatch( (Fsm *)&self, (Event *)&e);  //dispatch
    return 0;
}


/**
* End State Definitions
*/


/**
* The main function below is to be used with keyboard input or Bucchi
* automaton for testing purposes.
*/


int main()
{
    int returner = 0;
    //Declare the variable k to be of the type 'inverter', where inverter is the class
    //wrapping the FSM
    Inverter k;

    //Take the class inverter, get the FSM it contains, and point it to an initialization state
    InverterCtor(&k);
    FsmInit((Fsm *)&k, 0);
    for (;;)
    {
        InverterEvent ke;                   //make a new event on every cycle
        //printf("\nSignal<-");             //output the signal attribute of the event object

        //ke.code should be the value sampled at ADC for actual implementation
        ke.code = getc(stdin);            //obtain user input, use the data attribute 'code' to store it
        getc(stdin);                      //discard newline '\n' //


        void    *funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);

        returner = InverterTransitionFunction(k, &ke);
        if(returner == -1) return 0;
        FsmDispatch((Fsm *)&k, (Event *)&ke);  //dispatch

        funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);


    }
    return 0;
}
