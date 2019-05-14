#include "Game.h"
#include "CellProcessor.h"
#include "Field.h"

#include <chrono>
#include <iostream>
#include <thread>

Game::Game(std::unique_ptr<Drawer> i_drawer) : d_isOver(false), d_drawer(std::move(i_drawer))
{

}

void Game::play()
{
  Field mainField;
  std::cin >> mainField;
  d_drawer->init();
  std::thread gameOverChecker(&Drawer::isOver, d_drawer.get(), std::ref(d_isOver));
  while(!d_isOver)
  {
    d_drawer->clear();
    Field buffer(mainField);
    for(auto cell = mainField.begin(); cell != mainField.end(); ++cell)
    {
      d_drawer->drawCell(*cell);
      buffer.addCell(processCell(*cell, cell.getNumberOfAliveNeighbours()));
    }
    d_drawer->refresh();
    mainField = buffer;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  gameOverChecker.join();
}


