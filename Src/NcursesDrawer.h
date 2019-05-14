#ifndef GAMEOFLIFE_NCURSESDRAWER_H
#define GAMEOFLIFE_NCURSESDRAWER_H

#include "Drawer.h"

class NcursesDrawer : public Drawer
{
 public:
  void init() const override;
  void drawCell(const Cell& i_cell) const override;
  void clear() const override;
  void refresh() const override;
  void isOver(std::atomic_bool& o_isOver) const override;
  ~NcursesDrawer();
};

#endif  // GAMEOFLIFE_NCURSESDRAWER_H
