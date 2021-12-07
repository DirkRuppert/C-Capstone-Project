#include <algorithm>
#include "../includes/gameObject.h"

/** constructor
*/
GameObject::GameObject()
{
    type = ObjectType::noObject;
}

/* destructor 
*/
GameObject::~GameObject()
{
    // creating thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t)
    {
        t.join();
    });
}


void GameObject::Update() 
{
    return;
}

void GameObject::BringToLife()
{
    return;
}

/** setting the color of game object
*/
void GameObject::SetColours(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    _rColour = r;
    _gColour = g;
    _bColour = b;
    _aColour = a;
}


