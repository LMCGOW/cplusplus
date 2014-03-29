/*
=================
Ship.h
- Header file for class definition - SPECIFICATION
- Header file for the Ship class
=================
*/

#ifndef _SHIP_H
#define _SHIP_H
#include "GameConstants.h"
#include "cD3DXTexture.h"
#include "cD3DXSpriteMgr.h"
#include "cD3DManager.h"

class Ship{

private:

	//The position and speed of the ship
	D3DXVECTOR3 shipPosition;
	D3DXVECTOR2 shipSpeed;

	//The d3d manager
	cD3DManager* d3dMgr;
	cD3DXSpriteMgr* spriteManager;

	//The ship texture
	cD3DXTexture* shipTexture;


public:

	Ship(); //Default constructor
	~Ship(); //Destructor

	void Update(); //Update method
	void Draw(); //Draw method
	void HandleInput(WPARAM wParam); //Controls input
	void Initialise();
	
};
#endif