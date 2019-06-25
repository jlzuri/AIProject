#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <SDL.h>

namespace AIProject
{

class Color
{
public:
	static constexpr SDL_Color Black = { 0, 0, 0, 255 };
	static constexpr SDL_Color White = { 255, 255, 255, 255 };
	static constexpr SDL_Color Red = { 255, 0, 0, 255 };
	static constexpr SDL_Color Blue = { 0, 255, 0, 255 };
	static constexpr SDL_Color Green = { 0, 0, 255, 255 };
	static constexpr SDL_Color Yellow = { 255, 255, 0, 255 };
	static constexpr SDL_Color Cyan = { 0, 255, 255, 255 };
	static constexpr SDL_Color Magenta = { 255, 0, 255, 255 };
};

}

#endif //GAME_CONSTANTS_H
