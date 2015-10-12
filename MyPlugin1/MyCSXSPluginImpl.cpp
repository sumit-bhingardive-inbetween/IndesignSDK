#include "VCPlugInHeaders.h"
#include "MyObserverImpl.h"
#include "ICSXSPlugPlugEventHandler.h"
#include "MyCSXSPluginImpl.h"
#include "FileTypeRegistry.h"
#include "PMString.h"

CREATE_PMINTERFACE(MyCSXSPluginImpl, kMyCSXSPluginImpl)

MyCSXSPluginImpl::MyCSXSPluginImpl(IPMUnknown* boss)
{
}

MyCSXSPluginImpl::~MyCSXSPluginImpl()
{
}

void dispatchEventForExtention() {

	InterfacePtr<ICSXSPlugPlugEventHandler> plugPlug(GetExecutionContextSession(), UseDefaultIID());// InterfacePtr is a iterface pointer (Template class) which is used to dispatch event by creating "plugPlug" object of ICSXSPlugPlugEventHandler type.
	PMString csxsEventStr;
	csxsEventStr.SetCString("Hello from CPP!");
	PMString eventData(csxsEventStr);
	std::string csxsEventUtf8;
	//adobe::to_utf8(csxsEventStr.begin(), csxsEventStr.end(), std::back_inserter(csxsEventUtf8));

	ICSXSPlugPlugEventHandler::CSXSEvent responseEvent;
	responseEvent.type = "com.adobe.indesign.scriptingcomms.html";// Type of the responseEvent
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

	plugPlug->DispatchPlugPlugEvent(&responseEvent);// ICSXSPlugPlugEventHandler contains this method DispatchPlugPlugEvent.

}