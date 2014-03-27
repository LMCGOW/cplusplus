#include "Screen.h"

Screen::Screen(){


}

Screen::Screen(LPDIRECT3DSURFACE9 theScreen){

	screen = theScreen;
	
}

Screen::~Screen(){

}

void Screen::Update(){

	

}

/*
	Will draw the screens 
*/
void Screen::DrawSurface(LPDIRECT3DSURFACE9 theBackBuffer, cD3DManager* d3dMgr){

	d3dMgr->updateTheSurface(screen, theBackBuffer);
	d3dMgr->releaseTheBackbuffer(theBackBuffer);

}

