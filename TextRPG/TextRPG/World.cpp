#include "World.h"

void UWorld::ZoneInit()
{
	Town0.SetName("초보마을");
	Town1.SetName("중급마을");
	FZone0.SetName("초보사냥터");
}

void UWorld::PlayerZonePlay()
{
	UZone* CurZone = &Town0;

	while (true)
	{
		CurZone = CurZone->InPlayer();
	}
}
