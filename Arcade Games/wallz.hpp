/****************************************
 * File: wall.hpp 
 * Author: Tucker Shannon
 * Decription: wallz class header file
 * Date: 3/17/17
 ****************************************/

#ifndef WALLZ_HPP
#define WALLZ_HPP
#include "npc.hpp"

class wallz: public npc{
	public:
		wallz();
		~wallz();
		void setX(int,int);
		void setY(int,int);
		void moveX(int,int);
		void moveY(int,int);


};

#endif
