#include "GameScreen.h"

/*
	default game screen constructor
*/
GameScreen::GameScreen(){

	Initialise();

}

/*
	game screen destructor
*/
GameScreen::~GameScreen(){

}

/*
	initialises the game screen
*/
void GameScreen::Initialise(){

	d3dMgr = cD3DManager::getInstance();
	screen = d3dMgr->getD3DSurfaceFromFile("Images\\game.png");

	enemySpawnRate = 3;
	enemySpawnTime = 3.0f;
	spawnWave = false;

	player = new Ship();

	for(int i = 0; i < 3; i++){

		enemies.push_back(new Enemy());

	}

	respawnTimer = new Timer();
	decreaseWaveSpawnTimer = new Timer();
	increaseSpawnRateTimer = new Timer();

}

/*
	updates the game screen and associated objects
*/
void GameScreen::Update(){

	player->Update();

	for(enemyIter = enemies.begin(); enemyIter != enemies.end(); ++enemyIter){

		(*enemyIter)->Update();

	}

	for(bulletIter = bullets.begin(); bulletIter != bullets.end(); ++bulletIter){

		(*bulletIter)->Update();

	}


	SpawnEnemyWave();
	IncreaseSpawnRate();
	DisposeOfDeadEnemies();

}

/*
	handles game screen input and associated objects
*/
void GameScreen::HandleInput(WPARAM wParam){
	
	player->HandleInput(wParam);

}

/*
	draws the game screen and associated objects
*/
void GameScreen::Draw(){

	player->Draw();
	
	for(enemyIter = enemies.begin(); enemyIter != enemies.end(); ++enemyIter){

		(*enemyIter)->Draw();

	}

	for(bulletIter = bullets.begin(); bulletIter != bullets.end(); ++bulletIter){

		(*bulletIter)->Draw();

	}

}

/*
	draws the game screen surface
*/
void GameScreen::DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer){

	if(screen!=NULL){

		d3dMgr->updateTheSurface(screen, theBackBuffer);
		d3dMgr->releaseTheBackbuffer(theBackBuffer);

	}

}

/*
	will spawn a new wave of enemies every 7 seconds
*/
void GameScreen::SpawnEnemyWave(){

	if(respawnTimer->TimePassed(enemySpawnTime)){

		for(int i = 0; i < enemySpawnRate; i++){

			enemies.push_back(new Enemy());

		}
	}

}

/*
	decreases the spawn timer after 15 seconds
*/
void GameScreen::DecreaseSpawnTimer(){

	if(decreaseWaveSpawnTimer->TimePassed(15.0f))
		enemySpawnTime -= 0.1f;

}

/*
	increases spawn rate after 10 seconds
*/
void GameScreen::IncreaseSpawnRate(){

	if(increaseSpawnRateTimer->TimePassed(10.0f))
		enemySpawnRate++;

}

/*
	will dispose of any enemies that die
*/
void GameScreen::DisposeOfDeadEnemies(){

	for(enemyIter = enemies.begin(); enemyIter != enemies.end(); ++enemyIter){

		if((*enemyIter)->IsDead()){

			enemyIter = enemies.erase(enemyIter);

		}

	}

}

/*
	Creates a bullet 
*/
void GameScreen::CreateBullet(){

	int halfPlayerTex = player->GetTexture()->getTWidth() / 2;
	//knob cheese
	bullets.push_back(new Bullet(player->GetPosition(), halfPlayerTex));

}

