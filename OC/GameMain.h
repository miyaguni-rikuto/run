#pragma once
#include "AbstractScene.h"


class GameMain :
    public AbstractScene
{
private:
    //スコア
    int Score;
    int a;
    int c;
    //プレイヤー
    int PlayerX;
    int PlayerY;
    int PlayerHP;
    int PlayerAirTime;
    bool PlayerJump;

  
   
    

    //AED
    int AED_Table[4];



public:
    GameMain();


    ~GameMain();

    void Init();

    void SCORE();

    void Player();

   

    

    AbstractScene* Update() override;


    void Draw() const override;
   

};

