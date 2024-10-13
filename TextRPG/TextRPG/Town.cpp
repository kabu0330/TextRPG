#include "Town.h"
#include "Player.h"
#include "TextRpgCore.h"
#include <conio.h>
#include <iostream>


UTown::UTown()
{
}

UZone* UTown::InPlayer()
{
	InMsgPrint();
	UPlayer& _Player = TextRpgCore::GetPlayer();

	while (true)
	{
		system("cls");
		ZonePrint();
		_Player.StatusRender();

		std::cout << "0. 체력 회복 \n";
		std::cout << "1. 강화 \n";
		std::cout << "2. 다른 지역으로 이동 \n";

		int Select = _getch();

		switch (Select)
		{
		case '1':
		{
			break;
		}
		case '2':
		{
			UZone* NextZone = ConnectingProgress();
			return NextZone;
			break;
		}
		case '0':
		{
			printf_s("아직 완성되지 않은 기능입니다. \n");
			return nullptr;
		}
		default:
			break;
		}

	}
	

}
