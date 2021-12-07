/**
 * Implementation of class MapLocation
 * 
 * MapLocation defines one specific segment in a map 
 * 
 */

#ifndef MAPLOCATION_H
#define MAPLOCATION_H

enum class MapLocationType {eHallway, eWall};

class MapLocation
{
    public:
    MapLocation() {}
    MapLocation(int xCoord, int yCoord, MapLocationType mapLocationType) 
        : _xCoord(xCoord), _yCoord(yCoord), _mapLocationType(mapLocationType) 
    {
        // every hallway starts with score = 1
        _score = (mapLocationType == MapLocationType::eHallway ? 1 : 0);
    }
    int GetX() { return _xCoord; }
    int GetY() { return _yCoord; }

    void SetX(int x) { _xCoord = x; }
    void SetY(int y) { _yCoord = y; }

    int GetScore() { return _score; }
    MapLocationType GetType() { return _mapLocationType; }

    protected:
    
    private:
    int _xCoord;
    int _yCoord;
    int _score;
    MapLocationType _mapLocationType;
};

#endif