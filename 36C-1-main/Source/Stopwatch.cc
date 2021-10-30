#include "Stopwatch.h"
/**
 * @brief Construct a new Stopwatch:: Stopwatch object
 * 
 */
Stopwatch::Stopwatch() { m_total_time = 0; }
/**
 * @brief times a linear search and sets the objects member time to total microseconds.
 * 
 * @param nb newbooks vector
 * @param r requested books vector
 * @return int amount of books found in search
 */
int Stopwatch::linear_stopwatch(const std::vector<Book> &nb,
                                const std::vector<Book> &r) {
  auto start = std::chrono::high_resolution_clock::now();
  int count = linear_search(nb, r);
  auto end = std::chrono::high_resolution_clock::now();
  double total_time =
      std::chrono::duration<double, std::micro>(end - start).count();
  m_total_time = total_time;
  return count;
}
/**
 * @brief times a binary search, and sets the objects member time to total microseconds.
 * 
 * @param nb newbooks vector
 * @param r requested books vector
 * @return int amount of books found in search
 */
int Stopwatch::binary_stopwatch(std::vector<Book> &nb,
                                const std::vector<Book> &r) {
  auto start = std::chrono::high_resolution_clock::now();
  std::sort(nb.begin(), nb.end());
  int count = binary_search_parse(nb, r);
  auto end = std::chrono::high_resolution_clock::now();
  double total_time =
      std::chrono::duration<double, std::micro>(end - start).count();
  m_total_time = total_time;
  return count;
}
/**
 * @brief overloads output stream to print the time of the stopwatch object
 * 
 * @param stream ostream object
 * @param stopwatch the stopwatch object
 * @return std::ostream& returns self.m_total_time to the stream buffer
 */
std::ostream &operator<<(std::ostream &stream, const Stopwatch stopwatch) {
  return stream << "CPU time: " << stopwatch.m_total_time << " microseconds";
}