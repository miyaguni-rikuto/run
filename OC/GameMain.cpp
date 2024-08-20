#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{

   
   
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
   
    return this;
}

void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    

    DrawBox(0, 0, 1280, 100, 0xffffff, FALSE);

}
