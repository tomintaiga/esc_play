#define BOOST_TEST_MODULE entity_manager
#include <boost/test/included/unit_test.hpp>

#include <entity_manager.h>

BOOST_AUTO_TEST_CASE(constructor)
{
    esc::EntityManager manager;

    BOOST_TEST(true);
}