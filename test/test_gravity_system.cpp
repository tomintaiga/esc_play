#define BOOST_TEST_MODULE gravity_system
#include <boost/test/included/unit_test.hpp>

#include <gravity_system.h>

BOOST_AUTO_TEST_CASE(gravity_system_constructor)
{
    esc::Systems::Gravity system;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(gravity_system_set_position_manager)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;

    system.set(&p_manager);

    BOOST_TEST(true);
}