#include "SIMath.h"
#include "EnemyWave.h"
#include <vector>
#include "Game.h"

SI::EnemyWave::EnemyWave(int rowCount, int enemyCount, int enemyMargin, int enemyWidth, int enemyHeight)
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

void SI::EnemyWave::Update()
{
	if (!SI::Game::IsPaused)
	{
		for (size_t i = 0; i < enemyWave.size(); i++)
		{
			if (!enemyWave[i].empty())
			{
				GameObject* lastEnemy = enemyWave[i][enemyWave[i].size() - 1];
				GameObject* firstEnemy = enemyWave[i][0];

				if (firstEnemy->GetDestinationRect().x <= 20)
				{
					speed = std::abs(speed);
					for (size_t i = 0; i < enemyWave.size(); i++)
					{
						for (size_t j = 0; j < enemyWave[i].size(); j++)
						{
							enemyWave[i][j]->SetPos(SI::SIMath::Clamp(enemyWave[i][j]->GetDestinationRect().x + speed, 20, 780), enemyWave[i][j]->GetDestinationRect().y + ySkip);
						}
					}
					break;
				}
				else if (lastEnemy->GetDestinationRect().x + this->enemyWidth >= 780)
				{
					speed = -speed;
					for (size_t i = 0; i < enemyWave.size(); i++)
					{
						for (size_t j = 0; j < enemyWave[i].size(); j++)
						{
							enemyWave[i][j]->SetPos(SI::SIMath::Clamp(enemyWave[i][j]->GetDestinationRect().x + speed, 20, 780 - enemyWidth), enemyWave[i][j]->GetDestinationRect().y + ySkip);
						}
					}
					break;
				}
				else
				{
					for (size_t j = 0; j < enemyWave[i].size(); j++)
					{
						enemyWave[i][j]->SetPos(SI::SIMath::Clamp(enemyWave[i][j]->GetDestinationRect().x + speed * speedMultiplier, 20, 780), enemyWave[i][j]->GetDestinationRect().y);
					}
				}
			}
		}
	}
}

void SI::EnemyWave::Render()
{
	for (size_t i = 0; i < enemyWave.size(); i++)
	{
		for (size_t j = 0; j < enemyWave[i].size(); j++)
		{
			enemyWave[i][j]->Render();
		}
	}
}

std::vector<std::vector<SI::GameObject*>>& SI::EnemyWave::GetEnemies()
{
	return enemyWave;
}

void SI::EnemyWave::RemoveEnemyAt(int rowIndex, int colIndex)
{
	enemyWave[rowIndex].erase(enemyWave[rowIndex].begin() + colIndex);

	killedEnemies += 1;

	if (killedEnemies >= 15)
	{
		speedMultiplier = 5;
		ySkip = 14;
	}
	else if (killedEnemies >= 12)
	{
		speedMultiplier = 4;
		ySkip = 13;
	}
	else if (killedEnemies >= 8)
	{
		speedMultiplier = 3;
		ySkip = 12;
	}
	else if (killedEnemies >= 4)
	{
		speedMultiplier = 2;
		ySkip = 11;
	}
}