#include "VCPlugInHeaders.h"
#include "MyObserverImpl.h"
#include "CAlert.h"
#include "ISubject.h"
#include "MP1ID.h"
#include "GenericID.h"
#include "ICSXSPlugPlugEventHandler.h"
#include "MyCSXSPluginImpl.h"
#include "adobe/unicode.hpp" // for adobe::to_utf8
#include "FileTypeRegistry.h"


/* CREATE_PMINTERFACE
Binds the C++ implementation class onto its
ImplementationID making the C++ code callable by the
application.
*/
CREATE_PMINTERFACE(MyObserverImpl, kMyObserverImpl)

MyObserverImpl::MyObserverImpl(IPMUnknown* boss) :CObserver(boss)
{
}

MyObserverImpl::~MyObserverImpl()
{
}


//Defined in File CSDTPIndesignResponderImpl
extern bool setObserver;

bool isCopyCutEventGlobal = false;

/*
@Interface
AutoAttach() attaches the Observer on the document
*/
void MyObserverImpl::AutoAttach()
{
	CAlert::InformationAlert("hello....AutoAttach");
	do
	{
		InterfacePtr<ISubject> subject(this, IID_ISUBJECT);
		if (subject != nil)
		{
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER) == kFalse)
			{
				subject->AttachObserver(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER);
			}
		}
	} while (false);

	/*InterfacePtr<ICSXSPlugPlugEventHandler> plugPlug(GetExecutionContextSession(), UseDefaultIID());// InterfacePtr is a iterface pointer (Template class) which is used to dispatch event by creating "plugPlug" object of ICSXSPlugPlugEventHandler type.
	PMString csxsEventStr;
	csxsEventStr.SetCString("Hello from CPP!");
	PMString eventData(csxsEventStr);
	std::string csxsEventUtf8 = "CSXS Notification";
	//adobe::to_utf8(csxsEventStr.begin(), csxsEventStr.end(), std::back_inserter(csxsEventUtf8));

	ICSXSPlugPlugEventHandler::CSXSEvent responseEvent;
	responseEvent.type = "Frame.New";// Type of the responseEvent
	responseEvent.scope = ICSXSPlugPlugEventHandler::kEventScope_Application;// Here scope of the event is limited to the indesigne application. If we set event scope to globle it can communicate with the other adobe application using indesigne.
	responseEvent.extensionId = nil;// Extention id is the id of the extention which you want to dispach event. nil will work for all extention.
	responseEvent.data = csxsEventUtf8.c_str();// Data sent by event.

	if (LocaleSetting::GetLocale().IsProductFS(kInDesignProductFS))
	{
		// as defined in ICSXSPlugPlugEventHandler.h
		responseEvent.appId = kIDEnigmaCode;
	}
	else
	{
		// as defined in ICSXSPlugPlugEventHandler.h
		responseEvent.appId = kICEnigmaCode;
	}

	plugPlug->DispatchPlugPlugEvent(&responseEvent);// ICSXSPlugPlugEventHandler contains this method DispatchPlugPlugEvent.*/
}

/*
@Interface
AutoDetach() detaches the Observer from the document
*/
void MyObserverImpl::AutoDetach()
{
	CAlert::InformationAlert("hello....AutoDetach");
	/*do
	{
		InterfacePtr<ISubject> subject(this, UseDefaultIID());

		if (subject != nil)
		{
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_ICSDTPOBSERVER) == kTrue)
			{
				subject->DetachObserver(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_ICSDTPOBSERVER);
			}
		}

	} while (false);*/
}

void MyObserverImpl::Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy)
{
	CAlert::InformationAlert("hello....Update");
}
