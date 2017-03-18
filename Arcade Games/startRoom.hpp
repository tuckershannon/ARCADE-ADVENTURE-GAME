/****************************************
 * File: 
 * Author:
 * Decription:
 * Date: 3/17/17
 ****************************************/

#ifndef STARTROOM_HPP
#define STARTROOM_HPP
#include "room.hpp"
class startRoom : public room{
	public:
		startRoom(player *main);
		~startRoom();
		void runGame();

};
#endif
