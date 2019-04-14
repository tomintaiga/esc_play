/**
 * @brief Header for esc::Components::Force class
 * @file force_component.h
 */
#ifndef FORCE_COMPONENT_H
#define FORCE_COMPONENT_H

#include "component_manager.h"

namespace esc
{
namespace Components
{

/**
 * @brief Force component
 */
struct Force
{
    float angle;         ///< Angle of force vector
    unsigned int radius; ///< Size of force vector
};

/**
 * @brief Manager for Force components
 */
typedef ComponentManager<Force> ForceManager;

} // namespace Components
} // namespace esc

#endif // FORCE_COMPONENT_H