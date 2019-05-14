#ifndef STATE_H_
#define STATE_H_

class State
{
public:
  enum InternalState
  {
    DEAD,
    ALIVE
  };
  State(char i_state);
  State(InternalState i_state);
  bool operator==(InternalState i_state) const;
  operator char() const;
private:
  InternalState d_state;
};


#endif /* STATE_H_ */
