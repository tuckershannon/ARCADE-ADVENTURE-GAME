/****************************************
 * File: 
 * Author:
 * Decription:
 * Date: 3/17/17
 ****************************************/

#include "player.hpp"
#include <string>
#include <iostream>

 /************************
 * player constructor
 ************************/
player::player() : npc(){
	this -> body = "(o.O)";
	this -> coins = 100;
	for (int i=0;i<5;i++){
		this -> inventory[i] = "";
	}

}

 /************************
 * player deconstrucor
 ************************/
player::~player(){
}
 /************************
 *	kill player
 ************************/
void player::kill(){
	coins = 0;
}
 /************************
 * get players health
 ************************/
int player::getCoins(){
	return coins;
}

 /************************
 *	decrease health 
 ************************/
void player::decreaseCoins(int d){
	coins-=d;
}
 /************************
 * check inventory
 ************************/
bool player::checkInvy(std::string thing){
	bool found = false;
	for (int i=0;i<5;i++){
		if(inventory[i] == thing){
			found = true;
		}
	}
	return found;
}

 /************************
 * add an item tp the invy
 ************************/
void player::addInvy(std::string thing){
	int i =0;
	while (inventory[i] != ""){
			i++;
	}
	inventory[i] = thing;
}

