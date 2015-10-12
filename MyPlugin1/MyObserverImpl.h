#include "VCPlugInHeaders.h"
#include "MP1ID.h"
#include "SelectionObserver.h"

class MyObserverImpl : public CObserver
{
public:
	MyObserverImpl(IPMUnknown* boss);
	virtual ~MyObserverImpl();

	/*
	@Interface
	*AutoAttach() attaches the Observer on the document
	*/
	void AutoAttach();

	/*
	@Interface
	*AutoDetach() detaches the Observer from the document
	*/
	void AutoDetach();

	void Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy);
};