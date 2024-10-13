#pragma once
#include "Actor.h"

class UPlayer : public AActor
{
public:
	UPlayer();

	void StatusTextRender() override;

private:
	int EquipAtt = 0;
};

