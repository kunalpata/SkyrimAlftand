#makefile inspired by lecture
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Menu.o InputValidation.o Characters.o Nord.o Falmer.o Spider.o Bandit.o Game.o Space.o Glacial.o Lab.o Alftand.o Dungeon.o Tower.o Cathedral.o main.o

SRCS = Menu.cpp InputValidation.cpp Characters.cpp Nord.cpp Falmer.cpp Spider.cpp Bandit.cpp Game.cpp Space.cpp Glacial.cpp Lab.cpp Alftand.cpp Dungeon.cpp Tower.cpp Cathedral.cpp main.cpp

HEADERS = Menu.hpp InputValidation.hpp Characters.hpp Nord.hpp Falmer.hpp Spider.hpp Bandit.hpp Game.hpp Space.hpp Glacial.hpp Lab.hpp Alftand.hpp Dungeon.hpp Tower.hpp Cathedral.hpp



main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o FinalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm *.o FinalProject


