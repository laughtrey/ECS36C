#include "Book.h"
/**
 * @brief Construct a new Book:: Book object
 * 
 * @param isbn of the book
 * @param language of the book
 * @param condition mint,new,used etc
 */
Book::Book(const int& isbn, const std::string& language,
           const std::string& condition) {
  m_isbn = isbn;
  m_language = language;
  m_condition = condition;
}
//Getters
int Book::get_isbn() const { return m_isbn; }
std::string Book::get_language() const { return m_language; }
std::string Book::get_condition() const { return m_condition; }
/**
 * @brief overloads the < operator to return higher isbn number
 * 
 * @param b 
 * @return true lhs is less than rhs
 * @return false rhs is less than lhs
 */
bool Book::operator<(const Book& b) const {
  if (get_isbn() == b.get_isbn()) {
    return (get_language() > b.get_language());
  } else {
    return (get_isbn() < b.get_isbn());
  }
}
/**
 * @brief parse a csv file and construct a book object from each line
 * 
 * @param fileName name of the file to open and parse
 * @return std::vector<Book> the constructed unsorted list
 */
std::vector<Book> Book::parseList(std::string fileName) {
  std::vector<Book> v;
  int isbn = 0;
  std::ifstream file(fileName.c_str());
  std::string line;
  while (std::getline(file, line)) {
    splitstring input(line);
    std::vector<std::string> flds = input.split(
        ',');  // Expected: [0] = ISBN, [1] = Language, [2] = Condition
    std::stringstream isbnstring(flds[0]);  // Cast the ISBN string to int
    isbnstring >> isbn;                     // Cast the ISBN string to int
    v.push_back(Book(isbn, flds[1],
                     flds[2]));  // push the new book back into the vector
  }
  return v;
}
