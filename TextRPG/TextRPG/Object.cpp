#include "Object.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>

void UObject::SetName(const char* const _Name)
{
	if (static_cast<int>(Enums::MAXS::NAMEMAX) <= strlen(_Name))
	{
		MSGASSERT("이름이 너무 깁니다.");
		return;
	}

	strcpy_s(Name, _Name);
}

void UObject::TopLine()
{
	const char* Name = GetName();
	printf_s("%s Status", Name);
	
	int NameLen = static_cast<int>(strlen(Name));
	int StatusLen = static_cast<int>(strlen("Status"));
	int NameLineCount = static_cast<int>(Enums::MAXS::LINECOUNT) - NameLen - StatusLen;

	for (int i = 0; i < NameLineCount; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
}

void UObject::botLine()
{
	for (int i = 0; i < static_cast<int>(Enums::MAXS::LINECOUNT); i++)
	{
		printf_s("-");
	}
	printf_s("\n");
}
