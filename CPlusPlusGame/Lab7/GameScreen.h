#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include "IGameScreen.h"
#include "Ship.h"

class GameScreen : public IGameScreen{

private:

	LPDIRECT3DSURFACE9 screen;
	Ship* player;

public:

	GameScreen();

	void Update();
	void Draw();
	void DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer);
	void Initialise();
	void HandleInput(WPARAM wParam);

};
#endif