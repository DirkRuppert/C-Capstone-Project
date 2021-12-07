/**
 * Implementation of class Map
 * 
 * Map transfers the level information into map locations and provides the determination of map locations
 * 
 */

#ifndef MAP_H
#define MAP_H

#include <mutex>
#include "level.h"
#include "mapLocation.h"

class Map
{
    public:
    Map();
    ~Map();
    vector<vector<MapLocation>> GetMapLocations() const
    { 
        return _mapLocations;
    }

    std::vector<MapLocation> GetNextValidLocations(MapLocation currentLocation);
    MapLocation GetNextLocation(MapLocation currentLocation, int direction);
    MapLocation GetNextLocation(MapLocation currentLocation, int Y, int X);


    protected:

    private:
    void initMap();
    void buildMapFromLevel();

    std::vector<std::vector<MapLocation>> _mapLocations;

    static std::mutex _mtx;
};



#endif