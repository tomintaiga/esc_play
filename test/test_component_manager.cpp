#define BOOST_TEST_MODULE component_manager
#include <boost/test/included/unit_test.hpp>

#include <component_manager.h>
#include <entity_manager.h>

BOOST_AUTO_TEST_CASE(componentManager_constructor)
{
    esc::ComponentManager manager;

    BOOST_TEST(true);
}

struct Position
{
    int x;
    int y;
};

BOOST_AUTO_TEST_CASE(component)
{

    esc::ComponentManager components;
    esc::EntityManager entities;

    esc::EntityManager::EntityId entity = entities.create();

    components.add<Position>(entity, 10, 15);

    BOOST_TEST(true);
}