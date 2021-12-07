
/**
 * Implementation of class Level
 * 
 * Level reads the level information from a .lvl file and parses this into level segments
 * 
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../includes/mapLocation.h"


using std::vector;
using std::string;

const string LEVEL_FILE{"../assets/1.lvl"};

class Level
{
 public:
  Level();
  ~Level();

  vector<vector<int>> GetLevelSegments() const;

 private:
  vector<int> ParseLine(string line);
  vector<vector<int>> _levelSegments;

  void readLevelFile(std::string levelFile); 

};

#endif