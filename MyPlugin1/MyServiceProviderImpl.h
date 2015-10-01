
#ifndef _CSDTPSERVICEPROVIDERIMPL_H_
#define _CSDTPSERVICEPROVIDERIMPL_H_

//includes
#include "VCPlugInHeaders.h"
#include "CServiceProvider.h"
#include "InterfaceFactory.h"
#include "K2Vector.h"

//project includes
#include "MP1ID.h"

class MyServiceProviderImpl : public CServiceProvider
{
public:
	MyServiceProviderImpl(IPMUnknown*);
	~MyServiceProviderImpl();

	/*@Interface
	GetName() initializes the name of the service.
	@param pName Ptr to PMString to receive the name.
	*/
	virtual void GetName(PMString* pName);

	/*@Interface
	GetServiceID() returns a single service ID.  This is required, even though
	GetServiceIDs() will return the complete list initialized in the constructor.
	This method just returns the first service ID in the list.
	*/
	virtual ServiceID GetServiceID();

	/*@Interface
	*/
	virtual bool16 IsDefaultServiceProvider();

	/*@Interface
	GetInstantiationPolicy() returns a InstancePerX value to indicate that only
	one instance per session is needed.
	*/
	virtual InstancePerX GetInstantiationPolicy();

	/*@Interface
	HasMultipleIDs() returns true in order to force a call to GetServiceIDs().
	*/
	virtual bool16 HasMultipleIDs() const;

	/*@Interface
	GetServiceIDs() returns a list of services provided.
	@param serviceIDs List of IDs describing the services that
	CSDTPServiceProviderImpl registers to handle.
	*/
	virtual void GetServiceIDs(K2Vector<ServiceID>& serviceIDs);

private:

	K2Vector<ServiceID> fSupportedServiceIDs;

	/*addResponder() add the services for which Notification is required
	*/
	void addResponder();


};

#endif //_CSDTPSERVICEPROVIDERIMPL_H_
