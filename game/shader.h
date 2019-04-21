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

private:
    GLuint _id;
};

} // namespace game

#endif // SHADER_H