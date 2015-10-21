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
#include "MyIntercepterImpl.h"
//#include "ICommandInterceptor.h"

CREATE_PMINTERFACE(MyIntercepterImpl, kMyIntercepterImpl)

InterceptResult MyIntercepterImpl::InterceptProcessCommand(ICommand *cmd){
	return kCmdHandled;
}

InterceptResult MyIntercepterImpl::InterceptScheduleCommand(ICommand *cmd){
	return kCmdHandled;
}

InterceptResult MyIntercepterImpl::InterceptExecuteDynamic(ICommand *cmd){
	return kCmdHandled;
}

void MyIntercepterImpl::InstallSelf(){
}
void MyIntercepterImpl::DeinstallSelf(){
}

InterceptResult MyIntercepterImpl::InterceptExecuteImmediate(ICommand * cmd){
	return kCmdHandled;
}