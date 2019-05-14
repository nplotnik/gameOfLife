#include "CellProcessor.h"

Cell processCell(const Cell& i_cell, int i_numberOfAliveNeighbours)
{
  Cell next(i_cell);
  if(i_numberOfAliveNeighbours > 3)
    next.d_state = State::InternalState::DEAD;
  if(i_numberOfAliveNeighbours < 2)
    next.d_state = State::InternalState::DEAD;
  if(i_numberOfAliveNeighbours == 3 && next.d_state == State::InternalState::DEAD)
    next.d_state = State::InternalState::ALIVE;
  return next;
}