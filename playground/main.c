#include "fsm.h"
#include "hBridgeFSM.h"
#include "inverterFSM.h"
#include <stdio.h>
#include <ctype.h>
#include <execinfo.h>

/**
* The main function below is to be used with keyboard input or Bucchi
* automaton for testing purposes.
*/

/*

int main() {

    int returner = 0;
    //Declare the variable k to be of the type 'inverter', where inverter is the class
    //wrapping the FSM

    Mppt k;
    MpptCtor(&k);
    FsmInit((Fsm *) &k, 0);

    //Infinite Loop
    for (;;) {
        //Make a new event on every cycle
        MpptEvent ke;

        //printf("\nSignal<-");             //output the signal attribute of the event object

        //ke.code should be the value sampled at ADC for actual implementation
        ke.code = getc(stdin);            //obtain user input, use the data attribute 'code' to store it
        getc(stdin);                      //discard newline '\n' //


        void *funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);

        returner = MpptTransitionFunction(k, &ke);
        if (returner == -1) return 0;

        FsmDispatch((Fsm *) &k, (Event *) &ke);  //dispatch

        funptr = k.super_.state__;
        backtrace_symbols_fd(&funptr, 1, 1);
    }
    return 0;
}
*/
