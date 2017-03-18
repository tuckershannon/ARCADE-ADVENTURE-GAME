/****************************************
 * File: caveRoom.cpp 
 * Author: Tucker Shannon
 * Decription: cave room class file. dodge the walls with arrow keys
 * Date: 3/17/17
 ****************************************/

#include "caveRoom.hpp"
#include "npc.hpp"
#include <iostream>
#include <vector>
#include "wallz.hpp"

/****************************
* constructor for room
****************************/
caveRoom::caveRoom(player *main): room(main){
	this -> rows = 30;
	this -> cols = 70;	
}
/********************************************************************
 * deconstructor for class
 ********************************************************************/
caveRoom::~caveRoom(){
}
/********************************************************************
 * runGame function. creates jagged walls that close in eventually
 ********************************************************************/

void caveRoom::runGame(){
	clear();

	//printing the menu
	mvprintw(10,cols/2-10,"WELCOME TO THE CAVE GAME");
	mvprintw(14,cols/2-10, "OBJECTIVE: DODGE THE FRIGGIN WALLS");
	mvprintw(15,cols/2-10, "NEED SCORE OF 6 TO MOVE ON");
	mvprintw(16,cols/2-10, "CONTROLS: ARROW KEYS TO MOVE");
	mvprintw(22,cols/2-10,"PRESS ENTER KEY TO START..");	
	
	while(getch() != 10){}
	clear();
	main->setX(1);
	main->setY(rows/2);


	size_t size= cols-2;
	std::vector<wallz*> walls(size);
	int isicles = 1;
	int score = 0;
	double wallSpeed = 0.1; 
	int caveWidth = 20;
	double move = 0;
	int ch;
	int count = 0;
	bool lost = false;
	int caveMover = 1,topDistance=5,bottomDistance;

	for (int i=0; i<size;i++){
		walls[i] = new wallz;
		walls[i] -> setBody("#");
		walls[i] -> setX(i+1,caveWidth);
		walls[i] -> setY(5,caveWidth);
	}
	timeout(100);
	
	while((ch = getch()) != 'q'){
		if (caveMover == 0){
			caveMover = rand()%(bottomDistance+topDistance+1)-topDistance;
		}	
		clear();
		//get keyboard input
		switch(ch){
			case KEY_UP:
				if (main->getY()>=2)
					main->moveY(-1);
				break;
			case KEY_DOWN:
				if (main->getY() <= rows-1)
					main->moveY(1);
				break;
			default:
			{
				attron(A_BOLD);
				printw("%c", ch);
				attroff(A_BOLD);
				main->moveX(0);
			}
		}	
		//move the walls in 
		move += wallSpeed;
		count++;
		if (count >= 100){
			caveWidth--;
			count = 0;
			score++;
		}
		printWalls();
		for (int i=0;i<size;i++){
			walls[i] -> moveX(-1,caveWidth);
			if (walls[i] -> getX() <=6){
				if(main->getY()== walls[i] ->getY() || main->getY()== walls[i] ->getY()+caveWidth ){
					lost = true;
				}
			}

			if (walls[i] -> getX() <= 1){

				walls[i]-> setX(cols-1,caveWidth);
				if (caveMover > 0){
					walls[i]->setY(topDistance+1,caveWidth);
					caveMover--;

					topDistance = walls[i]->getY();
					bottomDistance = rows-topDistance-caveWidth;

				}
				else{
					walls[i]->setY(topDistance-1,caveWidth);
					caveMover++;
					topDistance = walls[i]->getY();
					bottomDistance = rows-topDistance-caveWidth;

				}
			}
		}
		//if you lose then do this
		if (lost){
			clear();
			if (score>=6){
				mvprintw(10, cols/2-10, "SCORE %d",score);
				mvprintw(14, cols/2-10, "YOU'VE BEEN GIVEN A KEY FOR THE NEXT GAME");
				mvprintw(16, cols/2-10, "PRESS ENTER TO GO TO NEXT ROOM");
				main->addInvy("KEY3");
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
		mvprintw(rows+1,1,"SCORE: %d", score);
		mvprintw(rows+2,1,"QUARTERS LEFT: %d", main->getCoins());
		mvprintw(rows+3,1,"ARROW KEYS TO MOVE");
					
	}
	main->decreaseCoins(1);

	for (std::vector< wallz* >::iterator it = walls.begin() ; it != walls.end(); ++it){
		delete (*it);

	} 
   walls.clear();
}
