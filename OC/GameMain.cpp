#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    BackImg[0] = LoadGraph("source/img/Hiru.jpg");
    BackImg[1] = LoadGraph("source/img/Yu.png");
    BackImg[2] = LoadGraph("source/img/Yoru.jpg");
    KumoImg = LoadGraph("source/img/kumo.png");
   

    KumoX = 0;
    KumoY = 5;

    FloorX = 300;
    FloorX2 = 700;

    FloorY = 300;
    FloorY2 = 350;

    FloorX3 = 300;
    FloorY3 = 100;
    FloorX4 = 700;
    FloorY4 = 100;
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
    FloorX -= 5.5;
    FloorX2 -= 5.5;

    if (FloorX2 < 0) {
        FloorX = 1280;  // 床を画面の右端に再配置
        FloorX2 = FloorX + 200; // 固定の幅を持つ新しい床 (例: 100ピクセル)
        FloorY = GetRand(200)+400;  // 固定のY座標
        FloorY2 = FloorY + 50; // 固定の高さ (例: 50ピクセル)
    }

    // 上に配置される新しい床
    FloorX3 -= 5;
    FloorX4 -= 5;

    if (FloorX4 < 0) {
        FloorX3 = 1280;
        FloorX4 = FloorX3 + 100;

        // 上の方にランダムな高さで配置 (例: 100～200の範囲)
        FloorY3 = GetRand(200) +( KumoY + 50);
        FloorY4 = FloorY3 + 50;
    }
}

void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    

    DrawBox(0, 0, 1280, 100, 0xffffff, FALSE);

    DrawGraph(0, 0, BackImg[0], TRUE);
    DrawGraph(KumoX, KumoY, KumoImg, TRUE);

    DrawBox(FloorX, FloorY, FloorX2, FloorY2, 0xffffff, TRUE);

    DrawBox(FloorX3, FloorY3, FloorX4, FloorY4, 0xffffff, TRUE);
}


