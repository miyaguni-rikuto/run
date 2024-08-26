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
    KumoX -= 2;

    if (KumoX < -290) {
        KumoX = 1280;
        KumoY = GetRand(150)+50;
    }
    
}

void GameMain::CreateFloor()
{
    FloorX -= 5;
    FloorX2 -= 5;

    if (FloorX2 < 0) {
        FloorX = 1280;  // 床を画面の右端に再配置
        FloorX2 = FloorX + 200; // 固定の幅を持つ新しい床 (例: 100ピクセル)
        FloorY = GetRand(200)+400;  // 固定のY座標
        FloorY2 = FloorY + 50; // 固定の高さ (例: 50ピクセル)
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


