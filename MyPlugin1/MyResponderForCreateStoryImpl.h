#pragma once
#ifndef _ICSDTPINDESIGNRESPONDER_H_
#define _ICSDTPINDESIGNRESPONDER_H_

#include "VCPlugInHeaders.h"
//#include "DocumentID.h"
#include "CResponder.h"
#include "CAlert.h"
//to get the service ID
#include "ISignalMgr.h"
//project includes
#include "MP1ID.h"
//Handling ICXS events
#include "ICSXSPlugPlugEventHandler.h"
#include "adobe/unicode.hpp" // for adobe::to_utf8
#include "FileTypeRegistry.h"

class MyResponderForCreateStoryImpl : public CResponder
{
public:

	MyResponderForCreateStoryImpl(IPMUnknown*);
	~MyResponderForCreateStoryImpl();

	virtual void Respond(ISignalMgr* signalMgr);

	virtual bool handleCreateStoryEvent(ISignalMgr*);
};
#endif