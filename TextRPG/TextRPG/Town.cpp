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

		std::cout << "0. ü�� ȸ�� \n";
		std::cout << "1. ��ȭ \n";
		std::cout << "2. �ٸ� �������� �̵� \n";

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
			printf_s("���� �ϼ����� ���� ����Դϴ�. \n");
			return nullptr;
		}
		default:
			break;
		}

	}
	

}
