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

BOOST_AUTO_TEST_CASE(gravity_system_free_fall)
{
    /*
     * Here we test that entyty can fall without start speed
     * with start position
     */
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
    position->second->z = 100;


    //Now let's update gravity for 1 second
    system.update(std::chrono::milliseconds(1000));

    //Now check result
    BOOST_TEST(position->second->z == 95.1, boost::test_tools::tolerance(0.001));
}

BOOST_AUTO_TEST_CASE(gravity_system_free_fall_for_alive_only)
{
    /*
     * Here we check that only "alive" entities are foling
     */

    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::Components::ForceManager f_manager;
    esc::EntityManager e_manager;

    system.set(&p_manager);
    system.set(&f_manager);
    system.set(&e_manager);

    system.init();

    auto e1 = e_manager.create();
    auto p1 = p_manager.add(e1);

    auto e2 = e_manager.create();
    auto p2 = p_manager.add(e2);

    p1->second->z = 100;
    p2->second->z = 100;

    e_manager.destroy(e2);

    system.update(std::chrono::milliseconds(1000));
    BOOST_TEST(p1->second->z == 95.1, boost::test_tools::tolerance(0.001));
    BOOST_TEST(p2->second->z == 100, boost::test_tools::tolerance(0.001));
}

BOOST_AUTO_TEST_CASE(gravity_system_add_force)
{
    esc::Systems::Gravity system;
    esc::Components::PositionManager p_manager;
    esc::Components::ForceManager f_manager;
    esc::EntityManager e_manager;

    system.set(&p_manager);
    system.set(&f_manager);
    system.set(&e_manager);

    system.init();

    auto e1 = e_manager.create();
    auto p1 = p_manager.add(e1);

    p1->second->y = 100;

    system.update(std::chrono::milliseconds(1000));

    BOOST_TEST(f_manager.has(e1));

    // auto forces = f_manager.find(e1);

    // BOOST_TEST(std::distance(forces.first, forces.second) == 1);

    // BOOST_TEST(forces.first->second->radius == 9.8, boost::test_tools::tolerance(0.001));
    // BOOST_TEST(forces.first->second->angle == 270, boost::test_tools::tolerance(0.001));

}