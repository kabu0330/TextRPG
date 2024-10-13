#pragma once

class TextRpgCore
{
public:
	TextRpgCore();

	static void Start(); // static : 객체 없이 바로 호출 가능
	
	static class UPlayer& GetPlayer(); 
};

