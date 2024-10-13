#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "�� �����߽��ϴ�.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "�� ü�� ��. \n";
}

bool UZone::IsConnecting(UZone* _ConnectingZone)
{
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (_ConnectingZone == ConnectingZones[i])
		{
			return true;
		}
	}
	return false;
}

bool UZone::InterConnecting(UZone* _LinkZone)
{
	this->Connecting(_LinkZone);
	_LinkZone->Connecting(this);

	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	// ����ڵ�
	if (this == _LinkZone)
	{
		MSGASSERT("�ڱ� �ڽ��� ������ ���� �����ϴ�.");
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("�̹� ����� �����Դϴ�.");
		return false;
	}
	//

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i]) // ����ִ� �迭�� ������
		{
			ConnectingZones[i] = _LinkZone; // �� ���� ������� ����
			SelectMax += 1;

			return true;
		}
	}
	
	MSGASSERT("�� �̻� ������ ������ �����ϴ�.");
	return false;
}


UZone* UZone::ConnectingProgress()
{
	while (true)
	{
		ConnectingPrint();

		int Select = _getch();
		Select -= '0';
		
		if (Select >= 1 && Select <= SelectMax)
		{
			return ConnectingZones[Select - 1];
		}

	}
	return nullptr;
}

void UZone::ConnectingPrint()
{
	system("cls");

	int StartIndex = 1;

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr != ConnectingZones[i])
		{
			const char* NamePtr = ConnectingZones[i]->GetName();

			printf_s("%d. %s�� �̵�. \n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}

}