#include "splitstring.h"

#include <string>
#include <vector>
// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
std::vector<std::string>& splitstring::split(char delim, int rep) {
  if (!flds.empty()) flds.clear();  // empty vector if necessary
  std::string work = data();
  std::string buf = "";
  unsigned int i = 0;
  while (i < work.length()) {
    if (work[i] != delim)
      buf += work[i];
    else if (rep == 1) {
      flds.push_back(buf);
      buf = "";
    } else if (buf.length() > 0) {
      flds.push_back(buf);
      buf = "";
    }
    i++;
  }
  if (!buf.empty()) flds.push_back(buf);
  return flds;
}
