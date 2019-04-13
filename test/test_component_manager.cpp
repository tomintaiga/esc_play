#define BOOST_TEST_MODULE component_manager
#include <boost/test/included/unit_test.hpp>

#include <component_manager.h>

struct TestPosition
{
    int x;
    int y;
    int z;
};

BOOST_AUTO_TEST_CASE(component_manager_constructor)
{
    esc::Components::ComponentManager<TestPosition> manager;

    BOOST_TEST(true);
}