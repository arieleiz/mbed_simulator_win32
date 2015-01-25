#pragma once
// THIS FILE WAS AUTO GENERATED BY model2mbed.exe DO NOT MODIFY!!!

#include "ModelImpl.h"

namespace Model {
// Channels
extern ModelImpl::SYNCHRONIZATION_CHANNEL GLOBAL_CHANNEL_VAR_m_BolusReq; // chan m_BolusReq
extern ModelImpl::SYNCHRONIZATION_CHANNEL GLOBAL_CHANNEL_VAR_c_StartInfusion; // chan c_StartInfusion
extern ModelImpl::SYNCHRONIZATION_CHANNEL GLOBAL_CHANNEL_VAR_c_StopInfusion; // chan c_StopInfusion
extern ModelImpl::SYNCHRONIZATION_CHANNEL GLOBAL_CHANNEL_VAR_m_EmptySyringe; // chan m_EmptySyringe
extern ModelImpl::SYNCHRONIZATION_CHANNEL GLOBAL_CHANNEL_VAR_c_Alarm; // chan c_Alarm


struct SYSTEM_VARIABLES
    {
        clk clk_pump_x;
         int __unused__;
       public:  SYSTEM_VARIABLES() :
 __unused__(0){
}
       private: SYSTEM_VARIABLES(const SYSTEM_VARIABLES& other);
       private: SYSTEM_VARIABLES& operator=(const SYSTEM_VARIABLES& other);
    };

extern SYSTEM_VARIABLES SystemVariables;

// Process - pump

extern ModelImpl::TRANSITION_ENTRY pump_TRANS_Infusion__Start__0;
extern ModelImpl::TRANSITION_ENTRY pump_TRANS_EmptyDetected__Start__0;
extern ModelImpl::TRANSITION_ENTRY pump_TRANS_Infusion__EmptyDetected__0;
extern ModelImpl::TRANSITION_ENTRY pump_TRANS_BolusRequested__Infusion__0;
extern ModelImpl::TRANSITION_ENTRY pump_TRANS_Start__BolusRequested__0;
extern ModelImpl::STATE_ENTRY pump_STATE_EmptyDetected;
extern ModelImpl::STATE_ENTRY pump_STATE_Infusion;
extern ModelImpl::STATE_ENTRY pump_STATE_BolusRequested;
extern ModelImpl::STATE_ENTRY pump_STATE_Start;
extern ModelImpl::PROCESS_ENTRY pump_PROCESS;
extern ModelImpl::PROCESS_ENTRY_STATE pump_PROCESS_STATE;



} // namespace

// initialize the dispatcher:
//    ModelImpl::Dispatcher disp;
//    disp.set_clock_multiplier(1000 /*us*/);
//    #ifdef DISPATCH_DEBUG
//    disp.init_debug(&pc);
//    #endif
//
// add events. examples:
//    disp.set_channel_action(&Model::Template_CHANNEL_VAR_led, LED1, ModelImpl::SendChannelModePulseUp, 250000);
//    disp.set_channel_action(&Model::Template_CHANNEL_VAR_manual, LED1, ModelImpl::SendChannelModeToggle);
//    disp.set_receive_input(&Model::GLOBAL_CHANNEL_VAR_press, p7, ModelImpl::ReceiveChannelInterruptRise);
//
// Tip: use just the templates you want in the code:
//    disp.add_process(&Model::pump_PROCESS_STATE);
//
// and finally run:
//    disp.run();

