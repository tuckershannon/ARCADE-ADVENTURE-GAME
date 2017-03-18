/****************************************
 * File: player.hpp 
 * Author: Tucker Shannon
 * Decription: player class header
 * Date: 3/17/17
 ****************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "npc.hpp"

class player: public npc{
	private:
		std::string inventory[5];
	public:
		player();
		~player();
		void addInvy(std::string);
		bool checkInvy(std::string);
		void decreaseCoins(int);
		int getCoins();
		void kill();
};

#endif
