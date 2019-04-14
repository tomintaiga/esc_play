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

BOOST_AUTO_TEST_CASE(gravity_system_set_force_manager)
{
    esc::Systems::Gravity system;
    esc::Components::ForceManager f_manager;

    system.set(&f_manager);

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(gravity_system_set_entity_manager)
{
    esc::Systems::Gravity system;
    esc::EntityManager e_manager;

    system.set(&e_manager);

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(gravity_system_init)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::Components::ForceManager f_manager;
    esc::EntityManager e_manager;

    system.set(&p_manager);
    system.set(&f_manager);
    system.set(&e_manager);

    BOOST_TEST(system.init());
}

BOOST_AUTO_TEST_CASE(gravity_system_init_should_fail_if_no_position_manager)
{
    esc::Systems::Gravity system;
    esc::Components::ForceManager f_manager;
    esc::EntityManager e_manager;

    system.set(&f_manager);
    system.set(&e_manager);

    BOOST_TEST(!system.init());
}

BOOST_AUTO_TEST_CASE(gravity_system_init_should_fail_if_no_force_manager)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    system.set(&p_manager);
    system.set(&e_manager);

    BOOST_TEST(!system.init());
}

BOOST_AUTO_TEST_CASE(gravity_system_init_should_fail_if_no_entity_manager)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::Components::ForceManager f_manager;

    system.set(&p_manager);
    system.set(&f_manager);

    BOOST_TEST(!system.init());
}

BOOST_AUTO_TEST_CASE(gravity_system_update)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::Components::ForceManager f_manager;
    esc::EntityManager e_manager;

    system.set(&p_manager);
    system.set(&f_manager);
    system.set(&e_manager);

    system.init();

    auto entity = e_manager.create();
    auto position = p_manager.add(entity);

    //Let's set position
    position->second->y = 100;


    //Now let's update gravity for 1 second
    system.update(std::chrono::seconds(1));

    //Now check result
    BOOST_TEST(position->second->y == 95.1);
}