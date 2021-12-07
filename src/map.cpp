#include "../includes/map.h"
#include <random>

// definition of directions LEFT, UP, DOWN and RIGHT as coordinates
const int directions[4][2] {{-1,0}, {0,-1}, {1,0}, {0,1}};

// init static variable
std::mutex Map::_mtx;


/** constructor
*
*/
Map::Map()
{
    initMap();
}

/** destructor
*
*/
Map::~Map()
{
    _mapLocations.clear();
}

/** initialises the map
*
*/
void Map::initMap()
{
    // creating the level
    Level *level = new Level();

    // getting the level segments
    vector<vector<int>> levelSegments = level->GetLevelSegments();

    // initialising the map location vector
    _mapLocations.resize(levelSegments.size());
    _mapLocations.resize(levelSegments[0].size());
    
    // transform the level segment information to map locations and fill map location vector
    for (int i = 0; i < levelSegments.size(); i++)
    {
        for (int j = 0; j < levelSegments[0].size(); j++)
        {
            MapLocation newMapLocation(i, j, levelSegments[i][j] == 1 ? MapLocationType::eWall : MapLocationType::eHallway);
            _mapLocations[i,j].push_back(newMapLocation);
        }
    }
}

/** determines the next valid location by direction
*
* param currentLocation     the current location of game object
* param direction           the direction the game object should be moved to
*/
MapLocation Map::GetNextLocation(MapLocation currentLocation, int direction)
{
    try
    {
        // direction is by default -1, so if direction < 0 then no no player movement needed
        if (direction < 0) return currentLocation;

        // otherwise get the next location related to direction
        MapLocation nextLocation = _mapLocations.at(currentLocation.GetY() + directions[direction][1]).at(currentLocation.GetX() + directions[direction][0]);
        
        // if the desired location is passable then set desir
        if (nextLocation.GetType() == MapLocationType::eHallway)
        {
            return nextLocation; 
        } 
        else
        {
            return currentLocation;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return currentLocation;
    }
}

/** determines a map location by coordinate
*
* param currentLocation     the current location of game object
* param Y                   the y coordinate 
* param X                   the x coordinate 
*/
MapLocation Map::GetNextLocation(MapLocation currentLocation, int Y, int X)
{
    auto desiredLocation = _mapLocations.at(Y).at(X);
    // if desired location is a hallway return the desired location ...
    if (desiredLocation.GetType() == MapLocationType::eHallway)
    {
        return desiredLocation; 
    } 
    else
    {
        // ... otherwise we return the current location (no movement to desired location possible)
        return currentLocation;
    }
}

/** determines all valid map location depending on current location
*
* param currentLocation     the current location of game object
*
*/
std::vector<MapLocation> Map::GetNextValidLocations(MapLocation currentLocation)
{
    // initialize a vector of next valid map locations with size of 0
    std::vector<MapLocation> nextValidLocations(0);  
    
    // always check for all four directions (UP, DOWN, LEFT, RIGHT)
    for (int i=0; i < 4; i++)
    {
        // we have to use y as first index and x as second, because we read the .lvl file in rows(increasing y) and colums(increasing x)
        auto validLocation = _mapLocations.at(currentLocation.GetY() + directions[i][1]).at(currentLocation.GetX() + directions[i][0]);
        
        // only locations of type hallway are valid
        if (validLocation.GetType() == MapLocationType::eHallway)
        {
            nextValidLocations.push_back(validLocation);
        }
    }
    
    return nextValidLocations;
}





