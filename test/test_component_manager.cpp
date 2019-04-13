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