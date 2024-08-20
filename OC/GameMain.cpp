#include "DxLib.h"
#include "GameMain.h"
#include"StageBack.h"

GameMain::GameMain()
{

    player = new Player;
    floor = new Floor;
    hitbox = new HitBox;
    stageback = new StageBack;

   
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
    player->Update();
    hitbox->Update();
    stageback->Update();
    return this;
}

void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    player->Draw();
    floor->Draw();
    hitbox->Draw();
    stageback->Draw();

    DrawBox(0, 0, 1280, 100, 0xffffff, FALSE);

}
