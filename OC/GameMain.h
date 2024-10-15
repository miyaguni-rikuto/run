#pragma once
#include "AbstractScene.h"


class GameMain :
    public AbstractScene
{
public:
    int BackImg[3];
    int CharaImg;
    int CharaImgX;
    int CharaImgY;
    int KumoImg;
    int KumoX;
    int KumoY;
    int FloorX;
    int FloorY;
    int FloorX2;
    int FloorY2;

    int  previousFloorX;



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

    //フリーズ
    bool FleezFlg;
    int Fleez1[2];
    int Fleez2[2];
    int FleezSE;
    int FleezSE2;
    int FleezTime;
    

    //AED
    int AED_Table[4];



public:
    GameMain();


    ~GameMain();

    void Init();

    void SCORE();

    void Player();

    void Fleez();

    void Hit();

    AbstractScene* Update() override;


    void Draw() const override;

    void DrawBackImg();

    void CreateKumo();
   
    void CreateFloor();
};

