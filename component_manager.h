/**
 * @brief Header for esc::ComponentManager class
 * @file component_manager.h
 */

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "entity_manager.h"
#include <map>
#include <utility>

namespace esc
{

/**
 * @brief Manager for ESC components
 */
class ComponentManager
{

  public:
    /**
     * @brief AddComponent to entity
     * 
     * @tparam T Type of component
     * @tparam Args Component arguments types
     * @param entity Entity to add component to
     * @param args Values for component arguments
     */
    template <typename T, typename... Args>
    void add(const esc::EntityManager::EntityId entity, Args &&... args)
    {
        T* component = new T({std::forward<Args>(args)...});
        _components.insert(std::make_pair(entity, static_cast<void*>(component)));
    }

  private:
    /**
     * @brief Store entities and components
     * 
     * Key is entity
     * Value is pointer to component
     */
    std::multimap<esc::EntityManager::EntityId, void *> _components;
};

} // namespace esc

#endif // COMPONENT_MANAGER_H