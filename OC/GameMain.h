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
    


public:
    GameMain();


    ~GameMain();


    AbstractScene* Update() override;


    void Draw() const override;

    void DrawBackImg();

    void CreateKumo();
   
    void CreateFloor();
};

