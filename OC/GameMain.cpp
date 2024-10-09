#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
  
    a = LoadSoundMem("source/BGM/destruct.wav");
    c = 0;
    Init();
   
    Score = 2000;

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


void GameMain::Init()
{
   


    PlayerX = 100;
    PlayerY = 400;
    PlayerHP = 3;
    PlayerAirTime = 0;
    PlayerJump = FALSE;
    

  

    c = 1;
   
  
}


void GameMain::SCORE()
{
    
}


void GameMain::Player()
{
    //重力
    if (PlayerY < 400&& PlayerJump == TRUE/* && CheckHitKey(KEY_INPUT_SPACE) == 0*/){
        PlayerY += 20;
    }

    //ジャンプ
    if (PlayerY < 720 && CheckHitKey(KEY_INPUT_SPACE) == 1&& PlayerJump == FALSE) {
        
        PlayerJump = FALSE;
            PlayerAirTime+=1;
            PlayerY -= 20;
            if (PlayerAirTime == 20) {
                PlayerJump = TRUE;
            }
      
    }

    
}





void GameMain::Hit()
{
    if (PlayerY + 70 == FloorY && PlayerX + 50 >= FloorX && PlayerX <= FloorX2 )
    {
        PlayerJump = FALSE;
    }
    else {
       PlayerY = PlayerY + 20;
    }
}


AbstractScene* GameMain::Update()
{
    CreateKumo();
    CreateFloor();
    if (c == 1) {
        ChangeVolumeSoundMem(70, a);
        PlaySoundMem(a, DX_PLAYTYPE_BACK);
    }
    c++;

   
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
    
   
    DrawBox(0, 0, 1280, 720, 0x00BFFF, TRUE);


    DrawGraph(0, 0, BackImg[0], TRUE);
    DrawGraph(KumoX, KumoY, KumoImg, TRUE);

    DrawBox(FloorX, FloorY, FloorX2, FloorY2, 0xffffff, TRUE);



    //Player
    DrawBox(PlayerX,PlayerY,PlayerX+50,PlayerY+70, 0xffffff, FALSE);
  
    //UI
    DrawBox(0, 620, 1280, 720, 0xFF0000, TRUE);

    DrawBox(10, 630, 1270, 710, 0x000000, TRUE);

    DrawFormatString(1050, 20, 0xffffff, "Total : %d M", Score);







  
}


