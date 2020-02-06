CXX = g++

CXXFLAGS = -Wall -O2

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

main: main.o Game.o Player.o Bullet.o Star.o
	$(CXX) $(CXXFLAGS) -o bin/Release/Spacewar main.o Game.o Player.o Bullet.o Star.o $(LIBS)
main.o: main.cpp include/Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(LIBS)
Game.o: data.h include/Game.h include/Player.h include/Bullet.h include/Star.h 
	$(CXX) $(CXXFLAGS) -c src/Game.cpp $(LIBS)
Player.o: data.h include/Player.h include/playerData.hpp
	$(CXX) $(CXXFLAGS) -c src/Player.cpp $(LIBS)
Bullet.o: data.h include/Bullet.h include/bulletData.hpp
	$(CXX) $(CXXFLAGS) -c src/Bullet.cpp $(LIBS)
Star.o: data.h include/Star.h
	$(CXX) $(CXXFLAGS) -c src/Star.cpp $(LIBS)
