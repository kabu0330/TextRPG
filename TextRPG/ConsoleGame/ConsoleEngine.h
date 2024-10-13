#pragma once
#include "Player.h"
#include "BaseSystem/EngineMath.h"
#include "ConsoleWindow.h"

class ConsoleEngine
{
public:
	static void Start();

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}
	

private:
	ConsoleEngine();

	Player NewPlayer;
	static UConsoleWindow Window;
	static FIntPoint WindowSize;

	void BeginPlay();

	void Tick();
	void Render();
};

