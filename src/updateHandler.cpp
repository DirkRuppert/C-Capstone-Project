#include <future>
#include "../includes/ghost.h"
#include "../includes/updateHandler.h"

/** returns the size = number of ghosts in the waiting queue
*
*/
int WaitingGhosts::getSize()
{
    std::lock_guard<std::mutex> lock(_mutex);
    return _ghosts.size();
}

/** adds a ghost and the related update allowance promise to  the waiting queue (the vectors)
*
*/
void WaitingGhosts::pushBack(std::shared_ptr<Ghost> ghost, std::promise<void> && promise)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _ghosts.push_back(ghost);
    _promises.push_back(std::move(promise));
}

/** sets the update promise value for all waiting ghosts in the queue
*
*/
void WaitingGhosts::permitLocationUpdate()
{
    std::lock_guard<std::mutex> lock(_mutex);

    int ghostCounter = _ghosts.size();
    
    for (int i = 0; i < _promises.size(); i++)
    {
        // fullfill promise and send signal back to ghost that update has been granted
        _promises.at(i).set_value();
    }
    
   _ghosts.clear();
   _promises.clear();
}

UpdateHandler::UpdateHandler()
{
    ; // empty constructor
}

/** delegates the update handler adding function to the waiting ghost queue / vectors
*
*/
void UpdateHandler::addGhostToQueue(std::shared_ptr<Ghost> ghost)
{
  std::promise<void> promiseGrantGhostUpdate;
  std::future<void> futureGrantGhostUpdate = promiseGrantGhostUpdate.get_future();

  _waitingGhosts.pushBack(ghost, std::move(promiseGrantGhostUpdate));
  
  futureGrantGhostUpdate.wait();
}

/* 
*  wrapper for the update permission function of waiting ghosts
*/
void UpdateHandler::processGhostQueue()
{
    _waitingGhosts.permitLocationUpdate();
}

