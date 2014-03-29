#ifndef _MENUSCREEN_H
#define _MENUSCREEN_H

#include "IGameScreen.h"

class MenuScreen : public IGameScreen{

private:

	LPDIRECT3DSURFACE9 screen;

public:

	MenuScreen();

	void Update();
	void DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer);
	void Draw();
	void Initialise();
	void HandleInput(WPARAM wParam);
	
};

#endif