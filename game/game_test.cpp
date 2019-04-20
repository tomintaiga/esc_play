#include "game_tests.h"

#define BOOST_TEST_MODULE game_test
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test1)
{
    BOOST_TEST(true);
}

int Test::run_tests()
{
    char *argv[] = {"EcsGame"};
    int argc = 1;

    return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}