/****************************************
 * File: startRoom.cpp 
 * Author: Tucker shannon
 * Decription: startRoom where you get a bag of coins to start you journey
 * Date: 3/17/17
 ****************************************/

#include "startRoom.hpp"
#include "npc.hpp"
#include <iostream>
#include <stack>
#include <vector>

/****************************
* constructor for room
****************************/
startRoom::startRoom(player *main): room(main){
	this -> rows = 10;
	this -> cols = 30;
}
/*************************************************
 * deconstructor room game function
 *************************************************/
startRoom::~startRoom(){
}
/*************************************************
 * run start room game function
 *************************************************/

void startRoom::runGame(){
	//print out the menu
	mvprintw(10,30/2-10,"GAME TITLE: PURE PROCRASTINATION ARCADE");
	mvprintw(14,30/2-10,"OBJECTIVE:");
	mvprintw(13,30/2-10,"BEAT ALL THE ARCADE GAMES WITH 10 QUARTERS");
	mvprintw(14,30/2-10,"DON'T DIE TOO MANY TIMES OR YOU RUN OUT OF QUARTERS");
	mvprintw(15,30/2-10,"AND YOU'LL HAVE TO RESTART");
	mvprintw(16,30/2-10,"CONTROLS: USE YOUR ARROW KEYS AND SPACE BAR");
	mvprintw(18,30/2-10,"GET THE BAG OF QUARTERS TO START YOUR ADVENTURE");
	mvprintw(19,30/2-10,"GOOD LUCK! PRESS ANY KEY TO START!");
	
	int ch;	
	getch();
	clear();
	main->setX(cols/2);
	main->setY(rows/2);
	timeout(50);
	//get keyboard inputs
	while((ch = getch()) != 'q'){
		clear();
		switch(ch){
			case KEY_RIGHT:
				main->moveX(2);
				break;
			default:
			{
				attron(A_BOLD);
				printw("%c", ch);
				attroff(A_BOLD);
				main->moveX(0);	
			}
		}
		printWalls();
		mvprintw(rows/2,cols-2,"$");
		refresh();
		//if you character touches the money bag
		if (main->getX() >=cols-7){
			main->setCoins(10); //add 10 quarters to the main character
			break;
		}
	mvprintw(rows+1,1,"USE ARROW KEYS TO GET THE BAG OF QUARTERS");
	}
}
