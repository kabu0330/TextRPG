#pragma once
#include "Enums.h"

class UObject
{
public:
	void SetName(const char* const _Name);

	inline const char* GetName() const
	{
		return Name;
	}

	void TopLine();
	void botLine();
	
private:
	char Name[static_cast<int>(Enums::MAXS::NAMEMAX)];
};

