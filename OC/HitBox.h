#pragma once

class HitBox
	
{
private:
	
protected:
	

	int Box_X;
	int Box_X2;

	int Box_Y;
	int Box_Y2;

	int Box2_X;
	int Box2_X2;

	int Box2_Y;
	int Box2_Y2;
public:
	HitBox();

	~HitBox();

	void HitBase(int x, int y, int x2, int y2);

	void Update();

	void Draw() const;

	void MoveBox();
	void SpawnBox();

	void HitFlg();

	int X_Hit;
	int Y_Hit;

	
};

