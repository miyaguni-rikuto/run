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
		

		
			Player_Y-=5;
			Player_Y2-=5;
		
	}
	if (CheckHitKey(KEY_INPUT_SPACE == 0))
	{

	}
}


void Player::DEAD()
{
	if (Player_Y2 <= Box_Y) {

	}
}

void Player::GRAVITY()
{

}

void Player::RUN()
{
	

}


void Player::Update()
{
	JUMP();
	RUN();
}


void Player::Draw() const
{
	DrawBox(Player_X, Player_Y, Player_X2, Player_Y2, 0xffffff, FALSE);
	
}




