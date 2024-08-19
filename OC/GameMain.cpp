#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    player = new Player;
    floor = new Floor;
    hitbox = new HitBox;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
    player->Update();
    hitbox->Update();
    return this;
}

void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    player->Draw();
    floor->Draw();
    hitbox->Draw();

    DrawBox(0, 0, 1280, 100, 0xffffff, FALSE);
}
