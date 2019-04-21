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

BOOST_AUTO_TEST_CASE(shader_compile)
{
    game::Shader shader;

    const GLchar *vShader = "#version 330 core\n"
                            "layout(location = 0) in vec3 aPos;\n"
                            "layout(location = 1) in vec2 aTexCoord;\n"
                            "out vec2 TexCoord;\n"
                            "uniform mat4 model;\n"
                            "uniform mat4 view;\n"
                            "uniform mat4 projection;\n"
                            "void main()\n"
                            "{\n"
                            "gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
                            "TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
                            "}\n";
    const GLchar *fShader = "#version 330 core\n"
                            "out vec4 FragColor;\n"
                            "in vec2 TexCoord;\n"
                            "uniform sampler2D texture1;\n"
                            "uniform sampler2D texture2;\n"
                            "uniform float opacity;\n"
                            "void main()\n"
                            "{\n"
                            "FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), opacity);\n"
                            "}\n";

    shader.compile(vShader, fShader);

    BOOST_TEST(shader.id() != 0);
}

int Test::run_tests()
{
    char *argv[] = {(char *)"EcsGame"};
    int argc = 1;

    return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}