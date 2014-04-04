#include "Ship.h"

/*
	default ship constructor
*/
Ship::Ship(){

	Initialise();

}

/*
	intialises the ship class
*/
void Ship::Initialise(){

	d3dMgr = cD3DManager::getInstance();
	spriteManager = cD3DXSpriteMgr::getInstance();

	shipTexture = new cD3DXTexture(d3dMgr->getTheD3DDevice(), "Images\\ship.png");

	shipSpeed = D3DXVECTOR2(10, 10);
	shipPosition = D3DXVECTOR3(50, ((GameInformation::WINDOWHEIGHT - shipTexture->getTHeight()) - 20), 0);

}


/*
	handles updating the logic for the Ship class
*/
void Ship::Update(){

	CheckWithinBounds();

}

/*
	ensures the ship stays within the bounds of the window
*/
void Ship::CheckWithinBounds(){

	if(shipPosition.x < 0)
		shipPosition.x = 0;

	if((shipPosition.x + shipTexture->getTWidth()) > GameInformation::WINDOWWIDTH){

		shipPosition.x = GameInformation::WINDOWWIDTH - shipTexture->getTWidth();

	}

}

/*
	will handle the input for the Ship class
*/
void Ship::HandleInput(WPARAM wParam){

	
	if(wParam == 'A'){
		shipPosition.x -= shipSpeed.x;
	}

	if(wParam=='D'){
	shipPosition.x += shipSpeed.x;
	}




}

D3DXVECTOR3 Ship::GetPosition(){

	return shipPosition;

}

cD3DXTexture* Ship::GetTexture(){

	return shipTexture;

}

/*
	handles drawing within the Ship class
*/
void Ship::Draw()
{

	spriteManager->drawSprite(shipTexture->getTexture(), NULL, NULL, &shipPosition, 0xFFFFFFFF);

}