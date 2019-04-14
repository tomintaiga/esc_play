
#include "gravity_system.h"

esc::Systems::Gravity::Gravity(): _position_manager{}, _force_maneger{}, _entity_manager{}
{

}

bool esc::Systems::Gravity::init()
{
    if(_position_manager == nullptr)
        return false;

    if(_force_maneger == nullptr)
        return false;

    if(_entity_manager == nullptr)
        return false;

    return true;
}