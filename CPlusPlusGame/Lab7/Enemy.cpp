#include "Enemy.h"

Enemy::Enemy(){

	Initialise();

}

/*
	destructor
*/
Enemy::~Enemy(){



}

/*
	intialises the enemy
*/
void Enemy::Initialise(){

	randomNumber = RandomNumber::GetInstance();

	minEnemySpeed = 3;
	maxEnemySpeed = 8;

	enemyPosition = D3DXVECTOR3(randomNumber->GenerateRandomNumber(800), 0, 0);

	d3dMgr = cD3DManager::getInstance();
	spriteManager = cD3DXSpriteMgr::getInstance();

	enemyTexture = new cD3DXTexture(d3dMgr->getTheD3DDevice(), "Images\\enemy.png");

	while(enemySpeed < minEnemySpeed){
		enemySpeed = randomNumber->GenerateRandomNumber(maxEnemySpeed);
	}
}

/*
	updates the enemy
*/
void Enemy::Update(){

	enemyPosition.y+= enemySpeed;

		if(enemyPosition.x < 0)
		enemyPosition.x = 0;

		if((enemyPosition.x + enemyTexture->getTWidth()) > GameInformation::WINDOWWIDTH){

		enemyPosition.x = GameInformation::WINDOWWIDTH - enemyTexture->getTWidth();

	}

}

/*
	draws the enemy
*/
void Enemy::Draw(){

	spriteManager->drawSprite(enemyTexture->getTexture(), NULL, NULL, &enemyPosition, 0xFFFFFFFF);

}

/*
	will return true if the enemy has been shot or has made it off screen
*/
bool Enemy::IsDead(){

	if(enemyPosition.y > GameInformation::WINDOWHEIGHT){

		return true;

	}

	else

		return false;

}