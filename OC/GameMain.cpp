#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    Init();
    a = 0;
    Score = 0;
}


GameMain::~GameMain()
{
}


void GameMain::Init()
{
   


    PlayerX = 100;
    PlayerY = 400;
    PlayerHP = 3;
    PlayerJump = FALSE;
    

    FleezFlg = FALSE/*TRUE*/;
    Fleez1[0] = 320;
    Fleez1[1] = 400;
    Fleez2[0] = 330;
    Fleez2[1] = 390;
   
   
}


void GameMain::SCORE()
{
    Score++;
}



void GameMain::Player()
{
    //重力
    if(PlayerY <=400&& CheckHitKey(KEY_INPUT_SPACE) == 0){
        PlayerY += 5;
    }

    //ジャンプ
    if (PlayerY < 720 && CheckHitKey(KEY_INPUT_SPACE) == 1) {
        PlayerY -= 5;
    }

    //
}


void GameMain::Fleez()
{
   
   if (Fleez1[0] != 360) {
       Fleez1[0] += 5;
       Fleez1[1] -= 5;
      
   }
   if (Fleez2[0] != 360) {
     
       Fleez2[0] += 5;
       Fleez2[1] -= 5;
   }
  


}



AbstractScene* GameMain::Update()
{
   /* SCORE();*/
    Player();
 /*   a++;
    if (a >= 120) {
        FleezFlg = TRUE;
        Fleez();
    }*/
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
    if (a >= 115)
    {
        DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
    }
    if (FleezFlg == TRUE)
    {
        DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
        DrawBox(0, Fleez1[0], 1280, Fleez1[1], 0x0000FF, TRUE);
        DrawBox(0, Fleez2[0], 1280, Fleez2[1], 0xffffff, TRUE);
       
        
    }
}
