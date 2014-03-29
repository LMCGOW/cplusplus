#include "GameScreen.h"

GameScreen::GameScreen(){

	Initialise();

}

void GameScreen::Initialise(){

	d3dMgr = cD3DManager::getInstance();
	screen = d3dMgr->getD3DSurfaceFromFile("Images\\game.png");

	player = new Ship();

}

void GameScreen::Update(){

	player->Update();

}

void GameScreen::HandleInput(WPARAM wParam){
	
	player->HandleInput(wParam);

}

void GameScreen::Draw(){

	player->Draw();

}

void GameScreen::DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer){

	if(screen!=NULL){

		d3dMgr->updateTheSurface(screen, theBackBuffer);
		d3dMgr->releaseTheBackbuffer(theBackBuffer);

	}

}

