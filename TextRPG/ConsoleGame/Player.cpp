#include "Player.h"
#include <conio.h>
#include "GlobalValue.h"
#include "ConsoleEngine.h"
#include "Enums.h"

void Player::BeginPlay()
{
	// BackBuffer에 그려질 플레이어의 좌표와 문자
	PlayerImage.Create({ 2, 2 }, '@');
}

void Player::Tick(ConsoleImage* _BackBuffer)
{
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	GlobalValue::WindowPtr;
	GlobalValue::WindowSize;
	//GlobalValue::BackBuffer = _BackBuffer;

	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (0 != Value)
	{
		int Select = _getch();

		// 입력
		switch (Select)
		{
		case 'a':
		case 'A':
		{
			Dir = Enums::GAMEDIR::LEFT;
			break;
		}
		case 'd':
		case 'D':
		{
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		}
		case 'w':
		case 'W':
		{
			Dir = Enums::GAMEDIR::UP;
			break;
		}
		case 's':
		case 'S':
		{
			Dir = Enums::GAMEDIR::DOWN;
			break;
		}
		default:
			break;
		}

		// 이동
		switch (Dir)
		{
		case Enums::GAMEDIR::LEFT:
		{	
			if (0 < Pos.X)
			{
				Pos += FIntPoint::LEFT;
			}
			break;

		}
		case Enums::GAMEDIR::RIGHT:
		{
			if (Pos.X + PlayerImage.GetImageSizeX() < _BackBuffer->GetImageSizeX())
			{
				Pos += FIntPoint::RIGHT;
			}
			break;
		}
		case Enums::GAMEDIR::UP:
		{
			if (0 < Pos.Y )
			{
				Pos += FIntPoint::UP;
			}
			break;
		}
		case Enums::GAMEDIR::DOWN:
		{
			if (Pos.Y + PlayerImage.GetImageSizeY() < _BackBuffer->GetImageSizeY())
			{
			Pos += FIntPoint::DOWN;
			}
			break;
		}
		default:
			break;
		}
	}

}

void Player::Render(ConsoleImage* _BackBuffer)
{
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}
