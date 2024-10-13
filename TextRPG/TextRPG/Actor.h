#pragma once
#include "Object.h"
#include "StatusUnit.h"

class AActor : public UObject, public UStatusUnit
{
public:
	void StatusRender();

	virtual void StatusTextRender() {}
};

