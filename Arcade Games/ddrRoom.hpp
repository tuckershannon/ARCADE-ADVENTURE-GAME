/****************************************
 * File: ddrRoom.hpp 
 * Author: Tucker Shannon 
 * Decription: header file for ddr class
 * Date: 3/17/17
 ****************************************/

#ifndef DDRROOM_HPP
#define DDRROOM_HPP
#include "alien.hpp"
#include "room.hpp"
class ddrRoom : public room{
	public:
		ddrRoom(player *main);
		~ddrRoom();
		void runGame();

};
#endif
