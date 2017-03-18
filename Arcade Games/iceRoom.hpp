/****************************************
 * File: iceRoom.hpp 
 * Author: Tucker hannon
 * Decription: iceroom class header file 
 * Date: 3/17/17
 ****************************************/

#ifndef ICEROOM_HPP
#define ICEROOM_HPP
#include "alien.hpp"
#include "room.hpp"
class iceRoom : public room{
	public:
		iceRoom(player *main);
		~iceRoom();
		void runGame();
};
#endif
