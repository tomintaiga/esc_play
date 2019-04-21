
// For correct boost linking
#define BOOST_LOG_DYN_LINK 1

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

// Logging
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>

#include <iostream>

namespace LOG
{
    
/**
 * @brief Init Boost Log library
 * @see https://github.com/snikulov/boost-log-example
 */
static void init_log()
{
    static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]: %Message%");

    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

    // Output message to console
    boost::log::add_console_log(
        std::cout,
        boost::log::keywords::format = COMMON_FMT,
        boost::log::keywords::auto_flush = true);

    // Output message to file, rotates when file reached 1mb or at midnight every day. Each log file
    // is capped at 1mb and total is 20mb
    boost::log::add_file_log(
        boost::log::keywords::file_name = "sample_%3N.log",
        boost::log::keywords::rotation_size = 1 * 1024 * 1024,
        boost::log::keywords::max_size = 20 * 1024 * 1024,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::format = COMMON_FMT,
        boost::log::keywords::auto_flush = true);

    boost::log::add_common_attributes();

    // Only output message with INFO or higher severity in Release
#ifndef _DEBUG
    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::info);
#endif
}

} // namespace LOG

/**
 * @brief Command line arguments consts
 * @namespace ARGS
 */
namespace ARGS
{
const char *help_option = "help,h";
const char *help_descr = "Help screen";
const char *test_option = "test,t";
const char *test_descr = "Run tests";
} // namespace ARGS

int main(int argc, const char *argv[])
{
    // Init logging
    LOG::init_log();

    BOOST_LOG_TRIVIAL(info) << "Start app";

    // Check for command-line options
    try
    {
        // Prepare options
        boost::program_options::options_description desc{"Allowed options"};
        desc.add_options()(ARGS::help_option, ARGS::help_descr)(ARGS::test_option, ARGS::test_descr);

        // Parse them
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        // Check what we have
        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
            return EXIT_SUCCESS;
        }
        else if (vm.count("test"))
        {
            std::cout << "Runing tests" << std::endl;
            return Test::run_tests();
        }

        //If no such options specified - just run program
    }
    catch (const boost::program_options::error &e)
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
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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