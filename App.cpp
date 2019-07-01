#include "App.h"
#include "ServiceLocator.h"

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
bool App::Initialize()
{
	mSDLService = std::make_unique<SDLService>();
    mInputService = std::make_unique<InputService>();
    mAgentsManager = std::make_unique<AgentsManager>();

	ServiceLocator::AddService(mSDLService.get(), ServiceType::SDLService);
	ServiceLocator::AddService(mInputService.get(), ServiceType::InputService);
	ServiceLocator::AddService(mAgentsManager.get(), ServiceType::AgentsManager);

	if(!mSDLService->Initialize()) return false;
	if(!mInputService->Initialize()) return false;
	if(!mAgentsManager->Initialize()) return false;


	return true;
}

//----------------------------------------------------------------------------------------------------------------------
void App::Update()
{
	mInputService->Update();
	mAgentsManager->Update();
}

//----------------------------------------------------------------------------------------------------------------------
void App::Render()
{
	mSDLService->BeforeRender();

	mAgentsManager->Render(mSDLService->GetRenderer());

	mSDLService->AfterRender();
}

//----------------------------------------------------------------------------------------------------------------------
void App::Shutdown()
{
	ServiceLocator::RemoveService(ServiceType::AgentsManager);
	ServiceLocator::RemoveService(ServiceType::InputService);
	ServiceLocator::RemoveService(ServiceType::SDLService);
}

//----------------------------------------------------------------------------------------------------------------------
void App::OnEvent(SDL_Event *event) {
	switch(event->type)
	{
	case SDL_QUIT: {
		OnExit();
		break;
	}
	default:
		mInputService->ProcessInputEvent(event);
		break;
	}
}

//----------------------------------------------------------------------------------------------------------------------
void App::OnExit()
{
    mRunning = false;
}

//----------------------------------------------------------------------------------------------------------------------
bool App::IsRunning()
{
    return mRunning;
}

}