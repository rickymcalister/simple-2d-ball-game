simple2dBallGame: src/main.cpp src/Game.cpp src/Player.cpp
	c++ -c src/main.cpp src/Game.cpp src/Player.cpp
	g++ main.o Game.o Player.o -o ballgameapp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network