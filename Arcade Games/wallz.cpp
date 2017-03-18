/****************************************
 * File: Wallz.cpp
 * Author: Tucker Shannon
 * Decription: wallz npc class. I made this to print two sided walls for the cave
 * Date: 3/17/17
 ****************************************/

#include "wallz.hpp"

/**************************************************************
 * constructor function
 **************************************************************/
	
wallz::wallz() : npc() {
	this -> body = "#";
}

/**************************************************************
 * destructor function
 **************************************************************/

wallz::~wallz(){

}

/************************
 * setX position
 ************************/
void wallz::setX(int x,int w){
		mvprintw(yPos,xPos," ");
		mvprintw(yPos+w,xPos," ");
	xPos = x;
	mvprintw(yPos,xPos,body.c_str());
	mvprintw(yPos+w,xPos,body.c_str());

}


/************************
 * setY position
 ************************/

void wallz::setY(int y, int w){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");
		mvprintw(yPos+w,xPos+i," ");	
	}
	yPos = y;
	mvprintw(yPos,xPos,body.c_str());
	mvprintw(yPos+w,xPos,body.c_str());

}
/**************************************************************
 * move y position
 **************************************************************/


void wallz::moveY(int y,int w){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");	
		mvprintw(yPos+w,xPos+i," ");	
	}
	yPos += y;
	mvprintw(yPos,xPos,body.c_str());
	mvprintw(yPos+w,xPos,body.c_str());
	
/**************************************************************
 * move x position
 **************************************************************/

}
void wallz::moveX(int x,int w){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");	
		mvprintw(yPos+w,xPos+i," ");	
	}
	xPos += x;
	mvprintw(yPos,xPos,body.c_str());
	mvprintw(yPos+w,xPos,body.c_str());

}



