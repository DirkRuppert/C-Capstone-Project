/**
 * Implementation of class Ghost
 * 
 * ghost is a game object that is randomly moved through the map / level
 * 
 */

#ifndef GHOST_H
#define GHOST_H

#include <vector>
#include <thread>
#include "../includes/gameObject.h"
#include "../includes/updateHandler.h"

class Ghost : public GameObject, public std::enable_shared_from_this<Ghost>
{
    public:
    Ghost(int ghostID, int startPosX, int startPosY, std::shared_ptr<Map> map, std::shared_ptr<UpdateHandler> updateHandler);

    void BringToLife();
    void Haunt();
    bool IsAlive() { return _isAlive; }

    std::shared_ptr<Ghost> get_shared_this() { return shared_from_this(); }

    protected:

    private:

    int DetermineDirection(MapLocation &newLocation, MapLocation &oldLocation);
    int ReverseDirection(int directionIdx);
    void RemoveLocation(MapLocation locationToRemove);

    std::shared_ptr<int> _ghostID;
    std::shared_ptr<UpdateHandler> _updateHandler;

    std::vector<MapLocation> _nextValidLocations;
    int _preferredLocationIndex { -1 };
    bool _isAlive { true };
};
#endif 