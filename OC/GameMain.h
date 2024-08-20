#pragma once
#include "AbstractScene.h"


class GameMain :
    public AbstractScene
{
private:



public:
    GameMain();


    ~GameMain();


    AbstractScene* Update() override;


    void Draw() const override;
   
};

