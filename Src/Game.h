#ifndef GAME_H_
#define GAME_H_

#include "Drawer.h"
#include <memory>
#include <atomic>
#include <boost/noncopyable.hpp>


class Game : public boost::noncopyable
{
  std::atomic_bool d_isOver;
  std::unique_ptr<Drawer> d_drawer;
public:
  Game(std::unique_ptr<Drawer> i_drawer);
  void play();
};



#endif /* GAME_H_ */
