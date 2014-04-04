#ifndef _BULLET_H
#define _BULLET_H

#include "GameConstants.h"
#include "GameInformation.h"
#include "cD3DManager.h"
#include "cD3DXSpriteMgr.h"
#include "cD3DXTexture.h"

class Bullet{

public:

	Bullet(D3DXVECTOR3 playerPosition, int halfPlayerTex);
	~Bullet();

	bool IsDead();

	void Update();
	void Draw();
	void Initialise(D3DXVECTOR3 playerPosition);


private:

	int bulletSpeed;
	D3DXVECTOR3 bulletPosition;
	cD3DXTexture* bulletTexture;

	cD3DManager* d3dMgr;
	cD3DXSpriteMgr* d3dSRMgr;

};

#endif