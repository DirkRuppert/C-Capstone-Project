/**
 * Implementation of class WaitingGhosts
 * 
 * WaitingGhosts handles the queue for game objects of type ghost location updates
 * 
 */

#ifndef UPDATEHANDLER_H
#define UPDATEHANDLER_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>
#include "../includes/gameObject.h"

// forward declaration of class Ghost
class Ghost;

class WaitingGhosts
{
  public:
    int getSize();

    void pushBack(std::shared_ptr<Ghost> ghost, std::promise<void> && promise);
    void permitLocationUpdate();
    int  getGhostCount() { return _ghosts.size(); }

  private:
    std::vector<std::shared_ptr<Ghost>> _ghosts;
    std::vector<std::promise<void>> _promises;
    std::mutex _mutex;
};

/**
 * Implementation of class UpdateHandler
 * 
 * UpdateHandler handles the snychronisation and control of game objects
 * 
 */

class UpdateHandler
{
  public:
    UpdateHandler(); // constructor

    void addGhostToQueue(std::shared_ptr<Ghost> ghost);
    int  getWaitingGhostsCount() { return _waitingGhosts.getGhostCount(); }
    void processGhostQueue();

  private:
    
    WaitingGhosts _waitingGhosts;
    
};


#endif
