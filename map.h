#pragma once
#include <vector>
class Map
{
public:
	void Initialize();
	void Draw();

	std::vector<std::vector<int>>  map;

	const int mapSize = 64;
};
