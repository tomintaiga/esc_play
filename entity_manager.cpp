#include "entity_manager.h"

esc::EntityManager::EntityId esc::EntityManager::create()
{
    EntityId entity = _entities.emplace_back(EntityId(_entities.size()));

    return entity;
}

bool esc::EntityManager::valid(const esc::EntityManager::EntityId& entity) const noexcept
{
    return entity < _entities.size() && _entities[entity] == entity;
}

void esc::EntityManager::destroy(const esc::EntityManager::EntityId& entity)
{
    if(entity < _entities.size())
        _entities[entity] = entity+1;
}