#define BOOST_TEST_MODULE component_manager
#include <boost/test/included/unit_test.hpp>

#include <component_manager.h>

struct TestPosition
{
    int x;
    int y;
    int z;

    TestPosition(): x{}, y{}, z{} {}
};

BOOST_AUTO_TEST_CASE(component_manager_constructor)
{
    esc::Components::ComponentManager<TestPosition> manager;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(component_manager_add_entity)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    auto component = c_manager.add(e1);

    BOOST_TEST((*component).second.x == 0);
    BOOST_TEST((*component).second.y == 0);
    BOOST_TEST((*component).second.z == 0);
}

struct TestPositionArgs
{
    int x;
    int y;
    int z;
    TestPositionArgs() = delete;
    TestPositionArgs(int X, int Y, int Z): x{X}, y{Y}, z{Z} {}
};

BOOST_AUTO_TEST_CASE(component_manager_add_entity_with_args)
{
    esc::Components::ComponentManager<TestPositionArgs> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    auto component = c_manager.add(e1, 10, 20, 30);

    BOOST_TEST((*component).second.x == 10);
    BOOST_TEST((*component).second.y == 20);
    BOOST_TEST((*component).second.z == 30);
}

BOOST_AUTO_TEST_CASE(component_manager_find)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    auto component = c_manager.add(e1);

    BOOST_TEST(c_manager.has(e1));
    BOOST_TEST(!c_manager.has(e2));
}