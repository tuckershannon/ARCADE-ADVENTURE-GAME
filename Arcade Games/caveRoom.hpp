/****************************************
 * File: caveRoom.hpp 
 * Author: Tucker Shannon
 * Decription: header file for cave room class
 * Date: 3/17/17
 ****************************************/

#ifndef CAVEROOM_HPP
#define CAVEROOM_HPP
#include "alien.hpp"
#include "room.hpp"
#include "wallz.hpp"
class caveRoom : public room{
	public:
		caveRoom(player *main);
		~caveRoom();
		void runGame();

};
#endif
