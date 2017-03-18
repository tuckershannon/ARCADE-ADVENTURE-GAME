/****************************************
 * File: iceRoom.cpp 
 * Author: Tucker Shannon
 * Decription: dodge falling ice game room
 * Date: 3/17/17
 ****************************************/

#include "iceRoom.hpp"
#include "npc.hpp"
#include <iostream>
#include <stack>
#include <vector>

/****************************
* constructor for room
****************************/
iceRoom::iceRoom(player *main): room(main){
	this -> rows = 30;
	this -> cols = 70;
}
/*************************************************
 * room deconstructor
 *************************************************/
iceRoom::~iceRoom(){
}
/*************************************************
 * run game function. make ice fall from ceiling
 ************************************************/
void iceRoom::runGame(){
	clear(); 
	//print welcom instructions
	mvprintw(10,cols/2-10,"WELCOME TO THE ICE GAME");
	mvprintw(14,cols/2-10, "OBJECTIVE: DODGE THE FRIGGIN ICE");
	mvprintw(16,cols/2-10, "CONTROLS: ARROW KEYS TO MOVE 15 POINTS TO PASS");
	mvprintw(22,cols/2-10,"PRESS ENTER KEY TO START..");	
	while(getch() != 10){};
	clear();
	main->setX(cols/2);
	main->setY(rows-1);

	//set up falling isicles
	size_t size= 50;
	std::vector<alien*> ice(size);
	std::vector<double> speeds(size);
	int isicles = 1;
	int score = 0;
	double iceSpeed = 0.1;
	double move = 0;
	int ch;
	int count = 0;
	bool lost = false;
	for (int i=0; i<size;i++){
		ice[i] = new alien;
		ice[i] -> setBody("V");
		ice[i] -> setX(rand() % (cols-3)+1);
		ice[i] -> setY(1);
		speeds[i] = 0;
	}
	
	timeout(50);
	//get keyboard input
	while((ch = getch()) != 'q'){
		clear();
		switch(ch){
			case KEY_LEFT:
				if (main->getX()>=2)
					main->moveX(-2);
				break;
			case KEY_RIGHT:
				if (main->getX() <= cols -5)
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
		count++;
		if (count >= 50){
			count = 0;
			isicles++;
		}
		printWalls();
		for (int i = 0;i<isicles;i++){
			speeds[i]+=0.1 *1.05*(i+1); 
			//make ice fall at varying speeds
			if (speeds[i]>=1){	
				ice[i] -> moveY(1);
				speeds[i] = 0;
			}
			else{
				ice[i] -> moveY(0);
			}
			if (ice[i] -> getY() > rows-1){
				if(main->getX() + 5> ice[i]->getX() && main->getX() - 1 < ice[i] ->getX()){
					lost = true;
				} 
				ice[i]-> setY(1);
				ice[i]-> setX(rand() % (cols-3) +1);
			}
		}
		//if ya lose then do this
		if (lost){
			clear();
			if (isicles>=15){
				mvprintw(10, cols/2-10, "SCORE %d",isicles);
				mvprintw(14, cols/2-10, "YOU'VE BEEN GIVEN A KEY FOR THE NEXT GAME");
				mvprintw(16, cols/2-10, "PRESS ENTER TO GO TO NEXT ROOM");
				main->addInvy("KEY2");
			}
			else{
				mvprintw(10, cols/2-10, "YOU HAVE DISHONERED YOUR FAIMLY");
				mvprintw(12, cols/2-10, "PRESS ENTER TO CONINUE");
			}

			refresh();
			timeout(5000000);
			while (getch() != 10){
				
			};
			break;
		}
		mvprintw(rows+1,1,"SCORE: %d", isicles);
		mvprintw(rows+2,1,"QUARTERS LEFT: %d", main->getCoins());
		mvprintw(rows+3,1,"ARROW KEYS TO MOVE");
	}
	//take coin for each attempt
	main->decreaseCoins(1);
	for (std::vector< alien* >::iterator it = ice.begin() ; it != ice.end(); ++it)
		   {
			     delete (*it);
			} 
   ice.clear();
} 
