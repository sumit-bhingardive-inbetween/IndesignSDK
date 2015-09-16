//includes
#include "VCPlugInHeaders.h"

//Project Includes
#include "myStartUpShutdownServiceImpl.h"

//#include "IObserver.h"
#include "UIDRef.h"
#include "IActiveContext.h"
#include "string.h"
#include "MP1ID.h"
#include "CAlert.h"
//#include "IObserver.h"


// Bind this C++ implementation onto its implementation ID so it's callable by InDesign.
CREATE_PMINTERFACE(myStartUpShutdownServiceImpl, kmyStartUpShutdownServiceImpl)

//Defined in File CSDTPIndesignResponderImpl
extern bool setObserver;

myStartUpShutdownServiceImpl::myStartUpShutdownServiceImpl(IPMUnknown *boss) :CPMUnknown<IStartupShutdownService>(boss)
{
	CAlert::InformationAlert("hello");
}

myStartUpShutdownServiceImpl::~myStartUpShutdownServiceImpl()
{

}


/*Startup() Called when app(Indesign) is starting up
1) Attach the observer
2) Add an event listener for a message type to catch CSXS
messages from the HTML extension
*/
void myStartUpShutdownServiceImpl::Startup()
{

	//ActiveSelectionObserver: this will observe all the selection changes in the document
	//pageItems selected, text selected, deselected etc.
	//InterfacePtr<IObserver> selDocObserver(GetExecutionContextSession(), IID_ICSDTPSELECTIONOBSERVER);
	//if (selDocObserver != nil)
	//{
	//	selDocObserver->AutoAttach();
	//}

	//Below code was written to make sure that obser is attached only when message is received from HTML Extension
	//InterfacePtr<ICSXSPlugPlugEventHandler> plugPlug(GetExecutionContextSession(), UseDefaultIID());
	//plugPlug->AddPlugPlugEventListener(csdtp_constant::MESSAGE_TYPE_ATTACH.GetPlatformString().c_str(), &messageEventListenerAttach, nil);
	//plugPlug->AddPlugPlugEventListener(csdtp_constant::MESSAGE_TYPE_DETACH.GetPlatformString().c_str(), &messageEventListenerDetach, nil);
}

/*Shutdown() Called when app(Indesign) is shutting up
1) Detach the observer
2) remove the event listener for the message type
*/
void myStartUpShutdownServiceImpl::Shutdown()
{
	
}


/*messageEventDispatcher() dispatches message to HTML5 handler registered extension id
@param msgType : the type of message eg: "Selection.Frame", "Frame.new" etc
@param msgData : the data to be sent as part of selction
*/




/*------NOTE: Below code was written to make sure that obser is attached only when message is received from HTML Extension-------*/





