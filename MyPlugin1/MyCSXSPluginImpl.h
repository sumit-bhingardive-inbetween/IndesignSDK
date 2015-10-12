#include "MP1ID.h"
#include "VCPlugInHeaders.h"
#include "adobe/unicode.hpp" // for adobe::to_utf8

class MyCSXSPluginImpl {

public:
	MyCSXSPluginImpl(IPMUnknown* boss);
	virtual ~MyCSXSPluginImpl();

	void dispatchEventForExtention();
};