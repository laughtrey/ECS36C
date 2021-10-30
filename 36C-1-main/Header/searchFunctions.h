#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H
#include <vector>

#include "Book.h"
int linear_search(const std::vector<Book> &nb, const std::vector<Book> &r);
int binary_search_parse(const std::vector<Book> &nb,
                        const std::vector<Book> &r);
int binary_search(const std::vector<Book> &v, int from, int to,
                  const int &value);
#endif