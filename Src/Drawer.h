#ifndef DRAWER_H_
#define DRAWER_H_

#include <atomic>
#include <boost/noncopyable.hpp>

class Field;
class Cell;

class Drawer : public boost::noncopyable {
 public:
  virtual void init() const = 0;
  virtual void drawCell(const Cell& i_cell) const = 0;
  virtual void clear() const = 0;
  virtual void isOver(std::atomic_bool& o_isOver) const = 0;
  virtual void refresh() const = 0;
  virtual ~Drawer() = default;
};

#endif /* DRAWER_H_ */
