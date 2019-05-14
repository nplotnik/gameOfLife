#include "NcursesDrawer.h"
#include "Cell.h"
#include <ncurses.h>

void NcursesDrawer::init() const
{
  ::initscr();
}

void NcursesDrawer::drawCell(const Cell& i_cell) const
{
  ::mvprintw(i_cell.d_y, i_cell.d_x, "J");
}

void NcursesDrawer::clear() const
{
  ::clear();
}

void NcursesDrawer::refresh() const
{
  ::refresh();
}

void NcursesDrawer::isOver(std::atomic_bool& o_isOver) const
{
  getch();
  o_isOver = true;
}

NcursesDrawer::~NcursesDrawer()
{
  ::endwin();
}