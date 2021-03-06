/**
 * @brief Header for esc::Systems::Gravity class
 * @file gravity_system.h
 */

#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H

#include "abstract_system.h"
#include "position_component.h"
#include "force_component.h"

namespace esc
{
namespace Systems
{

/**
 * @brief System for gravity simulation
 */
class Gravity: public AbstractSystem
{
public:

    /**
     * @brief Default constructor
     */
    Gravity();

    virtual ~Gravity(){};

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

    /**
     * @brief Set Entity manager
     * 
     * @param e_manager Pointer to EntityManager class
     */
    inline void set(esc::EntityManager *e_manager) { _entity_manager = e_manager; }

    /**
     * @brief Initialize system class
     * 
     * @return true If system is ready to work
     * @return false Is system is not ready to work
     */
    virtual bool init() override;

    /**
     * @brief Update entyties positions and forces
     * 
     * @param dt Time interval
     */
    virtual void update(std::chrono::milliseconds dt) override;

    /**
     * @brief Acceleration of gravity
     * @see https://en.wikipedia.org/wiki/Standard_gravity
     */
    static const double G;

private:
    esc::Components::PositionManager *_position_manager;
    esc::Components::ForceManager *_force_maneger;
    esc::EntityManager *_entity_manager;
};

} //namespace Systems
} // namespace esc

#endif // GRAVITY_SYSTEM_H