#pragma once
#include "GameObject.h"
#include <vector>

namespace SI
{
	class EnemyWave : public GameObject
	{
	public:
		EnemyWave(int rowCount = 3, int enemyCount = 8, int enemyMargin = 75, int enemyWidth = 60, int enemyHeight = 40);
		~EnemyWave();

		void Update() override;
		void Render() override;
		std::vector<std::vector<GameObject*>>& GetEnemies();
		void RemoveEnemyAt(int rowIndex, int colIndex);

	private:
		const char* enemyTextures[3] =
		{
			"resources/sprites/sprite_00.bmp",
			"resources/sprites/sprite_01.bmp",
			"resources/sprites/sprite_02.bmp"
		};
		size_t enemyCount = 10;
		int enemyMargin = 50;
		int speed = 1;
		int enemyWidth = 60;
		int enemyHeight = 40;
		int speedMultiplier = 1;
		int killedEnemies = 0;
		int ySkip = 10;
		std::vector<std::vector<GameObject*>> enemyWave;
	};
}