#include "TextRpgCore.h"
#include "Player.h"
#include "World.h"

UPlayer Player;
UWorld World;

UPlayer& TextRpgCore::GetPlayer()
{
    return Player;
}

void TextRpgCore::Start()
{
    Player.SetName("Player"); // �÷��̾� �̸� ����
    World.ZoneInit(); // �� ����
    World.PlayerZonePlay(); // ���� ����
}

TextRpgCore::TextRpgCore()
{
}
