/*
*  Pacemaker4Mbed (c) 2014 Ariel Eizenberg - arieleiz@seas.upenn.edu.
*  Developed for UPENN CIS 541 course project - verifiable pacemaker.
*
*    This file is part of Pacemaker4Mbed. You can redistribute it and/or modify
*    it under the terms of the Academic Free License 3.0
*	  (http://opensource.org/licenses/AFL-3.0).
*
*/

#include "ModelImpl.h"
#include "Model.h"

Serial pc(USBTX, USBRX); // tx, rx
#ifdef DISPATCH_DEBUG
Mutex dbgmutex;
#endif

int main (void) 
{
    // terminal should be set to MBED's defaults: 9600,8,n,1
    pc.printf("Simple-v1: initializing.\r\n");

	ModelImpl::Dispatcher disp;
	disp.set_clock_multiplier(2500 /*us*/);
	#ifdef DISPATCH_DEBUG
	disp.init_debug(&pc, &dbgmutex);
	#endif

	disp.set_channel_action(&Model::GLOBAL_CHANNEL_VAR_c_StartInfusion, p5, ModelImpl::SendChannelModeSet);
	disp.set_channel_action(&Model::GLOBAL_CHANNEL_VAR_c_StopInfusion, p5, ModelImpl::SendChannelModeReset);
	disp.set_channel_action(&Model::GLOBAL_CHANNEL_VAR_c_Alarm, p6, ModelImpl::SendChannelModePulseUp, 3000000);
	disp.set_channel_action(&Model::GLOBAL_CHANNEL_VAR_c_Alarm, p5, ModelImpl::SendChannelModeReset);
	disp.set_receive_input(&Model::GLOBAL_CHANNEL_VAR_m_BolusReq, p7, PullUp, ModelImpl::ReceiveChannelInterruptRise);
	disp.set_receive_input(&Model::GLOBAL_CHANNEL_VAR_m_EmptySyringe, p8, PullUp, ModelImpl::ReceiveChannelInterruptRise);
	
	disp.add_process(&Model::pump_PROCESS_STATE);
	pc.printf("Simple-v1: starting.\r\n");
	disp.run();

}

