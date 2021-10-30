#include "searchFunctions.h"
/**
 * @brief searches all of nb for r linearlly
 * 
 * @param nb new book vector
 * @param r requested book vector
 * @return int number of times requested books found in new book vector
 */
int linear_search(const std::vector<Book> &nb, const std::vector<Book> &r) {
  int count = 0;
  for (auto i : nb) {
    for (auto j : r) {
      if (i.get_isbn() == j.get_isbn()) {
        count += 1;
      }
    }
  }
  return count;
  // print to result.dat
}
/**
 * @brief searches all of nb for r with binary search
 * 
 * @param nb new book vector
 * @param r request book vector
 * @return int number of times request books found in new book vector
 */
int binary_search_parse(const std::vector<Book> &nb,
                        const std::vector<Book> &r) {
  int count = 0;
  for (auto &i : r) {
    count += binary_search(nb, 0, nb.size() - 1, i.get_isbn());
  }
  return count;
  // print to result.dat
}
/**
 * @brief recursive binary search function
 * 
 * @param v vector to search through
 * @param from start point
 * @param to end point
 * @param value information requested
 * @return int value found in vector returns 1 or true
 */
int binary_search(const std::vector<Book> &v, int from, int to,
                  const int &value) {
  if (from > to) return 0;
  int mid = (from + to) / 2;
  if (v[mid].get_isbn() == value)
    return 1;
  else if (v[mid].get_isbn() < value)
    return binary_search(v, mid + 1, to, value);
  else
    return binary_search(v, from, mid - 1, value);
}