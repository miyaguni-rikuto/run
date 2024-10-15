#include "DxLib.h"
#include "GameMain.h"

GameMain::GameMain()
{
    CharaImg= LoadGraph("source/img/chara.png");
    FleezSE = LoadSoundMem("source/SE/Fleez.mp3");
    FleezSE2 = LoadSoundMem("source/SE/Freez.mp3");
    a = LoadSoundMem("source/BGM/destruct.wav");
    c = 0;
    Init();
    FleezTime = 0;
    Score = 0;

    BackImg[0] = LoadGraph("source/img/Hiru.jpg");
    BackImg[1] = LoadGraph("source/img/Yu.png");
    BackImg[2] = LoadGraph("source/img/Yoru.jpg");
    KumoImg = LoadGraph("source/img/kumo.png");


    KumoX = 0;
    KumoY = 10;

    FloorX = 300;
    FloorY = 300;
    FloorX2 = 700;
    FloorY2 = 350;

    CharaImgX = 100;
    CharaImgY=500;


}


GameMain::~GameMain()
{
   
}


void GameMain::Init()
{
   


    PlayerX = 500;
    PlayerY = 900;
    PlayerHP = 3;
    PlayerAirTime = 0;
    PlayerJump = FALSE;
    

    FleezFlg = FALSE/*TRUE*/;
    Fleez1[0] = 320;
    Fleez1[1] = 400;
    Fleez2[0] = 330;
    Fleez2[1] = 390;

    c = 1;
   
  
}


void GameMain::SCORE()
{
    /* Score++;
     if (Score == 2400)
     {
         FleezFlg = TRUE;
     }
 }*/
}


void GameMain::Player()
{
    // ジャンプの最高到達点とジャンプ速度の設定
    const int MaxJumpHeight = 200; // プレイヤーが到達できる最大の高さ
    const int JumpSpeed = 5; // ジャンプ速度
    const int Gravity = 5; // 重力による下降速度

    const int GroundY = 1000;

    // ジャンプ処理
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 && PlayerJump == FALSE && PlayerY >= 400) {
        // ジャンプを開始
        PlayerJump = TRUE;
        PlayerAirTime = 0; // ジャンプ開始時に空中時間をリセット
    }

    if (PlayerJump == TRUE) {
        // ジャンプ中の処理
        if (PlayerAirTime < MaxJumpHeight / JumpSpeed) {
            // 最大高さに到達していない場合は上昇
            PlayerY -= JumpSpeed;
        }
        else {
            // 最大高さに到達したらジャンプを終了し、落下する
            PlayerJump = FALSE;
        }
        PlayerAirTime++;
    }
    else {
        // ジャンプが終わったら重力で落下
        if (PlayerY < 400) {
            PlayerY += Gravity;
        }

        // 地面に到達したらY座標を固定
        if (PlayerY >= 400) {
            PlayerY = 400;
        }
    }

    // プレイヤーが動く床に乗っている場合
    if (PlayerY + 70 >= FloorY && PlayerX + 50 >= FloorX && PlayerX <= FloorX2) {
        // プレイヤーが動く床の上にいる場合、床の高さに合わせる
        PlayerY = FloorY - 70;
        PlayerJump = FALSE; // 床にいるのでジャンプをリセット
    }

    Hit(); // 当たり判定処理
    Score += 5;
}



void GameMain::Fleez()
{
    if (FleezFlg == TRUE) {


        FleezTime++;
        if (FleezTime == 1)
        {
            StopSoundMem(a);
            PlaySoundMem(FleezSE2, DX_PLAYTYPE_BACK);
        }
        if (FleezTime == 6)
        {
           
            PlaySoundMem(FleezSE, DX_PLAYTYPE_BACK);
           
        }
        if (FleezTime >= 6) {

           

            if (Fleez1[0] != 360) {
                Fleez1[0] += 5;
                Fleez1[1] -= 5;

            }
            if (Fleez2[0] != 360) {

                Fleez2[0] += 5;
                Fleez2[1] -= 5;

            }

        }
      
    }
}

bool isPlayerOnEdge = false; // Edge collision flag

void GameMain::Hit()
{
    // 床に乗っているか確認
    if (PlayerY + 70 >= FloorY && PlayerY + 70 <= FloorY + 10 &&
        PlayerX + 50 >= FloorX && PlayerX <= FloorX2)
    {
        PlayerY = FloorY - 70;  // プレイヤーを床の上に固定
        PlayerJump = FALSE;
    }

    // プレイヤーが動く床の左端または右端に接触しているかを確認
    const int edgeThreshold = 5; // エッジ判定の幅を調整 (適宜変更)

    if ((PlayerX <= FloorX + edgeThreshold && PlayerY + 70 >= FloorY && PlayerY <= FloorY + 70) ||
        (PlayerX + 50 >= FloorX2 - edgeThreshold && PlayerY + 70 >= FloorY && PlayerY <= FloorY + 70))
    {
        // 左端または右端に接触したとき
        if (!isPlayerOnEdge) // 初めてエッジに当たった時のみ
        {
            Score -= 100;  // スコアをマイナス
            isPlayerOnEdge = true;  // 当たりを記録
        }
    }
    else
    {
        // プレイヤーがエッジから離れた場合にフラグをリセット
        isPlayerOnEdge = false;
    }
}
AbstractScene* GameMain::Update()
{
    CreateKumo();
    CreateFloor();
    if (c == 1) {
        ChangeVolumeSoundMem(70, a);
        PlaySoundMem(a, DX_PLAYTYPE_BACK);
    }
    c++;

    if (FleezFlg == FALSE) {
        SCORE();
        Player();

    }
    Fleez();
    return this;
}


void GameMain::DrawBackImg()
{

}


void GameMain::CreateKumo()
{
    KumoX -= 2;

    if (KumoX < -290) {
        KumoX = 1280;
        KumoY = GetRand(150)+50;
    }
    
}


void GameMain::CreateFloor()
{
    FloorX -= 5;
    FloorX2 -= 5;

    if (FloorX2 < 0) {
        FloorX = 1280;  // 床を画面の右端に再配置
        FloorX2 = FloorX + 200; // 固定の幅を持つ新しい床 (例: 100ピクセル)
        FloorY = GetRand(200)+400;  // 固定のY座標
        FloorY2 = FloorY + 50; // 固定の高さ (例: 50ピクセル)
    }
 
    
}


void GameMain::Draw() const
{
    DrawString(30, 30, "GameMain1", 0xffffff);
    DrawBox(0, 0, 1280, 720, 0x00BFFF, TRUE);

    if (Score < 2000) {
        DrawGraph(0, 0, BackImg[0], TRUE);
    }
    else if (Score < 4000) {
        DrawGraph(0, 0, BackImg[1], TRUE);
    }
    else {
        DrawGraph(0, 0, BackImg[2], TRUE);
    }

    DrawGraph(KumoX, KumoY, KumoImg, TRUE);

    DrawBox(FloorX, FloorY, FloorX2, FloorY2, 0xffffff, TRUE);

    // 動く床の当たり判定を可視化
    DrawBox(FloorX, FloorY, FloorX + 10, FloorY + 70, 0xFF0000, TRUE); // 左端の衝突判定
    DrawBox(FloorX2 - 10, FloorY, FloorX2, FloorY + 70, 0xFF0000, TRUE); // 右端の衝突判定

    // プレイヤー
    DrawGraph(PlayerX, PlayerY, CharaImg, TRUE); 

    // UI
    DrawBox(0, 620, 1280, 720, 0xFF0000, TRUE);
    DrawBox(10, 630, 1270, 710, 0x000000, TRUE);
    DrawFormatString(1050, 20, 0xffffff, "Total : %d M", Score);

    // フリーズ
    if (FleezFlg == TRUE)
    {
        DrawBox(0, 0, 1280, 720, 0x000000, TRUE);

        if (FleezTime >= 1 && FleezTime < 6)
        {
            DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
        }
        if (FleezTime >= 6)
        {
            DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
            DrawBox(0, Fleez1[0], 1280, Fleez1[1], 0x0000FF, TRUE);
            DrawBox(0, Fleez2[0], 1280, Fleez2[1], 0xffffff, TRUE);
        }
    }
}


