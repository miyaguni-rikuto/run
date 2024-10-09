#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
  
    a = LoadSoundMem("source/BGM/destruct.wav");
    c = 0;
    Init();
   
    Score = 2000;

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
    Score++;
    if (Score == 2400)
    {
      
    }
}


void GameMain::Player()
{
    //重力
    if (PlayerY < 400&& PlayerJump == TRUE/* && CheckHitKey(KEY_INPUT_SPACE) == 0*/){
        PlayerY += 10;
    }

    //ジャンプ
    if (PlayerY < 720 && CheckHitKey(KEY_INPUT_SPACE) == 1&& PlayerJump == FALSE) {
        
            PlayerAirTime+=1;
            PlayerY -= 20;

            if (PlayerAirTime == 10) {
                PlayerJump = TRUE;
            }

        
      
    }

    
}





AbstractScene* GameMain::Update()
{
   
    Player();
  
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







}
