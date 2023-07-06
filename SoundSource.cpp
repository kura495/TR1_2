#include "SoundSource.h"
#include"Player.h"
#include<Novice.h>
void SoundSource::Initialize(Vector2 Position)
{
	position_ = Position;
}

void SoundSource::Update()
{
	moveCount--;
	SoundScore[Right] = 0;
	if (player_->GetPlayerX()+1 != mapPosX_ || player_->GetPlayerY() != mapPosY_) {

		path_[Right] = FindPath(map_->map, mapPosX_, mapPosY_, player_->GetPlayerX()+1 , player_->GetPlayerY(), SoundScore[Right]);
		
		if (moveCount <= 0 && !path_[Right].empty()) {
			// パスを更新
			path_[Right].erase(path_[Right].begin(), path_[Right].begin() + 1);
			moveCount = 30;
		}
	}
	SoundScore[Left] = 0;
	if (player_->GetPlayerX() - 1 != mapPosX_ || player_->GetPlayerY() != mapPosY_) {

		path_[Left] = FindPath(map_->map, mapPosX_, mapPosY_, player_->GetPlayerX() - 1, player_->GetPlayerY(), SoundScore[Left]);

		if (moveCount <= 0 && !path_[Left].empty()) {
			// パスを更新
			path_[Left].erase(path_[Left].begin(), path_[Left].begin() + 1);
			moveCount = 30;
		}
	}
	
}

void SoundSource::Draw()
{
	for (const auto& node : path_[Right]) {
		Novice::DrawBox(node->x * 64, node->y * 64, 64, 64, 0, RED, kFillModeWireFrame);
	}
	for (const auto& node : path_[Left]) {
		Novice::DrawBox(node->x * 64, node->y * 64, 64, 64, 0, RED, kFillModeWireFrame);
	}
	
	Novice::DrawBox((int)position_.x,(int)position_.y, 64, 64, 0, RED, kFillModeSolid);
}

void SoundSource::Move(char* keys)
{
	if (keys[DIK_UP]) {
		speed_.y = -4;
	}
	else if (keys[DIK_DOWN]) {
		speed_.y = 4;
	}
	else if (keys[DIK_LEFT]) {

		speed_.x = -4;
	}
	else if (keys[DIK_RIGHT]) {
		speed_.x = 4;
	}
	position_.x += speed_.x;
	position_.y += speed_.y;
	speed_ = { 0,0 };
	mapPosX_ = (int)position_.x / 64;
	mapPosY_ = (int)position_.y / 64;
}

