#include "MenuScreen.h"

MenuScreen::MenuScreen(){

	Initialise();

}

void MenuScreen::Update(){

	

}

void MenuScreen::HandleInput(WPARAM wParam){


}

void MenuScreen::Initialise(){

	d3dMgr = cD3DManager::getInstance();
	screen = d3dMgr->getD3DSurfaceFromFile("Images\\menu.png");

}

void MenuScreen::Draw(){

	
	
}

void MenuScreen::DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer){

	if(screen!=NULL){

		d3dMgr->updateTheSurface(screen, theBackBuffer);
		d3dMgr->releaseTheBackbuffer(theBackBuffer);

	}
}
