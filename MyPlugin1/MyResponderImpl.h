#ifndef _CSDTPINDESIGNRESPONDERIMPL_H_
#define _CSDTPINDESIGNRESPONDERIMPL_H_

//includes
#include "VCPlugInHeaders.h"
#include "DocumentID.h"
#include "CResponder.h"
#include "CAlert.h"
//to get the service ID
#include "ISignalMgr.h"
//project includes
#include "MP1ID.h"
#include "MyResponder.h"
//#include "CSDTPUtility.h"
//Handling ICXS events
#include "ICSXSPlugPlugEventHandler.h"
#include "adobe/unicode.hpp" // for adobe::to_utf8
#include "FileTypeRegistry.h"
//using EasyJson library for encoding and decoding json string for HTML5 plugin
//#include "json.h"

class MyResponderImpl : public CResponder, public MyResponder
{
public:

	MyResponderImpl(IPMUnknown*);
	~MyResponderImpl();

	/*@Interface
	Respond() - Invoked by Indesign Notifications
	1) This will capture the generated signals and call the appropriate function
	2) For close doc detection, we used 'kBeforeCloseDocSignalResponderService' signal
	as we need the document reference of the closing doc
	*/
	virtual void Respond(ISignalMgr* signalMgr);

	/*@Interface
	handleMyOpenEvent() attaches the document Observer(for cut/copy/delete) on
	opened doc and also dispatches the CSXS event
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMyOpenEvent(ISignalMgr*);

	/*@Interface
	handleDocCloseEvent() detaches the document Observer(for cut/copy/delete) on
	close doc and also dispatches the CSXS event
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMyCloseEvent(ISignalMgr*);

	/*@Interface
	handleDocSwitchEvent()  dispatches the CSXS event on switching between the document tabs
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleDocSwitchEvent(ISignalMgr*);


	/*@Interface
	handleMySaveEvent() dispatches the CSXS event on saving a document
	@param signalMgr: Signal from Indesign
	*/
	virtual bool handleMySaveEvent(ISignalMgr*);

private:
	//ICXS message 
	PMString dispatchType, dispatchMsg;

};

#endif //_CSDTPINDESIGNRESPONDERIMPL_H_