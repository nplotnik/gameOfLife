#include "ConsoleDrawer.h"
#include "Cell.h"

#include <iostream>

void ConsoleDrawer::init() const
{

}

void ConsoleDrawer::drawCell(const Cell& i_cell) const
{
  if(i_cell.d_x == 0 && i_cell.d_y != 0)
    std::cout << std::endl;
  std::cout << i_cell.d_state;
}

void ConsoleDrawer::clear() const
{
  std::cout << "\033[2J\033[1;1H";
}

void ConsoleDrawer::refresh() const
{

}

void ConsoleDrawer::isOver(std::atomic_bool& o_isOver) const
{
  int c = std::getchar();
  std::cout << c << std::endl;
  o_isOver = true;
}



