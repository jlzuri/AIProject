#include "InputService.h"
#include "InputListener.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
bool InputService::AddListener(InputListener *listener, SDL_EventType eventType) {
	if (listener == nullptr) {
		//invalid listener
		return false;
	}

	auto range = mListeners.equal_range(eventType);
	for (auto it = range.first; it != range.second; ++it) {
		if (it->second == listener) {
			//listener already registered for this eventType
			return false;
		}
	}

	mListeners.insert(std::make_pair(eventType, listener));
	return true;
}

//remove listener from given event type
//----------------------------------------------------------------------------------------------------------------------
bool InputService::RemoveListener(InputListener *listener, SDL_EventType eventType) {
	if (listener != nullptr) {
		auto range = mListeners.equal_range(eventType);
		for (auto it = range.first; it != range.second; ++it) {
			if (it->second == listener) {
				mListeners.erase(it);
				return true;
			}
		}
	}
	return false;
}

//Remove listener from all event types
//----------------------------------------------------------------------------------------------------------------------
bool InputService::RemoveListener(InputListener *listener) {
	bool found = false;
	if (listener != nullptr) {
		for (auto it = mListeners.begin(); it != mListeners.end(); ++it) {
			if (it->second == listener) {
				it = mListeners.erase(it);
				found = true;
			}
		}
	}
	return found;
}

//----------------------------------------------------------------------------------------------------------------------
void InputService::NotifyListeners(SDL_Event *event) {
//	Multimap implementation.
//	auto range = mListeners.equal_range((SDL_EventType)event->type);
//	for(auto it = range.first; it != range.second; ++it)
//	{
//		InputListener* listener = it->second;
//		listener->OnInputEvent(event);
//	}

	auto it = mListeners.find((SDL_EventType) event->type);
	if (it != mListeners.end()) {
		InputListener *listener = it->second;
		listener->OnInputEvent(event);
	}
}

//----------------------------------------------------------------------------------------------------------------------
void InputService::ProcessInputEvent(SDL_Event *event) {
	NotifyListeners(event);
}

}