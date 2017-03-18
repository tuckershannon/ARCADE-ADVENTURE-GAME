/****************************************
 * File: finalRoom.cpp 
 * Author: Tucker Shannon
 * Decription: final room class. This uses a few gifs animation NOT CREATED BY ME!!!!!!!
 * Date: 3/17/17
 ****************************************/

#include "finalRoom.hpp"
#include "npc.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "bullet.hpp"
/****************************
* constructor for room
****************************/
finalRoom::finalRoom(player *main): room(main){
	this -> rows = 10;
	this -> cols = 30;
	this->bullet1 = new bullet;
	//runGame();
}

/****************************
* deconstuctor for room 
****************************/

finalRoom::~finalRoom(){
	delete this-> bullet1;	
}

/****************************
* run game function. blows up the death star USING ANIMATIONS I DID NOT MAKE
****************************/

void finalRoom::runGame(){
	//USES ASCII IAMGES I FOUND AT ASCIIMATION.CO.NZ/
	//USES ASCII IAMGES I FOUND AT ASCIIMATION.CO.NZ/
	//USES ASCII IAMGES I FOUND AT ASCIIMATION.CO.NZ/

	clear();
	mvprintw(8,30/2-10,"FINAL CHALLENGE: DESTROY THE DEATH STAR");
	mvprintw(10,30/2-10,"USE THE FORCE LUKE");
	mvprintw(11,30/2-10,"LET GO LUKE...");
	mvprintw(12,30/2-10,"PRESS ENTER");
	while(getch()!=10){}
	std::ifstream file("deathstar.txt");
	std::string str;
	std::string ascii;
	int lines =0;

	while (std::getline(file, str)){
	  ascii += str;
	  mvprintw(lines,0,str.c_str());	
	  lines++;
	  ascii.push_back('\n');
	}
	
	mvprintw(35,30/2-10,"PRESS SPACE BAR TO USE FIRE THE X-WING");
	while(getch()!=' '){}
	timeout(200);
	bullet1->setY(16);
	bullet1->setX(23);

	while (bullet1->getY()>5){
				getch();
				bullet1->moveY(-1);	
	}

	system("boom"); //this calls a c animation file not created by me
	//all credits to squeamish ossifrage from stack exchange
	//http://codegolf.stackexchange.com/questions/24462/display-the-explosion-of-a-star-in-ascii-art	
	//the animation was only used for kicks and giggles
	system("clear");
	//initscr();
	clear();
	std::ifstream end("end.txt");
	lines = 0;
	while (std::getline(end, str)){
	  ascii += str;
	  mvprintw(lines,0,str.c_str());	 
	  lines++;
	  ascii.push_back('\n');
	}
	while(getch()!=10){}
}
