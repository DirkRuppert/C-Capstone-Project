#include "../includes/level.h"

/** constructor
*
*/
Level::Level()
{
    readLevelFile(LEVEL_FILE);
}

/** destructor
*
*/
Level::~Level() 
{
    // clear vector and all elements stored in the vector
    _levelSegments.clear();
}

/** reads the level information from a .lvl file
*
* param levelFilePath   the path and file to read the level information from
*
*/
void Level::readLevelFile(std::string levelFilePath)
{
    try
    {
        // creating input file stream
        std::ifstream levelFile(levelFilePath);
        _levelSegments.clear();

        // if level file stream is created read line and parse line to vector
        if (levelFile)
        {
            string line;
            while (getline(levelFile, line))
            {
                vector<int> row = ParseLine(line);
                _levelSegments.push_back(row);
            }
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/** parses the level information from a string line
*
* param line   the line as string read from the .lvl file
*
*/
vector<int> Level::ParseLine(string line)
{
    int n;
    char c;
    vector<int> row;

    try
    {
        std::istringstream sline(line);

        while(sline >> n >> c && c == ',')
        {
            row.push_back(n);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return row;    
}

/** returns the 2-dimensional vector of level segments
*
*/
vector<vector<int>> Level::GetLevelSegments() const
{
    return _levelSegments;
}

