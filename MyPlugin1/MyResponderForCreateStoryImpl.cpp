#include "VCPlugInHeaders.h"

//Responder service class definations
#include "DocumentID.h"          //For open and close doc signal
#include "DocFrameworkID.h"      //for switch doc signal
#include "GenericID.h"           //for new PI event


//Project Includes
#include "MyResponderForCreateStoryImpl.h"
#include "myStartupShutdownServiceImpl.h"
//#include "json.h"                //from supereasyJson library

//Interface includes
#include "IDocumentSignalData.h" //To get docRef
#include "INewPISignalData.h"    //To get pageItemRef
#include "IDocument.h"
//#include "IFrameType.h"
//#include "IObserver.h"
#include "IActiveContext.h"
#include "UIDRef.h"
#include "ISpreadList.h"
#include "ISpread.h"
#include "UIDList.h"
#include "IGraphicFrameData.h"
#include "IXMLReferenceData.h"
#include "IXMLUtils.h"
#include "XMLReference.h"
#include "IIDXMLElement.h"
#include "IXMLTagList.h"
#include "IXMLTagCommands.h"
#include "IPageItemTypeUtils.h"
#include "IHierarchy.h"
#include "TextID.h"				 //kNewStorySignalResponderService
#include "INewStorySignalData.h"

/* CREATE_PMINTERFACE
Binds the C++ implementation class onto its ImplementationID
making the C++ code callable by the application.
*/
CREATE_PMINTERFACE(MyResponderForCreateStoryImpl, kMyResponderForCreateStoryImpl)


void MyResponderForCreateStoryImpl::Respond(ISignalMgr* signalMgr)
{
	ServiceID serviceTrigger = signalMgr->GetServiceID();
	if (serviceTrigger.Get() == kNewStorySignalResponderService){
		handleCreateStoryEvent(signalMgr);
	}

}

bool MyResponderForCreateStoryImpl::handleCreateStoryEvent(ISignalMgr* signalMgr)
{
	CAlert::InformationAlert("hello");
	return true;
}