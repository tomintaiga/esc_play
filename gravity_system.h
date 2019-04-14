/**
 * @brief Header for esc::Systems::Gravity class
 * @file gravity_system.h
 */

#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H

#include "position_component.h"
#include "force_component.h"

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
    inline void set(esc::Components::PositionManager *p_manager) { _position_manager = p_manager; }

    /**
     * @brief Set Force manager
     * 
     * @param f_manager Pointer to ForceManager class
     */
    inline void set(esc::Components::ForceManager *f_manager) { _force_maneger = f_manager; }

private:
    esc::Components::PositionManager *_position_manager;
    esc::Components::ForceManager *_force_maneger;
};

} //namespace Systems
} // namespace esc

#endif // GRAVITY_SYSTEM_H