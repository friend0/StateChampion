/**************************************************************************
*@file MpptFSM.C                                                          *
*@author Ryan Rodriguez                                                   *
*@date 12/27/14                                                           *
*@brief This module implements the Mppt state machine                     *
*This module is the software implementation of the Mppt state machine,    *
*and is intended for research purposes at this moment.                    *
**************************************************************************/

#include "fsm.h"
#include "mpptFSM.h"
#include <stdio.h>
#include <ctype.h>
#include <execinfo.h>

/**
enum{
Mppt_Initial,
Mppt_Execute,
Mppt_Blink,
Mppt_Disable,
};
*/


/**
* Begin State Defintiions
*/

void MpptCtor(Mppt *self) {
    _FsmCtor_(&self->super_, &Mppt_initial);
}

//I have ommited the 'const' qualifier here because I would like to be bale to set the transition state here
//May also need to change others for setting exit transition? will this get handled in transition function?
void Mppt_initial(Mppt *self, Event *e) {
    /* ... initialization of Mppt attributes */
    printf("Mppt initialized");

    //cannot call this here, the initial event passed is a zero...
    //e->transition = true;
    _FsmTran_((Fsm *) self, &Mppt_Disable);
}

void Mppt_Execute(Mppt *self, Event *e) {

    if (e->transition == true) {
        printf("transition is true!\n");
        e->transition = false;
    }

    switch (e->signal) {
        case DISABLE:
            printf("Disable");
            _FsmTran_((Fsm *) self, &Mppt_Disable);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            _FsmTran_((Fsm *) self, &Mppt_Blink);
            break;
    }
}

void Mppt_Blink(Mppt *self, Event *e) {

    if (e->transition == true) {
        printf("transition is true!\n");
        e->transition = false;
    }

    switch (e->signal) {

        case DISABLE:
            printf("Disable");
            _FsmTran_((Fsm *) self, &Mppt_Disable);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:
            printf("Blink");
            _FsmTran_((Fsm *) self, &Mppt_Execute);
            break;

    }
}

void Mppt_Disable(Mppt *self, Event *e) {

    if (e->transition == true) {
        printf("transition is true!\n");
        e->transition = false;
    }

    switch (e->signal) {
        case EXECUTE:
            printf("H-bridge to negVDC");
            _FsmTran_((Fsm *) self, &Mppt_Execute);
            break;

        case NO_EVENT:
            printf("defaultNOEVENT");
            break;

        default:;
            break;
    }
}


/**
* @brief Used to determine the event that should be passed to the FsmDispatch function
*
* Using the MpptEvent class, we utilize the data variable 'code' to switch the signal
* of the Event super-class. Next, we take the updated Event signal and dispatch it to
* the current state function pointed to by Fsm of the class Mppt.
*
*
* @param self [description]
* @param e    [description]
*/

char MpptTransitionFunction(Mppt self, MpptEvent *e) {
    //MpptEvent e is a wrapper structure containing members Char code, and Event super_.
    //  Code is just a data variable used to switch the signal attribute of the super_ Event.
    //  In our case, code should be a tuple of Il and Vc, used to switch the signal of the Event structure.
    //  The super_ Event is then passed to the dispatch function which calls the state function.
    //  The state function reads the signal and responds with the appropriate transition.

    //First, get the event pointed to by Mppt event
    //Next, get the signal pointed to by the event in MpptEvent

    //printf("MpptState:%d\n", self.super_.state__);

    /**
    * Grab the address of the function currently being pointed to
    */
    void *funptr = self.super_.state__;
    //backtrace_symbols_fd(&funptr, 1, 1);

    if (funptr == &Mppt_Execute) {
        printf("\nMppt Power On!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Mppt Event
        {
            case 'E' :
                e->super_.signal = EXECUTE;
                e->super_.transition = true;
                break;
            case 'D' :
                e->super_.signal = DISABLE;
                e->super_.transition = true;
                break;
            case 'N' :
                e->super_.signal = NO_EVENT;
                e->super_.transition = true;
                break;
            case '.' :
                return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default :
                e->super_.signal = 0;
                break;
        }
    }
    else if (funptr == &Mppt_Blink) {
        printf("\nMppt Out of Parameters!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Mppt Event
        {
            case 'E' :
                e->super_.signal = EXECUTE;
                e->super_.transition = true;
                break;
            case 'D' :
                e->super_.signal = DISABLE;
                e->super_.transition = true;
                break;
            case 'N' :
                e->super_.signal = NO_EVENT;
                e->super_.transition = true;
                break;
            case '.' :
                return -1;          // terminate the test

            default :
                e->super_.signal = 0;
                break;
        }
    }
    else if (funptr == &Mppt_Disable) {
        printf("\nMppt Within Parameters!\n");
        switch (e->code)                  //This switch uses the data attribute 'code' of the Mppt Event
        {
            case 'E' :
                e->super_.signal = EXECUTE;
                e->super_.transition = true;
                break;
            case 'D' :
                e->super_.signal = DISABLE;
                e->super_.transition = true;
                break;
            case 'N' :
                e->super_.signal = NO_EVENT;
                e->super_.transition = true;
                break;
            case '.' :
                return -1;          // terminate the test

                //default : ke.super_.signal = ANY_KEY_SIG; break;
            default :
                e->super_.signal = NO_EVENT;
                break;
        }
    }
    else;


    //FsmDispatch( (Fsm *)&self, (Event *)&e);  //dispatch
    return 0;
}


/**
* End State Implementations
*/



int main()
{

    /**
      * Define which state machine will be tested
    */
    #define MPPT 1

    int returner = 0;
    //Declare the variable k to be of the type 'inverter', where inverter is the class
    //wrapping the FSM

    //Take the class 'inverter', for example, and get the FSM it contains, then point it to an initialization state


    Mppt k;
    MpptCtor(&k);

    FsmInit((Fsm *)&k, 0);

    for (;;)
    {
        MpptEvent ke;

        //printf("\nSignal<-");             //output the signal attribute of the event object

        //ke.code should be the value sampled at ADC for actual implementation
        ke.code = getc(stdin);            //obtain user input, use the data attribute 'code' to store it
        getc(stdin);                      //discard newline '\n' //

        void *funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);


        returner = MpptTransitionFunction(k, &ke);

        if(returner == -1) return 0;
        FsmDispatch((Fsm *)&k, (Event *)&ke);  //dispatch

        funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);


    }
    return 0;
}
