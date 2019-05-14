#include "Field.h"

#include <algorithm>
#include <memory>

Field::Iterator::Iterator(const Field& i_field, int i_index)
    : d_field(i_field), d_index(i_index) {}

const Cell& Field::Iterator::operator*() const {
  return d_field.d_cells[d_index];
}

Field::Iterator& Field::Iterator::operator++() {
  ++d_index;
  return *this;
}

Field::Iterator Field::Iterator::operator++(int) const {
  return Iterator(d_field, d_index + 1);
}

Field::Iterator Field::begin() const { return Iterator(*this, 0); }

Field::Iterator Field::end() const {
  return Iterator(*this, d_width * d_height);
}

bool Field::Iterator::operator==(const Field::Iterator& anotherIterator) const {
  return std::addressof(this->d_field) ==
             std::addressof(anotherIterator.d_field) &&
         this->d_index == anotherIterator.d_index;
}

bool Field::Iterator::operator!=(const Field::Iterator& anotherIterator) const {
  return !(*this == anotherIterator);
}
int Field::Iterator::getNumberOfAliveNeighbours() const {
  int row = d_field.d_cells[d_index].d_y;
  int column = d_field.d_cells[d_index].d_x;
  std::array<int, 8> possibleNeighboursIndexes = {
      d_index - d_field.d_width - 1,
      d_index - d_field.d_width,
      d_index - d_field.d_width + 1,
      d_index - 1,
      d_index + 1,
      d_index + d_field.d_width - 1,
      d_index + d_field.d_width,
      d_index + d_field.d_width + 1,
  };
  int numberOfAliveNeighbours = 0;
  for(const auto& possibleNeighbourIndex : possibleNeighboursIndexes)
  {
    if(possibleNeighbourIndex >= 0 && possibleNeighbourIndex < d_field.d_cells.size() && d_field.d_cells[possibleNeighbourIndex].d_state == State::InternalState::ALIVE)
      numberOfAliveNeighbours++;
  }
  return numberOfAliveNeighbours;
}


void Field::addCell(const Cell& i_cell)
{
  d_cells.insert(d_cells.begin() + i_cell.d_y*d_width + i_cell.d_x, std::move(i_cell));
}

std::istream& operator>>(std::istream& input, Field& o_field) {
  std::istreambuf_iterator<char> begin(input), end;
  int column = 0;
  int row = 0;
  std::for_each(begin, end, [&o_field, &column, &row](char current) {
    if (current != '\n') {
      o_field.d_cells.emplace_back(column, row, current);
      ++column;
    } else {
      if (column > o_field.d_width) o_field.d_width = column;
      ++row;
      column = 0;
    }
  });
  o_field.d_height = row + 1;
  return input;
}
