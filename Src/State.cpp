#include "State.h"

State::State(char i_state) : d_state(DEAD)
{
  if(i_state == '+')
    d_state = ALIVE;
}

State::State(InternalState i_state) : d_state(i_state)
{

}

State::operator char() const
{
  return d_state == ALIVE ? '+' : ' ';
}

bool State::operator==(InternalState i_state) const
{
  return d_state == i_state;
}


