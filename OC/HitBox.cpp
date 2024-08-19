#include "HitBox.h"
#include "DxLib.h"

HitBox::HitBox()
{
	 X_Hit = FALSE;
	 Y_Hit = FALSE;

	 Box_X = 0;
	 Box_X2 = 300;
	 Box_Y = 500;
	 Box_Y2 = 720;

	 Box2_X = 800;
	 Box2_X2 =1200;
	 Box2_Y = 500;
	 Box2_Y2 = 720;
}

HitBox::~HitBox()
{

}


void HitBox::MoveBox()
{
	Box_X-=5;
	Box_X2 -= 5;
	Box2_X -= 5;
	Box2_X2 -= 5;
}

void HitBox::SpawnBox()
{
	

	if (Box_X2 < 0&&Box2_X<=640) {

		int a = GetRand(3);


		switch (a)
		{
		case 0:

			Box_X = 1280;
			Box_X2 = 1580;
			Box_Y = 500;
			Box_Y2 = 720;
			break;
		case 1:
			Box_X = 1280;
			Box_X2 = 1680;
			Box_Y = 500;
			Box_Y2 = 720;
			break;
		case 2:
			Box_X = 1280;
			Box_X2 = 1480;
			Box_Y = 500;
			Box_Y2 = 720;
			break;
		case 3:
			Box_X = 1280;
			Box_X2 = 1600;
			Box_Y = 500;
			Box_Y2 = 720;

			break;
		}

	
	}

	
	if (Box2_X2 < 0&& Box_X <=640) {
		int b = GetRand(3);
		switch (b)
		{
		case 0:

			Box2_X = 1280;
			Box2_X2 = 1580;
			Box2_Y = 500;
			Box2_Y2 = 720;
			break;
		case 1:
			Box2_X = 1280;
			Box2_X2 = 1680;
			Box2_Y = 500;
			Box2_Y2 = 720;
			break;
		case 2:
			Box2_X = 1280;
			Box2_X2 = 1480;
			Box2_Y = 500;
			Box2_Y2 = 720;
			break;
		case 3:
			Box2_X = 1280;
			Box2_X2 = 1600;
			Box2_Y = 500;
			Box2_Y2 = 720;
		
			break;
		}
	}

}


void HitBox::HitBase(int x, int y, int x2, int y2)
{
	
}

void HitBox::HitFlg()
{

}




void HitBox::Update()
{
	MoveBox();
	SpawnBox();
}

void HitBox::Draw() const
{
	DrawBox(Box_X, Box_Y, Box_X2, Box_Y2, 0xffffff, FALSE);
	DrawBox(Box2_X, Box2_Y, Box2_X2, Box2_Y2, 0xffffff, FALSE);

}




