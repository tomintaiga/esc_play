#include "entity_manager.h"

esc::EntityManager::EntityId esc::EntityManager::create()
{
    EntityId entity = _entities.emplace_back(EntityId(_entities.size()));

    return entity;
}