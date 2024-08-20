#include "StageBack.h"
#include "DxLib.h"

StageBack::StageBack()
{
    AsaImg = LoadGraph("source/img/Asa.jpg");
    HiruImg = LoadGraph("source/img/Hiru.jpg");
    YuImg = LoadGraph("source/img/Yu.png");
    YoruImg = LoadGraph("source/img/Yoru.jpg");
    KumoImg = LoadGraph("source/img/Kumo.png");

    C_back_flg = false;
    MoveKumo_flg = false;
    kumoX=120;
}

StageBack::~StageBack()
{

}

void StageBack::Update()
{
    if (CheckHitKey(KEY_INPUT_LEFT)) {
        C_back_flg = true;
    }
    if (CheckHitKey(KEY_INPUT_D)) {
        MoveKumo_flg = true;
    }
    
    if (MoveKumo_flg == true) {
        kumoX--;
    }    
    if (kumoX < -300) {
        kumoX = 1280;
    }
}

void StageBack::Draw()
{
    DrawGraph(0, 0, AsaImg, TRUE);

    if (C_back_flg == true) {
        DrawGraph(0, 0, HiruImg, TRUE);
    }
    
    DrawGraph(kumoX, 100, KumoImg, TRUE);
   
}
