/****************************************
 * File: finalRoom.hpp 
 * Author: Tucker Shannon
 * Decription: final room class header
 * Date: 3/17/17
 ****************************************/

#ifndef FINALROOM_HPP
#define FINALROOM_HPP
#include "room.hpp"

class finalRoom : public room{
	private:
		npc *bullet1;
	public:
		finalRoom(player *main);
		~finalRoom();
		void runGame();
};
#endif
