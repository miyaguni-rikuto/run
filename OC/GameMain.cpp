#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    BackImg[0] = LoadGraph("source/img/Hiru.jpg");
    BackImg[1] = LoadGraph("source/img/Yu.png");
    BackImg[2] = LoadGraph("source/img/Yoru.jpg");
    KumoImg = LoadGraph("source/img/kumo.png");
   

    KumoX = 0;
    KumoY = 10;

    FloorX = 300;
    FloorY = 300;
    FloorX2 = 700;
    FloorY2 = 350;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
    CreateKumo();
    CreateFloor();
    return this;
}

void GameMain::DrawBackImg()
{

}


void GameMain::CreateKumo()
{
    if (KEY_INPUT_D) {
        KumoX--;
    }
    if (KumoX < -290) {
        KumoX = 1280;
        KumoY = GetRand(200);
    }
    
}

void GameMain::CreateFloor()
{
  

    if (FloorX > 340 && FloorX2 > 740) {
        FloorX--;
        FloorX2--;
    }
    if (FloorX = 340 && FloorX2 = 740) {
        FloorX++;
        FloorX2++;
    }
    
}

void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    

    DrawBox(0, 0, 1280, 100, 0xffffff, FALSE);

    DrawGraph(0, 0, BackImg[0], TRUE);
    DrawGraph(KumoX, KumoY, KumoImg, TRUE);

    DrawBox(FloorX, FloorY, FloorX2, FloorY2, 0xffffff, TRUE);
}


