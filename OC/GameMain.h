#pragma once
#include "AbstractScene.h"


class GameMain :
    public AbstractScene
{
private:
    //スコア
    int Score;

   
    //プレイヤー
    int PlayerX;
    int PlayerY;
    int PlayerHP;
    bool PlayerJump;

    //フリーズ
    bool FleezFlg;
    int Fleez1[2];
    int Fleez2[2];
    int a;
    

    //AED
    int AED_Table[4];



public:
    GameMain();


    ~GameMain();

    void Init();

    void SCORE();

    void Player();

    void Fleez();

    

    AbstractScene* Update() override;


    void Draw() const override;
   

};

