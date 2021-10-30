#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <algorithm>
#include <chrono>
#include <vector>

#include "Book.h"
#include "searchFunctions.h"
class Stopwatch {
 private:
  double m_total_time = 0;

 public:
  Stopwatch();
  int linear_stopwatch(const std::vector<Book> &nb, const std::vector<Book> &r);
  int binary_stopwatch(std::vector<Book> &nb, const std::vector<Book> &r);
  friend std::ostream &operator<<(std::ostream &stream,
                                  const Stopwatch stopwatch);
};
#endif