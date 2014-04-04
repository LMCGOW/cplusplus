#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameConstants.h"
#include "cD3DXSpriteMgr.h"
#include "cD3DXTexture.h"
#include "cD3DManager.h"
#include "RandomNumber.h"
#include "Timer.h"
#include "GameInformation.h"

class Enemy{

private:

	D3DXVECTOR3 enemyPosition;

	float enemySpeed;
	float maxEnemySpeed;
	float minEnemySpeed;

	//The d3d manager
	cD3DManager* d3dMgr;
	cD3DXSpriteMgr* spriteManager;

	//The ship texture
	cD3DXTexture* enemyTexture;

	RandomNumber* randomNumber;

	void Initialise();


public:

	Enemy();
	~Enemy();

	void Update();
	void Draw();

	void HandleInput(WPARAM wParam);

	bool IsDead();

};
#endif