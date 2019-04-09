/**
 * @brief Header for esc::EntityManager class
 * @file entity_manager.h
 */

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstdint>
#include <vector>

namespace esc
{

/**
 * @brief Manager for entity manipulations
 */
class EntityManager
{
public:
  /**
   * @brief Type for Entity ID
   */
  using EntityId = std::uint64_t;

  /**
   * @brief Create new Entity
   * 
   * @return ID of new entity
   */
  EntityId create();

private:

  /**
   * @brief Vector of alive entities
   */
  std::vector<EntityId> _entities;
};

} // namespace esc

#endif // ENTITY_MANAGER_H