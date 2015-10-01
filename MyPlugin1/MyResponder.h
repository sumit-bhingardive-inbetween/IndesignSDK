#pragma once
#ifndef _ICSDTPINDESIGNRESPONDER_H_
#define _ICSDTPINDESIGNRESPONDER_H_

//includes
//#include "VCPlugInHeaders.h"
//#include "ICSXSPlugPlugEventHandler.h"
//project includes
#include "MP1ID.h"

class MyResponder
{

public:

//	enum { kDefaultIID = IID_ICSDTPINDESIGNRESPONDER };

	/*handleDocOpenEvent() attaches the document Observer(for cut/copy/delete) on
	opened doc and also dispatches the CSXS event
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMyOpenEvent(ISignalMgr*) = 0;

	/*handleDocCloseEvent() detaches the document Observer(for cut/copy/delete) on
	close doc and also dispatches the CSXS event
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMyCloseEvent(ISignalMgr*) = 0;

	/*handleDocSwitchEvent()  dispatches the CSXS event on switching between the document tabs
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleDocSwitchEvent(ISignalMgr*) = 0;

	/*handleMySaveEvent()  dispatches the CSXS event on saving a document
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMySaveEvent(ISignalMgr*) = 0;



};


#endif  //_ICSDTPINDESIGNRESPONDER_H_