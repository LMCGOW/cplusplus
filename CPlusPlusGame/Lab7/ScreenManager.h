#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "Screens.h"
#include "MenuScreen.h"
#include "GameScreen.h"

class ScreenManager{

private:
	
#pragma region
	
	MenuScreen menuScreen;
	GameScreen gameScreen;

	//I'm the Batman
#pragma endregion Screens

	Screens activeScreen; //Stores the active screen
	cD3DManager* d3dMgr;

public:

	ScreenManager();

	void Update();
	void DrawSurface(LPDIRECT3DSURFACE9 theBackbuffer);
	void Draw();
	void SetActiveScreen(Screens active); //Will set the active screen
	void HandleInput(WPARAM wParam);
	void KeyboardPressed();
	
	Screens ReturnActiveScreen(); //Will return the active screen

};
#endif