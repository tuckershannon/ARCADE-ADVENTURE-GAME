/****************************************
 * File: ddrRoom.cpp 
 * Author: Tucker Shannon
 * Decription: dance dance revolution style game room
 * Date: 3/17/17
 ****************************************/

#include "ddrRoom.hpp"
#include "npc.hpp"
#include <iostream>
#include <stack>
#include <vector>

/****************************
* constructor for room
****************************/
ddrRoom::ddrRoom(player *main): room(main){
	this -> rows = 30;
	this -> cols = 70;
}
/***************************************************
 * room deconstuctor
 ***************************************************/   
ddrRoom::~ddrRoom(){
}

/***************************************************
 * run game functon
 ***************************************************/   
void ddrRoom::runGame(){
	clear();
	mvprintw(10,30/2-10,"DANCE DANCE REVOLUTON");
	mvprintw(14,30/2-10, "OBJECTIVE: TYPE THE CORRECT ARROW KEYS RIGHT BEFORE THEY PASS THE LINE");
	mvprintw(15,30/2-10, "50 POINTS TO PASS");
	mvprintw(16,30/2-10, "SONG: THROUGH THE FIRE AND THE FLAMES ft. ZEZIMA");
	mvprintw(22,30/2-10,"PRESS ENTER KEY TO START..");	
	while(getch()!=10){}
	clear();
	main->setX(cols/2);
	main->setY(rows-1);
	size_t size= 50;
	std::vector<alien*> ice(size);
	int isicles = 1;
	int score = 0;
	float iceSpeed = 0.1;
	float move = 0.1;
	int ch;
	int count = 0;
	bool addNote,added=false;
	int rando,keypress,points=0,missed=0;
	for (int i=0; i<size;i++){
		ice[i] = new alien;
		ice[i] -> setY(20);
		rando = rand() %4 +1;
		switch(rando){
			case 1:
				ice[i] -> setBody("^");
				ice[i] -> setX(17);
				break;
			case 2:
				ice[i] -> setBody(">");
				ice[i] -> setX(18);
				break;
			case 3:
				ice[i] -> setBody("v");
				ice[i] -> setX(16);
				break;
			case 4:
				ice[i] -> setBody("<");
				ice[i] -> setX(15);
		}	
	}	
	move =  0;	
	timeout(50);
	while((ch = getch()) != 'q'){
		clear();
		switch(ch){
			//get keypress
			case KEY_LEFT:
				keypress = 4;
				break;
			case KEY_RIGHT:
				keypress = 2;
				break;
			case KEY_UP:
				keypress = 1;
				break;
			case KEY_DOWN:
				keypress = 3;
				break;
			default:
			{
				attron(A_BOLD);
				printw("%c", ch);
				attroff(A_BOLD);
			}
		}
		//pritn walls
		for(int i=0;i<=rows;i++){
			if (i==rows){
				for(int j=13;j<20;j++){
					mvprintw(i,j,"-");
				}
			}
			else{
				mvprintw(i,13,"|");
				mvprintw(i,20,"|");
			}
		}	
		count++;
		move=move+0.1;
		if (count >= 70){
			count = 0;
			addNote = true;
			for (int i=0;i<isicles;i++){
				if (ice[i]->getY() > rows-1 || ice[i]->getY() == 20){
					addNote = false;
				}
			}
			if (addNote){
				isicles++;
			}
		}
		for (int i = 0;i<isicles;i++){
			if (ice[i]->getY() == 20 && added){
				added = false;
				rando = rand() %4 +1;
				switch(rando){
					case 1:
						ice[i] -> setBody("^");
						ice[i] -> setX(17);
						break;
					case 2:
						ice[i] -> setBody(">");
						ice[i] -> setX(18);
						break;
					case 3:
						ice[i] -> setBody("v");
						ice[i] -> setX(16);
						break;
					case 4:
						ice[i] -> setBody("<");
						ice[i] -> setX(15);
				}	
			}
			if (move>=1){	
				ice[i] -> moveY(1);
			}
			else{
				ice[i] -> moveY(0);
			}
			if (ice[i] -> getY() > rows-1){
				if(ice[i] -> getBody() == "^"){
					if (keypress != 1){
						missed++;
					}
				}
				else if(ice[i] -> getBody() == ">"){
					if (keypress != 2){
						missed++;
					}
				}
				else if(ice[i] -> getBody() == "v"){
					if (keypress != 3){
						missed++;
					}
				}
				else if(ice[i] -> getBody() == "<"){
					if (keypress != 4){
						missed++;
					}
				}
				points++;
				added = true;
				ice[i]-> setY(20);
			}
		}
		if (move>=1){
			move = 0;
		}
	if (missed>=10){
			clear();
			if (points>=50){
				mvprintw(10, cols/2-10, "SCORE %d",points);
				mvprintw(12, cols/2-10, "NICE");
				mvprintw(14, cols/2-10, "YOU'VE BEEN GIVEN A KEY FOR THE NEXT GAME");
				mvprintw(16, cols/2-10, "PRESS ENTER TO GO TO NEXT ROOM");
				main->addInvy("KEY4");
			}
			else{
				mvprintw(10, cols/2-10, "YOU DON'T DANCE AND IF YOU DONT DANCE");
				mvprintw(11, cols/2-10, "WELL YOU'RE NO FRIEND OF MINE. TRY AGAIN");
				mvprintw(14, cols/2-10, "PRESS ENTER TO CONINUE");
			}
			refresh();
			timeout(5000000);
			while (getch() != 10){
			};
			break;
		}
		mvprintw(rows+1,1,"SCORE: %d", points); 
		mvprintw(rows+3,1,"MISSED NOTES: %d",missed);
		mvprintw(rows+4,1,"QUARTERS LEFT: %d", main->getCoins());
		mvprintw(rows+5,1,"ARROW KEYS TO PLAY");
	}
	for (std::vector< alien* >::iterator it = ice.begin() ; it != ice.end(); ++it){
		delete (*it);
	} 
   ice.clear();
	main->decreaseCoins(1);
}
