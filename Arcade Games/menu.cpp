/****************************************
 * File: menu.cpp 
 * Author: Tucker Shannon
 * Decription: menu function that displays contols to user 
 * Date: 3/17/17
 ****************************************/
#include "menu.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "room.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "defendRoom.hpp"
#include "iceRoom.hpp"
#include "caveRoom.hpp"
#include "ddrRoom.hpp"
#include "startRoom.hpp"
#include "finalRoom.hpp"
#include <iostream>
/************************************
 * PRINT MENU FUNCTION 
 ***********************************/

void printMenu(){
	//initiate scren for printing
	//this allow allows me to use arrow key input via ncurses
	initscr();
	raw();
	keypad(stdscr, TRUE); //for using keyboard inputs
	noecho(); //dont print key presses
	srand((unsigned)time(0)); //set random seed

	//initiate objects and classes
	player *main = new player; 
	room *currentRoom;
	room *start = new startRoom(main);
	room *def = new defendRoom(main);	
	room *ice = new iceRoom(main);
	room *cave = new caveRoom(main);
	room *ddr = new ddrRoom(main);
	room *end = new finalRoom(main);

	//set the four way pointers..
	def->setTop(ice);
	ice->setRight(cave);
	cave->setBottom(ddr);
	currentRoom = def;	
	start -> runGame();

	// setting up the game and making sure their life hasnt run out...
	while (!main->checkInvy("KEY1") && main->getCoins() > 0){
		currentRoom-> runGame();
	}
	currentRoom = currentRoom->getTop();
	
	while (!main->checkInvy("KEY2") && main->getCoins() > 0){
		currentRoom-> runGame();
	}
	
	currentRoom = currentRoom->getRight();
	
	while (!main->checkInvy("KEY3") && main->getCoins() > 0){
		currentRoom-> runGame();
	}
	currentRoom = currentRoom->getBottom();
	
	while (!main->checkInvy("KEY4") && main->getCoins() > 0){
		currentRoom-> runGame();
	}
	
	if (main->getCoins() > 0){
		end->runGame();
	}
	else{
		std::cout<<"You ran out of quarters. GAME OVER"<<std::endl;
	}
	
	endwin();
	delete main;
	delete start;
	delete def;
	delete ice;
	delete cave;
	delete ddr; 
	delete end;
	system("clear");	
}

