/**
 * @brief Header for esc::Components::Position class
 * @file position_component.h
 */

#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "component_manager.h"

namespace esc
{
namespace Components
{

/**
 * @brief Entity position structure
 */
struct Position
{
    float x;
    float y;
    float z;

    Position() : x{}, y{}, z{} {}
};

/**
 * @brief Manager for Position components
 */
typedef ComponentManager<Position> PositionManager;

} // namespace Components
} // namespace esc

#endif // POSITION_COMPONENT_H