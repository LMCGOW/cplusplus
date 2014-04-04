#include "Bullet.h"

Bullet::Bullet(D3DXVECTOR3 playerPosition, int halfPlayerTex){


	Initialise(playerPosition);

}

Bullet::~Bullet(){


}

void Bullet::Initialise(D3DXVECTOR3 playerPosition){

	d3dMgr = cD3DManager::getInstance();
	d3dSRMgr = cD3DXSpriteMgr::getInstance();

	bulletPosition = playerPosition;
	bulletTexture = new cD3DXTexture(d3dMgr->getTheD3DDevice(), "Images\\bullet.png");

	bulletSpeed = 30;

}

/*
	updates the bullet
*/
void Bullet::Update(){

	bulletPosition.y -= bulletSpeed;

}

/*
	returns true if the bullet is dead
*/
bool Bullet::IsDead(){

	if(bulletPosition.y > (GameInformation::WINDOWHEIGHT + 100)){

		return true;

	}

	else

		return false;

}

/*
	will draw the bullet
*/
void Bullet::Draw(){

	d3dSRMgr->drawSprite(bulletTexture->getTexture(), NULL, NULL, &bulletPosition, 0xFFFFFFFF);	

}

