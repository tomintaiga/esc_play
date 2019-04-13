#include "position_component.h"

esc::Components::PositionManager::ComponentsStore::iterator esc::Components::PositionManager::add(esc::EntityManager::EntityId entity)
{
    return _components.insert({entity, new Position()});
}

bool esc::Components::PositionManager::has(esc::EntityManager::EntityId entity) const
{
    return _components.find(entity) != _components.end();
}
