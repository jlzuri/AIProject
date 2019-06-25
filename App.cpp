#include "App.h"
#include "ServiceLocator.h"
#include "Constants.h"

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
bool App::Initialize()
{
	mSDLService = std::make_unique<SDLService>();
    mInputService = std::make_unique<InputService>();
    mAgentsManager = std::make_unique<AgentsManager>();
    mFlowFieldManager = std::make_unique<FlowFieldManager>(20);

	ServiceLocator::AddService(mSDLService.get(), ServiceType::SDLService);
	ServiceLocator::AddService(mInputService.get(), ServiceType::InputService);
	ServiceLocator::AddService(mFlowFieldManager.get(), ServiceType::FlowFieldManager);
	ServiceLocator::AddService(mAgentsManager.get(), ServiceType::AgentsManager);

	if(!mSDLService->Initialize()) return false;
	if(!mInputService->Initialize()) return false;
	if(!mFlowFieldManager->Initialize()) return false;
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

	mFlowFieldManager->Render(mSDLService->GetRenderer());
	mAgentsManager->Render(mSDLService->GetRenderer());

	mSDLService->AfterRender();
}

//----------------------------------------------------------------------------------------------------------------------
void App::Shutdown()
{
	ServiceLocator::RemoveService(ServiceType::AgentsManager);
	ServiceLocator::RemoveService(ServiceType::FlowFieldManager);
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