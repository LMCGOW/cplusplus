#include "ScreenManager.h"

ScreenManager::ScreenManager()
{

	activeScreen = Menu; //Sets the initial screen

	menuScreen = MenuScreen();
	gameScreen = GameScreen();

}

/*
	updates the current screen
*/
void ScreenManager::Update()
{

	switch(activeScreen){

	case Menu:
		menuScreen.Update();
		break;
	case Game:
		gameScreen.Update();
		break;
	}

}
/*
	draws the current screen
*/
void ScreenManager::DrawSurface(LPDIRECT3DSURFACE9 theBackbuffer)
{
	
	switch(activeScreen){

	case Menu:
		menuScreen.DrawSurface(theBackbuffer);
		break;
	case Game:
		gameScreen.DrawSurface(theBackbuffer);
		break;

	}

}

void ScreenManager::Draw(){

	switch(activeScreen){

	case Menu:
		menuScreen.Draw();
		break;
	case Game:
		gameScreen.Draw();
		break;

	}

}

void ScreenManager::HandleInput(WPARAM wParam){

	switch(activeScreen){

	case Menu:
		menuScreen.HandleInput(wParam);
		break;
	case Game:
		gameScreen.HandleInput(wParam);
		break;


	}

}

/*
	sets the active screen index
*/
void ScreenManager::SetActiveScreen(Screens active)
{

	activeScreen= active;

}

/*
	returns the active screen
*/
Screens ScreenManager::ReturnActiveScreen()
{

	return activeScreen;

}

void ScreenManager::KeyboardPressed(){

	if(activeScreen == Game){
		gameScreen.CreateBullet();
	}

}