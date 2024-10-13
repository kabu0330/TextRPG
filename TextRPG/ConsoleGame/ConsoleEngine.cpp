#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

void ConsoleEngine::Start()
{
	// ���� ���� ����
	ConsoleEngine Engine;
	Engine.BeginPlay();

	// ���� ����&���� ���� �ݺ�
	while (true)
	{
		Engine.Tick();
		Engine.Render();
		Sleep(250);
	}
}

void ConsoleEngine::BeginPlay()
{
	// ó������ �ʱⰪ 0�̱� ������ �׸��� �ʴ´�. system("cls")�� �Ѵ�.
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	// ConsoleEngine ��� ������ window�� �޸𸮸� �������� ������ �� �ְ� ��
	GlobalValue::WindowPtr = &Window;

	// ������ ������ ���� �� ��� �迭�� '*'�� �ִ´�.
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