/****************************************
 * File: npc.hpp 
 * Author: tucker shannon
 * Decription: npc or non player character file
 * Date: 3/17/17
 ****************************************/
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef NPC_HPP
#define NPC_HPP


/*************
 * NPC is anything in the room 
 **************/
class npc{
	protected:
		std::string body;
		std::string name;
		int xPos;
		int yPos;
		int coins;
		bool direction;
	public:
		npc();
		virtual ~npc() = 0; //pure virtual function
		virtual void setX(int);
		virtual void setY(int);
		int getX();
		int getY();
		std::string getBody();
		void setBody(std::string);
		std::string getName();
		int getCoins();
		void setCoins(int);
		virtual void moveX(int);
		virtual void moveY(int);	
};

#endif
