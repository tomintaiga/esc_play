#include "game_tests.h"

#define BOOST_TEST_MODULE game_test
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

#include "shader.h"

BOOST_AUTO_TEST_CASE(shader_constructor)
{
    game::Shader shader();

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(shader_id)
{
    game::Shader shader;

    GLuint id = shader.id();

    BOOST_TEST(id == 0);
}

int Test::run_tests()
{
    char *argv[] = { (char *)"EcsGame"};
    int argc = 1;

    return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}