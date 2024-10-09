#pragma once
#include "AbstractScene.h"


class GameMain :
    public AbstractScene
{
public:
    int BackImg[3];
    int KumoImg;
    int KumoX;
    int KumoY;
    int FloorX;
    int FloorY;
    int FloorX2;
    int FloorY2;

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

 

    void Hit();

    AbstractScene* Update() override;


    void Draw() const override;

    void DrawBackImg();

    void CreateKumo();
   
    void CreateFloor();
};

