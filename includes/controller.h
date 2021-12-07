#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * Implementation of class Controller
 * 
 * Controller handles user input by arrow keys and translate the key information to direction
 * 
 */ 
class Controller 
{
 public:
    int HandleInput(bool &running) const;
    int GetCurrentDirection() { return _direction; }

 private:
    int _direction;
};

#endif