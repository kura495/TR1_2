#pragma once
#pragma once
#include"Vector2.h"
#include "map.h"

class Player
{
public:
	void Initialize(Vector2 pos);

	void Update(char* keys);
	void Draw();
	Vector2 GetPos() { return pos_; }
	float GetSize() { return size_; }
	int GetPlayerX() { return playerMapX; }
	int GetPlayerY() { return playerMapY; }
private:
	int playerMapX;
	int playerMapY;
	Vector2 pos_;
	Vector2 initPos_;
	Vector2 speed_;
	float size_;
};
