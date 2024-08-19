#pragma once
#include "HitBox.h"
class Floor: public HitBox
  
{
private:

   
protected:

   /* int Floor_X;
    int Floor_X2;

    int Floor_Y;
    int Floor_Y2;*/



public:
    Floor();
    ~Floor();
    void Update();
    void Draw() const;

    void FLOOR();
};

