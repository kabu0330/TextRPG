#include "Player.h"
#include <iostream>

UPlayer::UPlayer()
{
	UObject* ObjectPtr = this; // 업캐스팅이 가능하니까.
}

void UPlayer::StatusTextRender() 
{
	printf_s("공격력 : %d ~ %d + %d \n", MinAtt, MaxAtt, EquipAtt);
	printf_s("체력 : %d\n", Hp);
	printf_s("골드 : %d\n", Gold);

}
