#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include <vector>
#include "priorityqueue.h"

class TeamData {
 public:
 	TeamData(std::string filename);
 	int numPlayers() const;
 	double winPercentages(int i, int j) const { return winPercentages_[i][j]; }

 private:
	// TODO: decide the type of this variable.
	std::vector<std::vector<int>> winPercentages_;

	int numPlayers_;

};  // class TeamData

#endif  // _TEAMDATA_H_