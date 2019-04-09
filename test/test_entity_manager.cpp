#define BOOST_TEST_MODULE entity_manager
#include <boost/test/included/unit_test.hpp>

#include <entity_manager.h>

BOOST_AUTO_TEST_CASE(constructor)
{
    esc::EntityManager manager;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(entity_type)
{
    esc::EntityManager::EntityId id;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(create_entity)
{
    esc::EntityManager manager;

    auto entity = manager.create();

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(create_multi_entity)
{
    esc::EntityManager manager;

    auto e1 = manager.create();
    auto e2 = manager.create();

    BOOST_TEST(e1 != e2);
}

BOOST_AUTO_TEST_CASE(valid)
{
    esc::EntityManager manager;

    auto entity = manager.create();

    BOOST_TEST(manager.valid(entity));
}