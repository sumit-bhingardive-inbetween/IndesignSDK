/************************************************************************************
*NOTE: The Observer is now moved from kDocBoss to kSessionBoss to keep only one instance
*	   Now the Observer will be attached in CSDTPStartupShutdownServiceImpl.startup() call
*	   and will use the ISession reference to instantiate
*
*
*************************************************************************************/


#include "VCPlugInHeaders.h"

//Responder service class definations
#include "DocumentID.h"          //For open and close doc signal
#include "DocFrameworkID.h"      //for switch doc signal
#include "GenericID.h"           //for new PI event


//Project Includes
#include "MyResponderImpl.h"
#include "myStartupShutdownServiceImpl.h"
//#include "json.h"                //from supereasyJson library

//Interface includes
#include "IDocumentSignalData.h" //To get docRef
#include "INewPISignalData.h"    //To get pageItemRef
#include "IDocument.h"
#include "IFrameType.h"
#include "IObserver.h"
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
#include "IApplication.h"
#include "IDocumentList.h"
#include "IDocumentSignalData.h"
#include "ISpreadList.h"
#include "IDataBase.h"
#include "ISpread.h"
#include "IFrameType.h"


/* CREATE_PMINTERFACE
Binds the C++ implementation class onto its ImplementationID
making the C++ code callable by the application.
*/
CREATE_PMINTERFACE(MyResponderImpl, kMyResponderImpl)

MyResponderImpl::MyResponderImpl(IPMUnknown* boss) :CResponder(boss)
{
}

MyResponderImpl::~MyResponderImpl()
{
}





/*@Interface
Respond()
1) This will capture the generated signals and call the appropriate function
2) For close doc detection, we used 'kBeforeCloseDocSignalResponderService' signal
as we need the document reference of the closing doc
*/
void MyResponderImpl::Respond(ISignalMgr* signalMgr)
{
	ServiceID serviceTrigger = signalMgr->GetServiceID();
	switch (serviceTrigger.Get())
	{

	case kAfterNewDocSignalResponderService:
	{
		handleMyOpenEvent(signalMgr);
		break;
	}
	case kAfterOpenDocSignalResponderService:
	{
		handleMyOpenEvent(signalMgr);
		break;
	}
	case kBeforeCloseDocSignalResponderService:
	{
		handleMyCloseEvent(signalMgr);
		break;
	}
	case kDocChangesSignalResponderService:
	{
		handleDocSwitchEvent(signalMgr);
		break;
	}

	case kBeforeSaveDocSignalResponderService:
	{
		CAlert::InformationAlert("hello....Before Saving");
		handleMySaveEvent(signalMgr);
		break;
	}

	case kAfterSaveDocSignalResponderService:
	{
		CAlert::InformationAlert("hello....After Saving Document");
		break;
	}

	case kBeforeSaveAsDocSignalResponderService:
	{
		CAlert::InformationAlert("hello....Before first time Saving Document");
		handleMySaveEvent(signalMgr);
		break;
	}

	default:
		break;
	}
}

/*@Interface
handleDocMyOpenEvent() attaches the document Observer(for cut/copy/delete) on
opened doc and also dispatches the CSXS event
@param signalMgr: Signal from Indesign
*/
bool MyResponderImpl::handleMyOpenEvent(ISignalMgr* signalMgr)
{
	CAlert::InformationAlert("hello.....Opening Document");
	return true;
}

/*@Interface
handleMyCloseEvent() detaches the document Observer(for cut/copy/delete) on
close doc and also dispatches the CSXS event
@param signalMgr: Signal from Indesign
*/
bool MyResponderImpl::handleMyCloseEvent(ISignalMgr* signalMgr)
{
	PMString docName;
	InterfacePtr<IDocumentSignalData> documentSignalData(signalMgr, UseDefaultIID());
	ASSERT(documentSignalData != nil);
	if (documentSignalData == nil)
	{
		return false;
	}
	UIDRef docUIDRef = documentSignalData->GetDocument();
	InterfacePtr<IDocument> document(docUIDRef, UseDefaultIID());
	if (!document)
	{
		return false;
	}
	else{
		CAlert::InformationAlert("hello......Found Docuemnt object");
	}
	InterfacePtr<ISpreadList> spreadList(document, UseDefaultIID());
	IDataBase* database = docUIDRef.GetDataBase();
	int32 spreadCount = spreadList->GetSpreadCount();

	for (int32 spreadIndex = 0; spreadIndex < spreadCount; spreadIndex++)
	{
		UIDRef spreadUIDRef(database, spreadList->GetNthSpreadUID(spreadIndex));
		InterfacePtr<ISpread> spread(spreadUIDRef, UseDefaultIID());
		for (int32 pageIndex = 0; pageIndex < spread->GetNumPages(); pageIndex++)
		{
			UIDList itemsOnPage(database);
			const bool16 bIncludePage = kFalse;
			const bool16 bIncludePasteboard = kFalse;
			spread->GetItemsOnPage(pageIndex, &itemsOnPage, bIncludePage,
				bIncludePasteboard);
			PMString str = "Number of Items ";
			str.AppendNumber(itemsOnPage.Length());
			CAlert::InformationAlert(str);
			// Add code to manipulate itemsOnPage.
		}
	}

	UID docUID = docUIDRef.GetUID();
	document->GetName(docName);


	/*InterfacePtr<IApplication> application(GetExecutionContextSession()
		->QueryApplication());
	InterfacePtr<IDocumentList> documentList(application->QueryDocumentList());
	for (int32 i = 0; i < documentList->GetDocCount(); i++) {
		IDocument* document = documentList->GetNthDoc(i);
		PMString name;
		PMString documentName = document->GetName(name);
		CAlert::InformationAlert("hello DocumentName");
	}*/
	CAlert::InformationAlert("hello......Closing Docuemnt");
	return true;
}

/*@Interface
handleDocSwitchEvent()  dispatches the CSXS event on switching between the document tabs
@param signalMgr: Signal from Indesign
*/
bool MyResponderImpl::handleDocSwitchEvent(ISignalMgr* signalMgr)
{
	return true;
}

/*@Interface
handleDocSwitchEvent()  dispatches the CSXS event on saving a document
@param signalMgr: Signal from Indesign
*/
bool MyResponderImpl::handleMySaveEvent(ISignalMgr* signalMgr)
{
	CAlert::InformationAlert("hello....Saving Document");

	PMString docName;
	InterfacePtr<IDocumentSignalData> documentSignalData(signalMgr, UseDefaultIID()); //Getting data from singnal manager 
	ASSERT(documentSignalData != nil);
	if (documentSignalData == nil)
	{
		return false;
	}
	UIDRef docUIDRef = documentSignalData->GetDocument();// Getting document reference Id.
	InterfacePtr<IDocument> document(docUIDRef, UseDefaultIID()); // Getting document object using docuement reference Id.
	if (!document)
	{
		CAlert::InformationAlert("Document is not found");
		return false;
	}
	InterfacePtr<ISpreadList> spreadList(document, UseDefaultIID()); // Getting spreads list for the document.
	IDataBase* database = docUIDRef.GetDataBase(); // Getting database object for the document. Database object contains information about doucument(eg. Number of spreads, number of pages, etc.)
	int32 spreadCount = spreadList->GetSpreadCount(); 

	for (int32 spreadIndex = 0; spreadIndex < spreadCount; spreadIndex++)
	{
		UIDRef spreadUIDRef(database, spreadList->GetNthSpreadUID(spreadIndex)); // Getting spreads reference Id.
		InterfacePtr<ISpread> spread(spreadUIDRef, UseDefaultIID());// object of spread. 
		for (int32 pageIndex = 0; pageIndex < spread->GetNumPages(); pageIndex++)
		{
			UIDList itemsOnPage(database);// list of page items.
			const bool16 bIncludePage = kFalse;
			const bool16 bIncludePasteboard = kFalse;
			spread->GetItemsOnPage(pageIndex, &itemsOnPage, bIncludePage,
				bIncludePasteboard);// Got list of page items.
			PMString str = "Number of Items ";
			
			str.AppendNumber(itemsOnPage.Length());// Append a Number in PMString.
			CAlert::InformationAlert(str);
			for (int32 frameIndex = 0; frameIndex < itemsOnPage.Length(); frameIndex++)
			{
				UIDRef frameUIDRef(database, itemsOnPage.At(frameIndex)); // Got reference id for the frame.
				InterfacePtr<IFrameType> iFrameType(frameUIDRef, UseDefaultIID());//Got frame object.
				PMString sFrameType = "Frame Type: ";
				sFrameType.AppendNumber(iFrameType->IsTextFrame());
				CAlert::InformationAlert(sFrameType);
				UIDRef pageItemRef  =  itemsOnPage.GetRef(frameIndex);
				IXMLReferenceData *xmlReferenceData = Utils<IXMLUtils>()->QueryXMLReferenceData(pageItemRef);
				if (xmlReferenceData)
				{
					XMLReference ref = xmlReferenceData->GetReference();
					InterfacePtr<IIDXMLElement> element(ref.Instantiate());
					if (element != nil)
					{
						UID tagUID = element->GetTagUID();
						WideString elementName = element->GetTagString();
						PMString sFrameName = "TagName... ";
						sFrameName.Append(elementName);
						CAlert::InformationAlert(sFrameName);
						for (int iTagElementCount = 0; iTagElementCount < element->GetChildCount(); iTagElementCount++)
						{
							XMLReference childRef = element->GetNthChild(iTagElementCount);
							InterfacePtr<IIDXMLElement> childElement(childRef.Instantiate());
							if (childElement != nil)
							{
								UID tagUID = childElement->GetTagUID();
								WideString elementName = childElement->GetTagString();
								PMString sFrameName = "ChildTagName... ";
								sFrameName.Append(elementName);
								CAlert::InformationAlert(sFrameName);
							}
						}
					}
				}
			}
			// Add code to manipulate itemsOnPage.
		}
	}

	UID docUID = docUIDRef.GetUID();
	document->GetName(docName);

	return true;
}



