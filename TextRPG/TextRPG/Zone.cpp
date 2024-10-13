#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "에 체류 중. \n";
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
	// 방어코드
	if (this == _LinkZone)
	{
		MSGASSERT("자기 자신을 연결할 수는 없습니다.");
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역입니다.");
		return false;
	}
	//

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i]) // 비어있는 배열이 있으면
		{
			ConnectingZones[i] = _LinkZone; // 빈 곳에 순서대로 대입
			SelectMax += 1;

			return true;
		}
	}
	
	MSGASSERT("더 이상 연결할 공간이 없습니다.");
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

			printf_s("%d. %s로 이동. \n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}

}