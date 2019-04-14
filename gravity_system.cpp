
#include "gravity_system.h"

const double esc::Systems::Gravity::G = 9.8;

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

void esc::Systems::Gravity::update(std::chrono::seconds dt)
{
    // We need to process all positions
    for(auto it = _position_manager->begin(); it != _position_manager->end(); ++it)    
    {
        // Update only "alive" entities
        if(!_entity_manager->valid(it->first))
            continue;
            
        it->second->y = it->second->y - (G*dt.count()*dt.count())/2;
    }
}