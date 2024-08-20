#pragma once
class StageBack
{

	int AsaImg;
	int HiruImg;
	int YuImg;
	int YoruImg;
	int KumoImg;
	
	int C_back_flg;
	int MoveKumo_flg;
	int kumoX;
	
public:
	StageBack();

	~StageBack();

	void Update();

	void Draw();
};

