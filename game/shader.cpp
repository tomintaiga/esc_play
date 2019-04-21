#include "shader.h"

void game::Shader::compile(const GLchar* vertexSource, const GLchar* fragmentSource)
{
    // First, lets check for input
    if(!vertexSource)
    {
        // Need to report error

        return;
    }
}