simple2dBallGame: src/main.cpp src/Game.cpp src/Player.cpp src/SwagBall.cpp assets/fonts/Dosis-Light.ttf
	c++ -c src/main.cpp src/Game.cpp src/Player.cpp src/SwagBall.cpp
	g++ main.o Game.o Player.o SwagBall.o -o ballgameapp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network