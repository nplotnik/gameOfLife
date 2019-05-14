#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"

#include <istream>
#include <vector>

class Field {
  int d_width = 0;
  int d_height = 0;
  std::vector<Cell> d_cells;

  class Iterator {
    const Field& d_field;
    int d_index = 0;
    Iterator operator++(int) const;
    bool operator==(const Iterator& anotherIterator) const;

   public:
    Iterator(const Field& i_field, int i_index);
    const Cell& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& anotherIterator) const;
    int getNumberOfAliveNeighbours() const;
  };

 public:
  Field() = default;
  void addCell(const Cell& i_cell);
  Iterator begin() const;
  Iterator end() const;

  friend std::istream& operator>>(std::istream& input, Field& o_field);
};

#endif
