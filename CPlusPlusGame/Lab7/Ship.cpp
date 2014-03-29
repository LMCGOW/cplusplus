#include "Ship.h"

Ship::Ship(){

	Initialise();

}

void Ship::Initialise(){

	d3dMgr = cD3DManager::getInstance();
	spriteManager = cD3DXSpriteMgr::getInstance();
	shipPosition = D3DXVECTOR3(50, 300, 0);
	shipSpeed = D3DXVECTOR2(15, 5);

	shipTexture = new cD3DXTexture(d3dMgr->getTheD3DDevice(), "Images\\ship.png");

}


/*
	handles updating the logic for the Ship class
*/
void Ship::Update(){

	//shipPosition.x +=1;

}

/*
	will handle the input for the Ship class
*/
void Ship::HandleInput(WPARAM wParam){

	switch(wParam){

	case 'W':
		shipPosition.y -= shipSpeed.y;
		break;
	case 'S':
		shipPosition.y += shipSpeed.y;
		break;

	}

}

/*
	handles drawing within the Ship class

	@param: spriteManager - the sprite manager; allows drawing of sprites
*/
void Ship::Draw()
{

	spriteManager->drawSprite(shipTexture->getTexture(), NULL, NULL, &shipPosition, 0xFFFFFFFF);

}