vimCXX = g++
CXXFLAGS = -std=c++0x 

OBJS = npc.o player.o room.o defendRoom.o main.o alien.o bullet.o iceRoom.o caveRoom.o wallz.o ddrRoom.o menu.o startRoom.o finalRoom.o

SRCS = npc.cpp player.cpp room.cpp defendRoom.cpp main.cpp alien.cpp bullet.cpp iceRoom.cpp caveRoom.cpp wallz.cpp ddrRoom.cpp menu.cpp startRoom.cpp finalRoom.cpp
	
HEADERS = npc.hpp player.hpp room.hpp defendRoom.hpp alien.hpp bullet.hpp iceRoom.hpp caveRoom.hpp wallz.hpp ddrRoom.hpp menu.hpp startRoom.hpp finalRoom.hpp

final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o final -lncurses

clean:
	rm -f npc.o player.o room.o defendRoom.o main.o alien.o bullet.o iceRoom.o caveRoom.o wallz.o ddrRoom.o menu.o startRoom.o finalRoom.o

