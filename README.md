# Pong
A simple pong game in C++ using the SDL2 Library. It's work in progress at the moment.

When you compile it, you have to compile the C++ files together.

g++ -std=c++11 src/game.cpp src/main.cpp -c
g++ -o bin/Pong game.o main.o -lSDL2

That's how you compile the game on Linux

On Windows (make sure you have mingw and the SDL2 library files to compile this):

g++ -std=c++11 src\game.cpp src\main.cpp -c
g++ -o bin\Pong.exe game.o main.o -I{Path to SDL2\include} -L{Path to SDL2\lib} -Wall -lmingw32 -lSDL2main -lSDL2

For Windows users, I would recommend reading this guide before you do anything (unless you have it setup already):
https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php
