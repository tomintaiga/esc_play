#define BOOST_TEST_MODULE entity_manager
#include <boost/test/included/unit_test.hpp>

#include <entity_manager.h>

BOOST_AUTO_TEST_CASE(manager_constructor)
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

BOOST_AUTO_TEST_CASE(valid_entity)
{
    esc::EntityManager manager;

    auto entity = manager.create();

    BOOST_TEST(manager.valid(entity));
}

BOOST_AUTO_TEST_CASE(valid_entity_not_created)
{
    esc::EntityManager manager;

    esc::EntityManager::EntityId entity{};

    BOOST_TEST(!manager.valid(entity));
}

BOOST_AUTO_TEST_CASE(destroy_entity)
{
    esc::EntityManager manager;

    auto entity = manager.create();
    manager.destroy(entity);

    BOOST_TEST(!manager.valid(entity));
}