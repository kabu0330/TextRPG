#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

void ConsoleEngine::Start()
{
	// 게임 엔진 세팅
	ConsoleEngine Engine;
	Engine.BeginPlay();

	// 게임 로직&렌더 무한 반복
	while (true)
	{
		Engine.Tick();
		Engine.Render();
		Sleep(250);
	}
}

void ConsoleEngine::BeginPlay()
{
	// 처음에는 초기값 0이기 때문에 그리지 않는다. system("cls")만 한다.
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	// ConsoleEngine 멤버 변수인 window의 메모리를 전역에서 접근할 수 있게 함
	GlobalValue::WindowPtr = &Window;

	// 윈도우 사이즈 설정 후 모든 배열에 '*'를 넣는다.
	Window.SetScreenSize(WindowSize);


	NewPlayer.BeginPlay();

}


void ConsoleEngine::Tick()
{
	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Tick(BackBufferPtr);
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Render(BackBufferPtr);

	Window.ScreenRender();
}

ConsoleEngine::ConsoleEngine()
{
}