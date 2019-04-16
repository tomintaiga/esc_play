
#include "gravity_system.h"

const double esc::Systems::Gravity::G = 9.8;

esc::Systems::Gravity::Gravity(): AbstractSystem(), _position_manager{}, _force_maneger{}, _entity_manager{}
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

void esc::Systems::Gravity::update(std::chrono::milliseconds dt)
{
    auto seconds = dt.count() / 1000;
    auto time = seconds*seconds;
    // We need to process all positions
    for(auto it = _position_manager->begin(); it != _position_manager->end(); ++it)    
    {
        // Update only "alive" entities
        if(!_entity_manager->valid(it->first))
            continue;

        // Check if entity has forces
        if(!_force_maneger->has(it->first))
            _force_maneger->add(it->first, 0, 0, -G);
        
        // Add all forces to current position
        auto forces = _force_maneger->find(it->first);
        for(auto fit = forces.first; fit != forces.second; ++fit)
        {
            it->second->x += (fit->second->x * time)/2;
            it->second->y += (fit->second->y * time)/2;
            it->second->z += (fit->second->z * time)/2;
        }
    }
}