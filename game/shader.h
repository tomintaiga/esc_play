/**
 * @brief Header file for game::Shader class
 * @file shader.h
 */

#ifndef SHADER_H
#define SHADER_H

#include <GL/gl.h>

namespace game
{

/**
 * @brief Class for loading compiling and using shader
 */
class Shader
{
public:

    /**
     * @brief Construct a new Shader object
     */
    Shader(): _id{} {}

    /**
     * @brief Get shader ID
     * 
     * @return GLuint Shader ID
     */
    GLuint id() const { return _id;}

    /**
     * @brief Compile program for given shader sources
     * 
     * @param vertexSource Text of vertex shader
     * @param fragmentSource Text of fragment shader
     * 
     * gane::Shader::id must be not 0 after this function call. If so - we got error
     */
    void compile(const GLchar* vertexSource, const GLchar* fragmentSource);

private:
    GLuint _id;
};

} // namespace game

#endif // SHADER_H