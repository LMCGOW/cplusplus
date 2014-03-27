#include "Ship.h"

Ship::Ship(){


}

/*
	second constructor for the ship class; initialises instance variables
*/
Ship::Ship(LPCSTR path, cD3DManager* d3dManager , D3DXVECTOR3 shipPos)
{
	d3dMgr = d3dManager;
	shipPosition = shipPos;
	shipSpeed = D3DXVECTOR2(15, 5);

	shipTexture = new cD3DXTexture(d3dMgr->getTheD3DDevice(), path);
}

/*
	handles updating the logic for the Ship class
*/
void Ship::Update(){

	shipPosition.x +=1;

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
void Ship::Draw(cD3DXSpriteMgr* spriteManager)
{

	spriteManager->drawSprite(shipTexture->getTexture(), NULL, NULL, &shipPosition, 0xFFFFFFFF);

}