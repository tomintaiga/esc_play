#include "entity_manager.h"

esc::EntityManager::EntityId esc::EntityManager::create()
{
    EntityId entity = _entities.emplace_back(EntityId(_entities.size()));

    return entity;
}

bool esc::EntityManager::valid(const esc::EntityManager::EntityId& entiry) const noexcept
{
    return true;
}