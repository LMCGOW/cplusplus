#ifndef _SCREEN_H
#define _SCREEN_H

#include "GameConstants.h"
#include "cD3DManager.h"

class Screen{

private:

	LPDIRECT3DSURFACE9 screen; //The screen that will be drawn

public:

	Screen();
	Screen(LPDIRECT3DSURFACE9 theScreen); //Constructor
	~Screen(); //Destructor

	void Update();
	void DrawSurface(LPDIRECT3DSURFACE9 theBackbuffer, cD3DManager* d3dMgr);

};
#endif