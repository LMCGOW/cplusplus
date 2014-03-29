#ifndef _IGAMESCREEN_H
#define _IGAMESCREEN_H

#include "cD3DManager.h"

class IGameScreen{

protected:

	cD3DManager* d3dMgr;
	

public:

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer) = 0;

};

#endif