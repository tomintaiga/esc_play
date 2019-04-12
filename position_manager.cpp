#include "position_component.h"

void esc::Components::PositionManager::add(esc::EntityManager::EntityId entity)
{
    _components.emplace(entity, Position());
}

bool esc::Components::PositionManager::has(esc::EntityManager::EntityId entity) const
{
    return _components.find(entity) != _components.end();
}