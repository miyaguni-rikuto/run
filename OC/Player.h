#pragma once
#include "HitBox.h"
class Player :public HitBox

    
{
private:

   



protected:
   int Player_X;
    int Player_X2;
    int Player_Y;
    int Player_Y2;

    int Jump_Flg;
    int Jump_Power;
public:

    Player();

    ~Player();

    void Update();

    void Draw() const;

    void JUMP();

    void DEAD();

    void GRAVITY();

    void RUN();
};

