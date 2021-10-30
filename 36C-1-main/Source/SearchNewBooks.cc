#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Book.h"
#include "Stopwatch.h"
#include "searchFunctions.h"
int main(int argc, char *argv[]) {
  //Declaring Variables
  Stopwatch ct;
  char search_type;

  //Command line argument check
  //This can be a function
  if (argc < 4 || argc > 5) {
    std::cerr << "Usage: "
              << "./SearchNewBooks <newbooks.dat> <request.dat> <result.dat>"
              << std::endl;
    return 1;
  } else if (std::string(argv[1]) != "newbooks.dat") {
    std::cerr << "Error: cannot open file " << argv[1] << std::endl;
    return 1;
  } else if (std::string(argv[2]) != "request.dat") {
    std::cerr << "Error: cannot open file " << argv[2] << std::endl;
    return 1;
  }
  //This can be a function
  std::string books_file = argv[1];    // arg1 should be books
  std::string request_file = argv[2];  // arg2 should be requests
  std::string result_file = argv[3];
  std::vector<Book> newBooksList = Book::parseList(
      books_file);  // creating book objects and pushing them to the vector
  std::vector<Book> requests = Book::parseList(
      request_file);  // creating book objects and pushing them to the vector

  //This can be a function
  std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
  std::cin >> search_type;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  if (isdigit(search_type) == true) {
    do {
      std::cerr << "Incorrect choice" << std::endl;
      std::cin >> search_type;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    } while (isdigit(search_type) == true);
  }
  if (search_type != 'l' && search_type != 'L' && search_type != 'b' &&
      search_type != 'B') {
    do {
      std::cerr << "Incorrect choice" << std::endl;
      std::cin >> search_type;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    } while (search_type != 'l' && search_type != 'L' && search_type != 'b' &&
             search_type != 'B');
  }

  std::ofstream outfile(result_file);
  //This can be a function
  if (search_type == 'l' || search_type == 'L') {
    int result = ct.linear_stopwatch(newBooksList, requests);
    outfile << result;
    std::cout << ct << std::endl;
    outfile.close();
  }
  if (search_type == 'b' || search_type == 'B') {
    int result = ct.binary_stopwatch(newBooksList, requests);
    outfile << result;
    std::cout << ct << std::endl;
    outfile.close();
  }
  return 0;
}
