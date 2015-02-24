// -------------------------------- FRAMEWORK --------------------------------------
// State Machine function prototypes
//----------------------------------------------------------------------------------
// Alpha states
void A0(void);  //state A0
void B0(void);  //state B0
void C0(void);  //state C0

// A branch states
void A1(void);  //state A1
void A2(void);  //state A2
void A3(void);  //state A3
void A4(void);  //state A4

// B branch states
void B1(void);  //state B1
void B2(void);  //state B2
void B3(void);  //state B3
//void B4(void);	//state B4

// C branch states
void C1(void);  //state C1
void C2(void);  //state C2
void C3(void);  //state C3
void C4(void);  //state C4

// Variable declarations
void (*Alpha_State_Ptr)(void);  // Base States pointer
void (*A_Task_Ptr)(void);       // State pointer A branch
void (*B_Task_Ptr)(void);       // State pointer B branch
void (*C_Task_Ptr)(void);       // State pointer C branch

int16 VTimer0[4];                   // Virtual Timers slaved off CPU Timer 0
int16 VTimer1[4];                   // Virtual Timers slaved off CPU Timer 1
int16 VTimer2[4];                   // Virtual Timers slaved off CPU Timer 2




//=================================================================================
//	STATE-MACHINE SEQUENCING AND SYNCRONIZATION
//=================================================================================

//--------------------------------- FRAMEWORK -------------------------------------
void A0(void)
{
        // loop rate synchronizer for A-tasks
        if(CpuTimer0Regs.TCR.bit.TIF == 1)
        {
                CpuTimer0Regs.TCR.bit.TIF = 1; // clear flag

                //-----------------------------------------------------------
                (*A_Task_Ptr)(); // jump to an A Task (A1,A2,A3,...)
                //-----------------------------------------------------------

                VTimer0[0]++;   // virtual timer 0, instance 0 (spare)
        }

        Alpha_State_Ptr = &B0;  // Comment out to allow only A tasks
}

void B0(void)
{
        // loop rate synchronizer for B-tasks
        if(CpuTimer1Regs.TCR.bit.TIF == 1)
        {
                CpuTimer1Regs.TCR.bit.TIF = 1;      // clear flag

                //-----------------------------------------------------------
                (*B_Task_Ptr)(); // jump to a B Task (B1,B2,B3,...)
                //-----------------------------------------------------------
                VTimer1[0]++;   // virtual timer 1, instance 0 (spare)
        }

        Alpha_State_Ptr = &C0;  // Allow C state tasks
}

void C0(void)
{
        // loop rate synchronizer for C-tasks
        if(CpuTimer2Regs.TCR.bit.TIF == 1)
        {
                CpuTimer2Regs.TCR.bit.TIF = 1;      // clear flag

                //-----------------------------------------------------------
                (*C_Task_Ptr)(); // jump to a C Task (C1,C2,C3,...)
                //-----------------------------------------------------------
                VTimer2[0]++;   //virtual timer 2, instance 0 (spare)
        }

        Alpha_State_Ptr = &A0; // Back to State A0
}

//=================================================================================
//	A - TASKS
//=================================================================================
//--------------------------------------------------------
void A1(void)  // Dash Board Measurements
//--------------------------------------------------------
{



        //-------------------
        //the next time CpuTimer0 'counter' reaches Period value go to A2
        A_Task_Ptr = &A2;
        //-------------------
}

//--------------------------------------------------------
void A2(void)          // Panel Connect Disconnect
//-----------------------------------------------------------------
{
        if(PanelBoostConnect==0)
        {
                GpioDataRegs.GPACLEAR.bit.GPIO12=0x1;
        }
        else if (PanelBoostConnect==1)
        {
                GpioDataRegs.GPASET.bit.GPIO12=0x1;
        }

        //-------------------
        //the next time CpuTimer0 'counter' reaches Period value go to A1
        A_Task_Ptr = &A3;
        //-------------------
}

//--------------------------------------------------------
void A3(void)  // Talk to the Panel Emulator
//-----------------------------------------
{
        if(Gui_LightCommand != Gui_LightCommand_Prev)
        {
                sdata[0]=1; //1 indicates it is the command for the light value

                // saturate the light command to 0.8 because of power capacity of the DC power supply shipped with the kit
                if(Gui_LightCommand>_IQ13(0.8))
                        Gui_LightCommand=_IQ13(0.8);

                if(Gui_LightCommand<_IQ13(0.0))
                        Gui_LightCommand=_IQ13(0.0);

                sdata[1]=Gui_LightCommand;  // Value of light that needs to be sent to the emulator

                Gui_LightCommand_Prev=Gui_LightCommand;

                SpibRegs.SPITXBUF=sdata[0];      // Send data
                SpibRegs.SPITXBUF=sdata[1];

                SpiaRegs.SPIFFTX.bit.TXFIFO=1;

                Gui_PanelPower_Theoretical=_IQ9mpy(_IQ9(36.02),((long)Gui_LightCommand>>4)); // Panel Max power * Luminance Ratio

        }
        //-----------------
        //the next time CpuTimer0 'counter' reaches Period value go to A1
        A_Task_Ptr = &A4;
        //-----------------
}

//--------------------------------------------------------
void A4(void)          // Spare
//--------------------------------------------------------
{
        //-----------------
        //the next time CpuTimer0 'counter' reaches Period value go to A1
        A_Task_Ptr = &A1;
        //-----------------
}
