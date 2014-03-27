#include "ScreenManager.h"

ScreenManager::ScreenManager(cD3DManager* d3dMgr)
{

	activeScreenIndex = 0;

	gameScreens[0] = Screen(d3dMgr->getD3DSurfaceFromFile("Images\\menu.png"));
	gameScreens[1] = Screen(d3dMgr->getD3DSurfaceFromFile("Images\\background.png"));

}

/*
	updates the current screen
*/
void ScreenManager::Update()
{

	gameScreens[activeScreenIndex].Update();

}
/*
	draws the current screen
*/
void ScreenManager::Draw(LPDIRECT3DSURFACE9 theBackbuffer, cD3DManager* d3dMgr)
{

	gameScreens[activeScreenIndex].DrawSurface(theBackbuffer, d3dMgr);

}

/*
	sets the active screen index
*/
void ScreenManager::SetActiveScreen(int active)
{

	activeScreenIndex = active;

}

/*
	returns the active screen
*/
int ScreenManager::ReturnActiveScreen()
{

	return activeScreenIndex;

}