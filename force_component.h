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
    float x; /// X Vector component
    float y; /// Y Vector component
    float z; /// Z Vector component

    Force(): x{}, y{}, z{} {}
    Force(float X, float Y, float Z): x{X}, y{Y}, z{Z}{}
};

/**
 * @brief Manager for Force components
 */
typedef ComponentManager<Force> ForceManager;

} // namespace Components
} // namespace esc

#endif // FORCE_COMPONENT_H