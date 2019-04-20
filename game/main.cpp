// For OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// For glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ECS
#include <entity_manager.h>

#include <boost/program_options.hpp>
#include "game_tests.h"

#include <iostream>

/**
 * @brief Command line arguments consts
 * @namespace ARGS
 */
namespace ARGS
{
    const char* help_option = "help,h";
    const char* help_descr  = "Help screen";
    const char* test_option = "test,t";
    const char* test_descr  = "Run tests";
}

int main(int argc, const char *argv[])
{
    // Check for command-line options
    try
    {
        // Prepare options
        boost::program_options::options_description desc{"Allowed options"};
        desc.add_options()
            (ARGS::help_option, ARGS::help_descr)
            (ARGS::test_option, ARGS::test_descr);

        // Parse them
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        // Check what we have
        if(vm.count("help"))
        {
            std::cout << desc << std::endl;
            return EXIT_SUCCESS;
        }
        else if(vm.count("test"))
        {
            std::cout << "Runing tests" << std::endl;
            return Test::run_tests();
        }

        //If no such options specified - just run program

    }
    catch(const boost::program_options::error& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }

     // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return EXIT_SUCCESS;    
}