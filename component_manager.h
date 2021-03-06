/**
 * @brief Header for esc::Components::ComponentManager class
 * @file component_manager.h
 */

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "entity_manager.h"
#include <map>
#include <type_traits>
#include <memory>

namespace esc
{
namespace Components
{

/**
 * @brief Universal component manager
 * 
 * @tparam T Component structure or class type
 * @tparam std::enable_if<! std::is_pointer<T>::value >::type Check that T is not a pointer
 */

template <typename T, class = typename std::enable_if< !std::is_pointer<T>::value >::type >
class ComponentManager
{
public:

    using ComponentsStore = std::multimap<esc::EntityManager::EntityId, std::unique_ptr<T> >;

    /**
     * @brief Add component to entity with arguments
     * 
     * This one is used when T is not a pointer
     * 
     * @tparam ARGS Types of arguments
     * @param entity Entity to add component to
     * @param args Arguments for component constructor
     * @return ComponentsStore::iterator Iterator fow new component
     */
    template<typename ...ARGS>
    typename ComponentsStore::iterator add(esc::EntityManager::EntityId entity, ARGS... args)
    {
        return _components.insert({entity, std::make_unique<T>(args...)});
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

    /**
     * @brief Find all Components in this ComponentManager for entity
     * 
     * @param entity Entity to find components for
     * @return std::pair<ComponentsStore::iterator, ComponentsStore::iterator> Found components
     */
    auto find(esc::EntityManager::EntityId entity)
    {
        return _components.equal_range(entity);
    }

    /**
     * @brief Get begin iterator for internal store
     * 
     * @return ComponentsStore::iterator Begin iterator for internal store
     */
    inline typename ComponentsStore::iterator begin() { return _components.begin(); }

    /**
     * @brief Get end iterator for internal store
     * 
     * @return ComponentsStore::iterator End iterator for internal store
     */
    inline typename ComponentsStore::iterator end() { return _components.end(); }

private:
    ComponentsStore _components;
};


} // namespace Components
} // namespace esc

#endif // COMPONENT_MANAGER_H