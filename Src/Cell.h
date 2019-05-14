#ifndef CELL_H_
#define CELL_H_

#include "State.h"

struct Cell
{
  Cell(int i_x, int i_y, char i_state) : d_x(i_x), d_y(i_y), d_state(i_state) {}
  Cell(int i_x, int i_y, State::InternalState i_state) : d_x(i_x), d_y(i_y), d_state(i_state) {}
  int d_x;
  int d_y;
  State d_state;
};

#endif /* CELL_H_ */
