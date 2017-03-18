/****************************************
 * File: room.cpp
 * Author: Tucker Shannon
 * Decription: room abstract class. other rooms inherit from this
 * Date: 3/17/17
 ****************************************/

#include "room.hpp"
#include "npc.hpp"
#include "player.hpp"

/*****************************************************
 * class constructor
 *****************************************************/
room::room(player *user){
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	main = user;
}

/*****************************************************
 *class deconstructor 
 *****************************************************/

room::~room(){
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}
/*****************************************************
 * print the walls of the room function 
 *****************************************************/

void room::printWalls(){
	for(int i=0;i<=rows;i++){
		if (i==0 || i==rows){
			for(int j=0;j<cols;j++){
				mvprintw(i,j,"-");
			}
		}
		else{
			mvprintw(i,0,"|");
			mvprintw(i,cols,"|");
		}
	}	
}


/*****************************************************
 * set top pointer 
*****************************************************/

void room::setTop(room *r){
	this-> top = r;
}

/***************************************************
 *set right pointer
 ***************************************************/    
void room::setRight(room *r){
	this-> right = r;
}

/***************************************************
 * set bottom pointer
 ***************************************************/   
void room::setBottom(room *r){
	this-> bottom = r;
}
/***************************************************
 * set left pointer
 ***************************************************/   
void room::setLeft(room *r){
	this-> left = r;
}

room* room::getTop(){
	return this->top;
}


/***************************************************
 * set top pointer
 ***************************************************/   
room* room::getRight(){
	return this->right;
}
/***************************************************
 * set bottom pointer
 ***************************************************/   

room* room::getBottom(){
	return this->bottom;
}


/***************************************************
 * set left pointer
 ***************************************************/   
room* room::getLeft(){
	return this->left;
}

/***************************************************
 *
 ***************************************************/   
void room::runGame(){

}
