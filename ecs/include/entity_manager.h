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

  /**
   * @brief Check if entity is valid
   * 
   * @param entity Entity to check
   * @return true If entity is valid
   * @return false If entity is invalid
   */
  bool valid(const EntityId& entity) const noexcept;

  /**
   * @brief Destroy entity
   * 
   * @param entity Entity to destroy
   * 
   * After this function entity is not valid any more
   */
  void destroy(const EntityId& entity);

private:

  /**
   * @brief Vector of alive entities
   */
  std::vector<EntityId> _entities;
};

} // namespace esc

#endif // ENTITY_MANAGER_H