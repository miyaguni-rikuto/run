#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    FleezSE = LoadSoundMem("source/SE/Fleez.mp3");
    FleezSE2 = LoadSoundMem("source/SE/Freez.mp3");
    a = LoadSoundMem("source/BGM/destruct.wav");
    c = 0;
    Init();
    FleezTime = 0;
    Score = 2000;

}


GameMain::~GameMain()
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


void GameMain::Init()
{
   


    PlayerX = 100;
    PlayerY = 400;
    PlayerHP = 3;
    PlayerAirTime = 0;
    PlayerJump = FALSE;
    

    FleezFlg = FALSE/*TRUE*/;
    Fleez1[0] = 320;
    Fleez1[1] = 400;
    Fleez2[0] = 330;
    Fleez2[1] = 390;

    c = 1;
   
  
}


void GameMain::SCORE()
{
    Score++;
    if (Score == 2400)
    {
        FleezFlg = TRUE;
    }
}


void GameMain::Player()
{
    //重力
    if (PlayerY < 400&& PlayerJump == TRUE/* && CheckHitKey(KEY_INPUT_SPACE) == 0*/){
        PlayerY += 20;
    }

    //ジャンプ
    if (PlayerY < 720 && CheckHitKey(KEY_INPUT_SPACE) == 1&& PlayerJump == FALSE) {
        
            PlayerAirTime+=1;
            PlayerY -= 20;

            if (PlayerAirTime == 20) {
                PlayerJump = TRUE;
            }

        
      
    }

    
}


void GameMain::Fleez()
{
    if (FleezFlg == TRUE) {


        FleezTime++;
        if (FleezTime == 1)
        {
            StopSoundMem(a);
            PlaySoundMem(FleezSE2, DX_PLAYTYPE_BACK);
        }
        if (FleezTime == 6)
        {
           
            PlaySoundMem(FleezSE, DX_PLAYTYPE_BACK);
           
        }
        if (FleezTime >= 6) {

           

            if (Fleez1[0] != 360) {
                Fleez1[0] += 5;
                Fleez1[1] -= 5;

            }
            if (Fleez2[0] != 360) {

                Fleez2[0] += 5;
                Fleez2[1] -= 5;

            }

        }
      
    }
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
    if (c == 1) {
        ChangeVolumeSoundMem(70, a);
        PlaySoundMem(a, DX_PLAYTYPE_BACK);
    }
    c++;
    
    if (FleezFlg == FALSE) {
        SCORE();
        Player();
       
    }
    Fleez();
    return this;
}


void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    
   
    DrawBox(0, 0, 1280, 720, 0x00BFFF, TRUE);





    DrawBox(PlayerX,PlayerY,PlayerX+50,PlayerY+70, 0xffffff, FALSE);
   


  
    //UI
    DrawBox(0, 620, 1280, 720, 0xFF0000, TRUE);

    DrawBox(10, 630, 1270, 710, 0x000000, TRUE);

    DrawFormatString(1050, 20, 0xffffff, "Total : %d M", Score);







    //フリーズ
    if (FleezFlg == TRUE) 
    {
        
            DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
        
       
        if (FleezTime >= 1 && FleezTime < 6)
        {
            DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);


        }
        if (FleezTime >= 6)
        {
            DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
            DrawBox(0, Fleez1[0], 1280, Fleez1[1], 0x0000FF, TRUE);
            DrawBox(0, Fleez2[0], 1280, Fleez2[1], 0xffffff, TRUE);



        }
      /*  if (FleezTime > 6&&FleezTime<20)
        {
            DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
        
        }

        if (FleezTime >= 20 && FleezTime < 30)
        {
            DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);

    DrawGraph(0, 0, BackImg[0], TRUE);
    DrawGraph(KumoX, KumoY, KumoImg, TRUE);

    DrawBox(FloorX, FloorY, FloorX2, FloorY2, 0xffffff, TRUE);
        }*/
    }
}


