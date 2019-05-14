#ifndef CONSOLEDRAWER_H_
#define CONSOLEDRAWER_H_

#include "Drawer.h"

class ConsoleDrawer: public Drawer
{
public:
  void init() const override;
  void drawCell(const Cell& i_cell) const override;
  void clear() const override;
  void refresh() const override;
  void isOver(std::atomic_bool& o_isOver) const override;
};

#endif /* CONSOLEDRAWER_H_ */
