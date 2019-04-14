/**
 * @brief Header for esc::Systems::Gravity class
 * @file gravity_system.h
 */

#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H

#include "position_component.h"

namespace esc
{
namespace Systems
{

/**
 * @brief System for gravity simulation
 */
class Gravity
{
public:
    /**
     * @brief Set Position manager
     * 
     * @param p_manager Pointer to PositionManager class
     */
    inline void set(esc::Components::PositionManager *p_manager) { _p_manager = p_manager; }

private:
    esc::Components::PositionManager *_p_manager;
};

} //namespace Systems
} // namespace esc

#endif // GRAVITY_SYSTEM_H