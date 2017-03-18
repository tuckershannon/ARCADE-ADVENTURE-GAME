/****************************************
 * File: room.hpp
 * Author: Tucker Shannon
 * Decription: "space"  for the charatcer to use
 * Date: 3/17/17
 ****************************************/

#include "npc.hpp"
#include "player.hpp"


#ifndef ROOM_HPP
#define ROOM_HPP

class room{
	protected:
		room *top;
		room *bottom;
		room *left;
		room *right;
		int rows;
		int cols;
		player *main;
		npc *enemy;
		
	public:
		room(player *main);
		virtual~room(); //pure virtual room	
		virtual void printWalls();
		virtual void setTop(room*);
		virtual void setRight(room*);
		virtual void setBottom(room*);
		virtual void setLeft(room*);
		virtual room* getTop();
		virtual room* getRight();
		virtual room* getBottom();
		virtual room* getLeft();
		virtual void runGame();
	
		

};
#endif
