/**
 * @brief Header for esc::Components::Position class
 * @file position_component.h
 */

#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "entity_manager.h"
#include <map>

namespace esc
{
namespace Components
{

/**
 * @brief Entity position structure
 */
struct Position
{
    int x;
    int y;
    int z;

    Position() : x{}, y{}, z{} {}
};

/**
 * @brief Manager for Position components
 */
class PositionManager
{
public:
    /**
     * @brief Add component for entity
     * 
     * @param entity Entity to add
     */
    void add(esc::EntityManager::EntityId entity);

    /**
     * @brief Check if manager has entity
     * 
     * @param entity Entity to check
     * @return true If manager has such entity
     * @return false If manager don't have such entity
     */
    bool has(esc::EntityManager::EntityId entity) const;

private:
    std::map<esc::EntityManager::EntityId, Position> _components;
};

} // namespace Components
} // namespace esc

#endif // POSITION_COMPONENT_H