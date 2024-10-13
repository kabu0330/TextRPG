#include "ConsoleImage.h"

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	// ����ڵ� : �迭�� ���� ���� ���ٸ�
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
	// �Ű����� ���� �޾� ��� ������ �����Ѵ�.
	X = _X;
	Y = _Y;

	// _Y ������ŭ char �����͸� �����.
	// Arr : �����͸� ����Ű�� ������ : ���� ������
	Arr = new char* [_Y];

	for (size_t y = 0; y < _Y; y++)
	{
		// char (_X + 1) �� ũ�� ��ŭ �� �޸𸮸� �����ϰ�
		// Arr[y] �����Ϳ� �ּҸ� �Ѱ��ش�.
		// �̷ν� Arr[_Y][_X + 1]�� 2���� �迭�� �ȴ�.
		Arr[y] = new char[_X + 1];
	}
	int Size = sizeof(Arr);

	// �迭�� ���� ���� ��� �ʱ�ȭ���ش�.
	Clear(_BaseChar);
}

// Player�� �׷��ش�
void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	for (int y = 0; y < _Image.GetImageSizeY(); y++)
	{
		for (int x = 0; x < _Image.GetImageSizeX(); x++)
		{
			// Player�κ��� ���� ��ǥ���� ���� SetPos�� �޴´�
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };
			
			// Player�� �̹��� ���ڸ� X�� �����Ѵ�?
			char X = _Image.GetPixel(x, y);

			// �׸� ��ġ SetPos�� Player �̹��� X�� �����Ѵ�.
			SetPixel(SetPos, X);
		}
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	// ����ڵ� : ȭ�� �ٱ��� �׷����� �ʰ� �Ѵ�.
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
