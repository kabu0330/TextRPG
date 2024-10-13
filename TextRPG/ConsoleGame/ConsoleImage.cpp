#include "ConsoleImage.h"

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	// 방어코드 : 배열을 만든 적이 없다면
	if (0 == X || 0 == Y)
	{
		return;
	}

	for (size_t y = 0; y < Y; y++)
	{
		delete[] Arr[y];
	}
	delete[] Arr;
}

void ConsoleImage::Clear(char _ClearChar)
{
	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			Arr[y][x] = _ClearChar;
		}
		Arr[y][X] = 0;
	}
}

void ConsoleImage::Create(int _X, int _Y, char _BaseChar)
{
	// 매개변수 값을 받아 멤버 변수에 대입한다.
	X = _X;
	Y = _Y;

	// _Y 개수만큼 char 포인터를 만든다.
	// Arr : 포인터를 가리키는 포인터 : 더블 포인터
	Arr = new char* [_Y];

	for (size_t y = 0; y < _Y; y++)
	{
		// char (_X + 1) 의 크기 만큼 힙 메모리를 생성하고
		// Arr[y] 포인터에 주소를 넘겨준다.
		// 이로써 Arr[_Y][_X + 1]의 2차원 배열이 된다.
		Arr[y] = new char[_X + 1];
	}
	int Size = sizeof(Arr);

	// 배열의 문자 값을 모두 초기화해준다.
	Clear(_BaseChar);
}

// Player를 그려준다
void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	for (int y = 0; y < _Image.GetImageSizeY(); y++)
	{
		for (int x = 0; x < _Image.GetImageSizeX(); x++)
		{
			// Player로부터 받은 좌표값을 더해 SetPos로 받는다
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };
			
			// Player의 이미지 문자를 X에 저장한다?
			char X = _Image.GetPixel(x, y);

			// 그릴 위치 SetPos에 Player 이미지 X를 대입한다.
			SetPixel(SetPos, X);
		}
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	// 방어코드 : 화면 바깥에 그려지지 않게 한다.
	if (0 > _Pos.X || X < _Pos.X)
	{
		return;
	}
	if (0 > _Pos.Y || Y < _Pos.Y)
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Char;
}
