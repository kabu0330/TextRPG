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
    Player.SetName("Player"); // 플레이어 이름 세팅
    World.ZoneInit(); // 맵 세팅
    World.PlayerZonePlay(); // 게임 시작
}

TextRpgCore::TextRpgCore()
{
}
