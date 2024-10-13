#include "ConsoleWindow.h"
#include <iostream>

UConsoleWindow::UConsoleWindow()
{
}

void UConsoleWindow::BeginPlay()
{
	Clear();
}

void UConsoleWindow::Clear()
{
	system ("cls");

	// 모든 배열을 해당 문자열로 초기화
	BackBuffer.Clear('*'); 
}

void UConsoleWindow::ScreenRender()
{
	for (size_t y = 0; y < BackBuffer.GetImageSizeY(); y++)
	{
		char* Ptr = BackBuffer.GetLine(y);


		printf_s(Ptr);
		printf_s("\n");
	}
}

void UConsoleWindow::SetScreenSize(int _X, int _Y)
{
	// Arr[_Y][_X] 배열 생성 후 문자 '*' 초기화
	BackBuffer.Create(_X, _Y, '*');
}

void UConsoleWindow::WindowSetPixel(int _X, int _Y, char _Text)
{
	
}

