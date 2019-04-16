/**
 * @brief Header for esc::Systems::AbstractSystem class
 * @file abstract_system.h
 */

#ifndef ABSTRACT_SYSTEM_H
#define ABSTRACT_SYSTEM_H

#include <chrono>

namespace esc
{
namespace Systems
{

/**
 * @brief Abstract System class
 */
class AbstractSystem
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~AbstractSystem() {}

    /**
     * @brief Initialize system class
     * 
     * @return true If system is ready to work
     * @return false Is system is not ready to work
     */
    virtual bool init() = 0;

    /**
     * @brief Update entyties positions and forces
     * 
     * @param dt Time interval
     */
    virtual void update(std::chrono::milliseconds dt) = 0;
};

} //namespace Systems
} // namespace esc

#endif // ABSTRACT_SYSTEM_H