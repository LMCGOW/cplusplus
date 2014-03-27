#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "Screen.h"


class ScreenManager{

private:
	
	Screen gameScreens[2];
	int activeScreenIndex;

public:

	ScreenManager(cD3DManager* d3dMgr);

	//Virtual methods
	void Update();
	void Draw(LPDIRECT3DSURFACE9 theBackbuffer, cD3DManager* d3dMgr);
	void SetActiveScreen(int active); //Will set the active screen
	
	int ReturnActiveScreen(); //Will return the active screen



};
#endif