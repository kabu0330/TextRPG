#pragma once

class TextRpgCore
{
public:
	TextRpgCore();

	static void Start(); // static : ��ü ���� �ٷ� ȣ�� ����
	
	static class UPlayer& GetPlayer(); 
};

