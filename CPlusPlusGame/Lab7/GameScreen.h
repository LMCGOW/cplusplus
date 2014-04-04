#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include "IGameScreen.h"
#include "Ship.h"
#include "Enemy.h"
#include "Timer.h"
#include "Bullet.h"

class GameScreen : public IGameScreen{

private:

	LPDIRECT3DSURFACE9 screen;
	Ship* player;
	
	vector<Enemy*> enemies;
	vector<Enemy*>::iterator enemyIter;

	vector<Bullet*> bullets;
	vector<Bullet*>::iterator bulletIter;

	int enemySpawnRate;
	float enemySpawnTime;
	bool spawnWave;

	Timer* respawnTimer;
	Timer* decreaseWaveSpawnTimer;
	Timer* increaseSpawnRateTimer;

public:

	GameScreen();
	~GameScreen();

	void Update();
	void Draw();
	void DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer);
	void Initialise();
	void HandleInput(WPARAM wParam);
	void SpawnEnemyWave();
	void DecreaseSpawnTimer();
	void IncreaseSpawnRate();
	void DisposeOfDeadEnemies();
	void CreateBullet();

};
#endif