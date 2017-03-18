/****************************************
 * File: defendRoom.cpp 
 * Author: Tucker Shannon
 * Decription: defend room class. SHOOTS aliens with spacebar
 * Date: 3/17/17
 ****************************************/

#include "defendRoom.hpp"
#include "npc.hpp"
#include <iostream>


/****************************
* constructor for room
****************************/
defendRoom::defendRoom(player *main): room(main){
	this -> rows = 30;
	this -> cols = 70;
	this->et = new alien;
	this->bullet1 = new bullet;

	//runGame();

}

/****************************
* function to determine if you hit alien with bullet
****************************/

bool isHit(double alienX,double alienY,int bulletX, int bulletY){
	if (abs(int(alienY) - bulletY)<2){
		if (bulletX - int(alienX) > -1 && bulletX - int(alienX) < 5){
			return true;
		} 
	}
	return false;
}


/****************************
* defend room deconstuctor 
****************************/


defendRoom::~defendRoom(){
	delete this->bullet1;
	delete this-> et;
}

/****************************
* defend room run game function
***************************/

void defendRoom::runGame(){

	//this function allows you to use sparce bar to shoot aliens with bullet
	//is has a loop to pickup arrow key inputs to move you character
	clear();
	mvprintw(10,cols/2-10,"WELCOME TO THE DEFENDER GAME");
	mvprintw(14,cols/2-10, "OBJECTIVE: SHOOT THE FRIGGIN ALIENS");
	mvprintw(16,cols/2-10, "CONTROLS: ARROW KEYS TO MOVE SPACE BAR TO SHOOT");
	mvprintw(18,cols/2-10, "YOU GOTTA STOP AT LEAST 15 ALIENS");

	mvprintw(22,cols/2-10,"PRESS ENTER KEY TO CONTINUE..");	
	while(getch() != 10){};
	clear();
	et->setX(cols/2);
	et->setY(1);
	main->setX(cols/2);
	main->setY(rows-1);

	
	int score = 0,x=0;
	double alienSpeed = 0.1;
	bool shotsFired = false;
	double move = 0;
	int ch;
	timeout(50);
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
			case ' ':
				shotsFired = true;
				bullet1->setX( main->getX() + 2 );
				bullet1->setY( main->getY() );
				break;
			default:
			{
				x = 0;
				attron(A_BOLD);
				printw("%c", ch);
				attroff(A_BOLD);
			}
		}	
		printWalls();
		move += alienSpeed;
		if (shotsFired){
			if (isHit(et->getX(),et->getY(),bullet1->getX(),bullet1->getY())){
				//et->setX() = 0;
				et->setY(1);
			  	et->setX(rand() % (cols-3)+1);
				shotsFired = false;
				alienSpeed+=0.02;
				score++;
			}
			if (bullet1->getY()>0){
				bullet1->moveY(-1);	
			}
			else{
				shotsFired = false;
			}
		}
		if (et->getY() >= rows){
			clear();
			if (score>=15){
				mvprintw(10, cols/2-10, "YOU STOPPED %d ALIENS",score);
				mvprintw(14, cols/2-10, "YOU'VE BEEN GIVEN A KEY FOR THE NEXT GAME");
				mvprintw(16, cols/2-10, "PRESS ENTER TO GO TO NEXT ROOM");
				main -> addInvy("KEY1");
			}
			else{
				mvprintw(LINES/2+2, cols/2-10, "ALIENS HAVE CAPTURED THE EARTH. RIP");
				mvprintw(LINES/2+4, cols/2-10, "PRESS ENTER TO CONINUE");
			}

			refresh();
			timeout(5000000);
			while (getch() != 10){
				
			};
			break;
		}
		if (move>=1){
			et->moveY(move);
			move = 0;
		}
		refresh();
		if (ch == 'q'){
			clear();
			refresh();
			break;
		}
		et->moveX(0);
		main->moveX(0);
		mvprintw(rows+1,1,"ALIENS DESTROYED: %d", score);
		mvprintw(rows+2,1,"QUARTERS LEFT: %d", main->getCoins());
		mvprintw(rows+3,1,"ARROW KEYS TO MOVE SPACE BAR TO SHOOT");

	}	
	//decrease coins for each attempt
	main->decreaseCoins(1);
}
