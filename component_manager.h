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
     * @param entity EntityId to add component
     * @return ComponentsStore::iterator Iterator for new component
     */
    typename ComponentsStore::iterator add(esc::EntityManager::EntityId entity)
    {
        return _components.insert({entity, T()});
    }

private:
    ComponentsStore _components;
};

} // namespace Components
} // namespace esc

#endif // COMPONENT_MANAGER_H