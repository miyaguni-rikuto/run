#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Floor.h"
#include"HitBox.h"
class GameMain :
    public AbstractScene
{
private:



public:
    GameMain();


    ~GameMain();


    AbstractScene* Update() override;


    void Draw() const override;
    Player* player;
    Floor* floor;
    HitBox* hitbox;
};

