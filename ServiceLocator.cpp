#include "ServiceLocator.h"
#include "IService.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
ServiceLocator ServiceLocator::sInstance;

//----------------------------------------------------------------------------------------------------------------------
IService *ServiceLocator::GetService(ServiceType serviceType) {
	return sInstance.sServices[(int) serviceType];
}

//----------------------------------------------------------------------------------------------------------------------
bool ServiceLocator::AddService(IService *service, ServiceType serviceType) {
	if (service == nullptr) {
		printf("Trying to insert a null IService");
		return false;
	}

	if (sInstance.sServices[(int) serviceType] != nullptr) {
		return false;
	}

	sInstance.sServices[(int) serviceType] = service;
	return true;
}

//----------------------------------------------------------------------------------------------------------------------
bool ServiceLocator::RemoveService(ServiceType serviceType) {
	sInstance.sServices[(int) serviceType] = nullptr;
	return true;
}

}