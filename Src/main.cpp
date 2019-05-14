//============================================================================
// Name        : GameOfLife.cpp
// Author      : nplotnik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
#include "ConsoleDrawer.h"
#include "NcursesDrawer.h"

int main() {

  Game game(std::make_unique<ConsoleDrawer>());
  game.play();
  return 0;
}
