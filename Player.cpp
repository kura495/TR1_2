#include "Player.h"
#include <Novice.h>
void Player::Initialize(Vector2 pos)
{
	initPos_ = pos;
	pos_ = pos;
	size_ = 32;
	speed_ = { 0,0 };
}

void Player::Update(char* keys)
{
	if (keys[DIK_W]) {
		speed_.y = -4;
	}
	else if (keys[DIK_S]) {
		speed_.y = 4;
	}
	else if (keys[DIK_A]) {

		speed_.x = -4;
	}
	else if (keys[DIK_D]) {
		speed_.x = 4;
	}
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	speed_ = { 0,0 };
	playerMapX = (int)pos_.x / 64;
	playerMapY = (int)pos_.y / 64;
}

void Player::Draw()
{
	Novice::DrawBox((int)pos_.x, (int)pos_.y, (int)size_, (int)size_, 0.0f, WHITE, kFillModeSolid);
}