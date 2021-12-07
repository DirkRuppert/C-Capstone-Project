/**
 * Implementation of class GameObject
 * 
 * GameObject is the base class for all game objects used
 * 
 */ 
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <thread>

#include "map.h"
#include "mapLocation.h"

enum ObjectType
{
    noObject,
    objGhost,
    objPlayer,
};


class GameObject
{
    public:
    //constructor / destructor
    GameObject();
    ~GameObject();

    //getter and setter
    MapLocation GetCurrentLocation() { return _currentLocation; }
    MapLocation GetNewLocation() { return _newLocation; }
    ObjectType GetType() { return type; }

    // getter and setter for colour information
    unsigned int getRColour() { return _rColour; }
    unsigned int getGColour() { return _gColour; }
    unsigned int getBColour() { return _bColour; }
    unsigned int getAColour() { return _aColour; }

    void setRColour(unsigned int rColour) { _rColour = rColour; }
    void setGColour(unsigned int gColour) { _gColour = gColour; }
    void setBColour(unsigned int bColour) { _bColour = bColour; }
    void setAColour(unsigned int aColour) { _aColour = aColour; }

    virtual void BringToLife();
    virtual void Update();

    protected:
    
    void SetColours(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

    ObjectType type;
    std::vector<std::thread> threads;
    std::shared_ptr<Map> _map;
    MapLocation _currentLocation;
    MapLocation _newLocation;
    static std::mutex _mtx;
    int _id;

    private:
    static int _objID;

    unsigned int _rColour;
    unsigned int _gColour;
    unsigned int _bColour;
    unsigned int _aColour;
    
};

#endif