/****************************************
 * File: defendRoom.hpp 
 * Author: Tucker Shannon 
 * Decription: defend room class header
 * Date: 3/17/17
 ****************************************/

#ifndef DEFENDROOM_HPP
#define DEFENDROOM_HPP
#include "alien.hpp"
#include "room.hpp"
#include "bullet.hpp"
class defendRoom : public room{
	private:
		npc *et;
		npc *bullet1;
	public:
		defendRoom(player *main);
		~defendRoom();
		void runGame();
};
#endif
