#include "../includes/player.h"
#include <cmath>
#include <iostream>
#include <SDL_image.h>

/** constructor */
Player::Player(int playerID, int posX, int posY, std::shared_ptr<Map> map)
{
    _id = playerID;
    type = ObjectType::objPlayer;

    _currentLocation.SetX(posX);
    _currentLocation.SetY(posY);
    _newLocation.SetX(posX);
    _newLocation.SetY(posY);

    _map = map;

    // set the player colour to green
    SetColours(0x00, 0xFF, 0x00, 0x00);

}

/** sets the player direction
*
* param direction     the direction the player should be moved to
*
*/
void Player::SetDirection(int direction)
{
  _direction = direction;
}

/** updates the player avatar
*
*/
void Player::Update() 
{
  _currentLocation = _newLocation;

  // determine the new player location depending on current location and direction
  _newLocation = _map->GetNextLocation(_currentLocation, _direction);
}
