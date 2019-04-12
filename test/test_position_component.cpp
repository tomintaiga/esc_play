#define BOOST_TEST_MODULE position_component
#include <boost/test/included/unit_test.hpp>

#include <position_component.h>

BOOST_AUTO_TEST_CASE(position_component_constructor)
{
    esc::Components::Position position;

    BOOST_TEST(position.x == 0);
    BOOST_TEST(position.y == 0);
    BOOST_TEST(position.z == 0);
}

BOOST_AUTO_TEST_CASE(position_component_manager_costructor)
{
    esc::Components::PositionManager manager;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(position_manager_add_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    p_manager.add(e1);

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(position_manager_check_for_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    p_manager.add(e1);

    BOOST_TEST(p_manager.has(e1));
    BOOST_TEST(!p_manager.has(e2));
}