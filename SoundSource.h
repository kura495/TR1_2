#pragma once
#include"Vector2.h"
#include "map.h"
#include "Astar.h"
#include"MyXAudio2.h"
enum LR {
	Left,
	Right,
	LR
};
class Player;
class SoundSource
{
public:

	void Initialize(Vector2 Position);

	void Update();

	void Draw();

	void Move(char* keys);

	void SetPlayer(Player* player) { player_ = player; }
	void SetMap(Map* map) { this->map_ = map; }
	int SoundScore[LR];
private:

	int moveCount = 30;
	int mapPosX_;
	int mapPosY_;
	Player* player_;
	Vector2 position_;
	Vector2 speed_;
	std::vector<Node*> path_[LR];
	Map* map_;
private:

};
