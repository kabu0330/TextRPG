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

	// ��� �迭�� �ش� ���ڿ��� �ʱ�ȭ
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
	// Arr[_Y][_X] �迭 ���� �� ���� '*' �ʱ�ȭ
	BackBuffer.Create(_X, _Y, '*');
}

void UConsoleWindow::WindowSetPixel(int _X, int _Y, char _Text)
{
	
}

