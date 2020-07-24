#pragma once
#include "GameObject.h"
#include <vector>

namespace SI
{
	class EnemyWave : public GameObject
	{
	public:
		EnemyWave(int rowCount = 3, int enemyCount = 8, int enemyMargin = 75, int enemyWidth = 60, int enemyHeight = 40)
		{
			this->enemyCount = enemyCount;
			this->enemyMargin = enemyMargin;
			this->enemyWidth = enemyWidth;
			this->enemyHeight = enemyHeight;

			for (int r = 0; r < rowCount; r++)
			{
				enemyWave.push_back(std::vector<GameObject*>());

				for (int i = 1; i <= enemyCount; i++)
				{
					GameObject* enemy = new GameObject(enemyTextures[r]);
					enemy->SetSize(enemyWidth, enemyHeight);
					enemy->SetPos(enemyMargin * i, enemyMargin * r);
					enemyWave[r].push_back(enemy);
				}
			}
		};
		~EnemyWave();

		void Update() override
		{
			for (size_t i = 0; i < enemyWave.size(); i++)
			{
				if (!enemyWave[i].empty())
				{
					GameObject* lastEnemy = enemyWave[i][enemyWave[i].size() - 1];
					GameObject* firstEnemy = enemyWave[i][0];

					if (firstEnemy->GetDestinationRect().x < 20)
					{
						speed = std::abs(speed);
						for (size_t i = 0; i < enemyWave.size(); i++)
						{
							for (size_t j = 0; j < enemyWave[i].size(); j++)
							{
								enemyWave[i][j]->SetPos(enemyWave[i][j]->GetDestinationRect().x + speed, enemyWave[i][j]->GetDestinationRect().y + 20);
							}
						}
						break;
					}
					else if (lastEnemy->GetDestinationRect().x + this->enemyWidth > 780)
					{
						speed = -speed;
						for (size_t i = 0; i < enemyWave.size(); i++)
						{
							for (size_t j = 0; j < enemyWave[i].size(); j++)
							{
								enemyWave[i][j]->SetPos(enemyWave[i][j]->GetDestinationRect().x + speed, enemyWave[i][j]->GetDestinationRect().y + 20);
							}
						}
						break;
					}
					else
					{
						for (size_t j = 0; j < enemyWave[i].size(); j++)
						{
							enemyWave[i][j]->SetPos(enemyWave[i][j]->GetDestinationRect().x + speed, enemyWave[i][j]->GetDestinationRect().y);
						}
					}
				}
			}
		}

		void Render() override
		{
			for (size_t i = 0; i < enemyWave.size(); i++)
			{
				for (size_t j = 0; j < enemyWave[i].size(); j++)
				{
					enemyWave[i][j]->Render();
				}
			}
		}

		std::vector<std::vector<GameObject*>>& GetEnemies()
		{
			return enemyWave;
		}

		void RemoveEnemyAt(int rowIndex, int colIndex)
		{
			enemyWave[rowIndex].erase(enemyWave[rowIndex].begin() + colIndex);
		}

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
		std::vector<std::vector<GameObject*>> enemyWave;
	};
}