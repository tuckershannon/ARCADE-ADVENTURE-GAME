/****************************************
 * File: npc.cpp 
 * Author: Tucker Shannon
 * Decription: npc function for moving and setting positions and coins
 * Date: 3/17/17
 ****************************************/



#include "npc.hpp"

/************************
 * npc constructor
 * **********************/
npc::npc(){
	name = "npcNULL";
}
/************************
 * setX position
 ************************/
void npc::setX(int x){
	mvprintw(yPos,xPos,"   ");
	xPos = x;
	mvprintw(yPos,xPos,body.c_str());
}


/************************
 * setY position
 ************************/

void npc::setY(int y){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");	
	}
	yPos = y;
	mvprintw(yPos,xPos,body.c_str());
}

/************************
 * getX position
 ************************/
int npc::getX(){
	return xPos;

}

/************************
 * get y position
 ************************/

int npc::getY(){
	return yPos;
}
/************************
 * npc::getBody()
 ************************/
std::string npc::getBody(){
	return this->body;
}
/************************
 * set body
 ************************/
void npc::setBody(std::string a){
	this->body = a;
}

/************************
 *set npc health
 ************************/
int npc::getCoins(){
	return this->coins;
}

void npc::setCoins(int h){
	this->coins = h;
}
std::string npc::getName(){
	return name;
}

/************************
 * Deconstrutor
 ************************/

void npc::moveY(int y){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");	
	}
	yPos += y;
	mvprintw(yPos,xPos,body.c_str());
}
void npc::moveX(int x){
	for (int i=0;i<body.length();i++){
		mvprintw(yPos,xPos+i," ");	
	}
	xPos += x;
	mvprintw(yPos,xPos,body.c_str());
}


npc::~npc(){
}
