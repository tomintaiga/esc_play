/**
 * @brief Header for esc::Components::ComponentManager class
 * @file component_manager.h
 */

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "entity_manager.h"
#include <map>

namespace esc
{
namespace Components
{

/**
 * @brief Universal component manager
 * 
 * @tparam T Component structure or class type
 */
template <typename T>
class ComponentManager
{
public:
    using ComponentsStore = std::multimap<esc::EntityManager::EntityId, T>;

    /**
     * @brief Add component to entity
     * 
     * @param entity Entity to add component to
     * @return ComponentsStore::iterator Iterator for new component
     */
    typename ComponentsStore::iterator add(esc::EntityManager::EntityId entity)
    {
        return _components.insert({entity, T()});
    }

    /**
     * @brief Add component to entity with arguments
     * 
     * @tparam ARGS Types of arguments
     * @param entity Entity to add component to
     * @param args Arguments for component constructor
     * @return ComponentsStore::iterator Iterator fow new component
     */
    template<typename ...ARGS>
    typename ComponentsStore::iterator add(esc::EntityManager::EntityId entity, ARGS... args)
    {
        return _components.insert({entity, T(args...)});
    }

    /**
     * @brief Check if ComponentManager has components for entity
     * 
     * @param entity Entity to check
     * @return true If ComponentManager has at least one component for entity
     * @return false If ComponentManager don't have any components for that entity
     */
    bool has(esc::EntityManager::EntityId entity) const
    {
        return _components.find(entity) != _components.end();
    }

private:
    ComponentsStore _components;
};

} // namespace Components
} // namespace esc

#endif // COMPONENT_MANAGER_H