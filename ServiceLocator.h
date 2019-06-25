#ifndef GAME_SERVICELOCATOR_H
#define GAME_SERVICELOCATOR_H

#include <array>

namespace AIProject
{

class IService;

enum class ServiceType
{
	SDLService,
	InputService,
	AgentsManager,
	FlowFieldManager,
	Count,
	Invalid
};

class ServiceLocator
{
public:
	static IService* GetService(ServiceType serviceType);
	static bool AddService(IService* service, ServiceType serviceType);
	static bool RemoveService(ServiceType serviceType);

private:
	ServiceLocator() {}

private:
	static ServiceLocator sInstance;
	std::array<IService*, (int)ServiceType::Count> sServices;
};

}


#endif //GAME_SERVICELOCATOR_H
