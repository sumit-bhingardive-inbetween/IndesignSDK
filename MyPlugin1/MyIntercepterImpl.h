#include "ICommandInterceptor.h"

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

class MyIntercepterImpl : public ICommandInterceptor
{

//public:
//	enum { kDefaultIID = IID_ICOMMANDINTERCEPTOR };
//
//	// Each interception method should return one of the following values.
//	typedef enum
//	{
//		kCmdNotHandled,			// command should get passed on to other interceptors
//		// 		they will decide whether to process it
//		kCmdNotHandledSkipInterceptors,
//		// command should get processed, other interceptors
//		// 		should get skipped
//		kCmdHandled				// command should not get processed, other interceptors
//		//		should get skipped
//	} InterceptResult;

	virtual InterceptResult InterceptProcessCommand(ICommand *cmd);
	virtual InterceptResult InterceptScheduleCommand(ICommand *cmd);

	/** DEPRICATED
	Avoid using this function if possible - this is legacy and is deprecated.
	*/
	virtual InterceptResult InterceptExecuteDynamic(ICommand * cmd);

	// install/deinstall itself as command interceptor
	virtual void InstallSelf();
	virtual void DeinstallSelf();

	// these will eventually go away
	virtual InterceptResult InterceptExecuteImmediate(ICommand * cmd);

};