#include "Player.h"
#include"DxLib.h"

Player::Player()
{
	Player_X = 100;
	Player_X2 = 150;

	Player_Y = 400;
	Player_Y2 = 500;

	Jump_Flg = TRUE;
	Jump_Power = 0;
}

Player::~Player()
{
}

void Player::JUMP()
{
	if (Jump_Flg == TRUE&& CheckHitKey(KEY_INPUT_SPACE)) {
		

		
			Player_Y-=10;
			Player_Y2-=10;
		
	}
	if (CheckHitKey(KEY_INPUT_SPACE ) == 0)
	{
		GRAVITY();
	}
}


void Player::DEAD()
{
	if (Player_Y2 <= Box_Y) {
		
	}
}

void Player::GRAVITY()
{
	if (Player_X2 < Box_X&& Player_X < Box_X2 ||Player_X > Box_X2&& Player_X2 > Box_X || Player_Y2 != 500) {

		
			Player_Y += 5;
			Player_Y2 += 5;
	
	}
	/*else if (Player_X2 < Box2_X && Player_X < Box2_X2 || Player_X > Box2_X2 && Player_X2 > Box2_X || Player_Y2 != 500)
	{
		Player_Y += 5;
		Player_Y2 += 5;
	}*/
}

void Player::RUN()
{ 
	

}


void Player::Update()
{
	JUMP();
	RUN();
	SpawnBox();
	MoveBox();
}


void Player::Draw() const
{
	DrawBox(Box_X, Box_Y, Box_X2, Box_Y2, 0xffffff, FALSE);
	DrawBox(Box2_X, Box2_Y, Box2_X2, Box2_Y2, 0xffffff, FALSE);
	DrawBox(Player_X, Player_Y, Player_X2, Player_Y2, 0xffffff, FALSE);
	DrawFormatString(30, 10, 0xffffff, "%d", Box_Y);
	DrawFormatString(60, 10, 0xffffff, "%d", Box_X);
	DrawFormatString(90, 10, 0xffffff, "%d", Box_X2);
}




