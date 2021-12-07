#include <thread>
#include <future>
#include <random>
#include <iostream>
#include "../includes/ghost.h"

const int directions[4][2] {{-1,0}, {0,-1}, {1,0}, {0,1}};

/** Constructor of class Ghost
*
* creates instance of game object of type ghost
*
* param ghostID         id of ghost
* param posX            start position x coordinate 
* param posY            start position y coordinate 
* param map             pointer to map
* param updateHandler   pointer to UpdateHandler
*/
Ghost::Ghost(int ghostID, int posX, int posY, std::shared_ptr<Map> map, std::shared_ptr<UpdateHandler> updateHandler)
{
    _ghostID = std::make_shared<int>( ghostID);
    type = ObjectType::objGhost;

    _currentLocation.SetX(posX);
    _currentLocation.SetY(posY);
    _newLocation.SetX(posX);
    _newLocation.SetY(posY);

    _map = map;
    _updateHandler = updateHandler;

    SetColours(0xFF, 0x00, 0x00, 0x00);
}

/** starts a thread for a ghost
*
*   ghost starts haunting the map randomly
*/
void Ghost::BringToLife()
{
    threads.emplace_back(std::thread(&Ghost::Haunt, this));
}

/** determines  the movement of a ghost in the map
*
*/
void Ghost::Haunt()
{ 
    // dead ghost do not haunt any longer, otherwise IsAlive is a bad variable naming for ghosts, which are literally never alive :-)
    while (IsAlive() == true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // before updating the new location, we have to store the coordinates into the current location
        _currentLocation.SetX(_newLocation.GetX());
        _currentLocation.SetY(_newLocation.GetY());

        // clear the vector
        _nextValidLocations.clear();
        
        // getting a vector containing the next possible/valid locations, reachable from the current location
        _nextValidLocations = _map->GetNextValidLocations(_currentLocation);

        // if only one valid next location is possible, probably dead end hallway, turn arround is mandatory
        if (_nextValidLocations.size() == 1) 
        {
            _newLocation = _nextValidLocations.at(0);
            // setting the new direction
            _preferredLocationIndex = DetermineDirection(_newLocation, _currentLocation);
        }    
        else // if we have more than one possible valid positions to move to, we select a random direction
        {
            // we dont want to haut the ghost backwards/turn arround, except dead ends, but this case is covered beforehand, so we eliminate the prior location from the possible locations
            // but only if the preferred location has been set, e.g. at start up it is unknown = -1 and then we want full random direction behavior
            if (_preferredLocationIndex > -1)
            {
                // getting the reversed preferred direction
                int reversedDirection = ReverseDirection(_preferredLocationIndex);
                // getting the prior location where ghost comes from
                auto priorLocation = _map->GetNextLocation(_currentLocation, _currentLocation.GetY() + directions[reversedDirection][1], _currentLocation.GetX() + directions[reversedDirection][0]);
                // removing the prior location to avoid ghost from haunting backwards / turning back
                RemoveLocation(priorLocation);
            }

            // if only one valid possible location is left after removing the prior position, probably turn in corner
            if (_nextValidLocations.size() == 1) 
            {
                _newLocation = _nextValidLocations.at(0);
                // setting the new direction
                _preferredLocationIndex = DetermineDirection(_newLocation, _currentLocation);
            }    
            else // after removing previous position and more than 1 possible next valid locations: most likely hallway crossing 
            {
                std::random_device rnd;
                std::mt19937 eng(rnd());
                // zero based vector of map location, so size - 1, covers all posible vector sizes, because size == 1 is handled in the if branch
                std::uniform_int_distribution<> distribution(0, _nextValidLocations.size()- 1);

                // setting new location
                _newLocation = _nextValidLocations.at(distribution(eng));

                _preferredLocationIndex = DetermineDirection(_newLocation, _currentLocation);
            }
        }

        // adding ghost to queue for position update...
        auto locationUpdatePermitted = std::async(&UpdateHandler::addGhostToQueue, _updateHandler, get_shared_this());

        // ... and wait for the permission
        locationUpdatePermitted.get();
    }
}

/** calculates the direction to move with new location and old location
*
*/
int Ghost::DetermineDirection(MapLocation &newLocation, MapLocation &oldLocation)
{
    int direction = -1;

    // getting the delta between positions
    int deltaX = newLocation.GetX() - oldLocation.GetX();
    int deltaY = newLocation.GetY() - oldLocation.GetY();

    // if deltas fit a direction return direction 
    for (int i = 0; i < 4; i++)
    {
        if (directions[i][0] == deltaX)
        {
            if (directions[i][1] == deltaY)
            {
                direction = i;
                break;
            }
            else continue;
        }
        else continue;
    }
    
    return direction;
}

/** determines the opposite /reversed direction
 * 
 * param directionIdx   the index of the current direction stored in the directions array
 * 
*/
int Ghost::ReverseDirection(int directionIdx)
{
    int reverseDirection = -1;

    try
    {
        // revert the direction determined by directionIdx
        int revX = directions[directionIdx][0] * (-1);
        int revY = directions[directionIdx][1] * (-1);

        for (int i = 0; i < 4; i++) // always four directions
        {
            if (directions[i][0] == revX)
            {
                if (directions[i][1] == revY)
                {
                    reverseDirection = i;
                    break;
                }
                else continue;
            }
            else continue;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        reverseDirection = -1;
    }
    
    return reverseDirection;
}

/** removes a map location from the next valid location vector
 * 
 * param locationToRemove   the location which should be removed from the vector
 * 
*/
void Ghost::RemoveLocation(MapLocation locationToRemove)
{
    int locIndex = -1;

    // find location to remove 
    for(int i = 0; i < _nextValidLocations.size(); i++)
    {
        if((_nextValidLocations[i].GetX() == locationToRemove.GetX()) && (_nextValidLocations[i].GetY() == locationToRemove.GetY()))
        {
            locIndex = i;
            break;
        }
    }
    if ((locIndex > -1) && (locIndex < _nextValidLocations.size()))
    {
        // remove the location
        _nextValidLocations.erase(_nextValidLocations.begin() + locIndex);
    }
}