#pragma once
#include "Town.h"
#include "FightZone.h"

// 모든 맵을 관리하는 관리자 개념
class UWorld
{
public:
	void ZoneInit();

	void PlayerZonePlay();

	UTown Town0;
	UTown Town1;
	UFightZone FZone0;

};

