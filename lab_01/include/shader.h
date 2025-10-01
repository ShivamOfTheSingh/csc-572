#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    // The shader program ID
    unsigned int ID;

    // Constructor reads and builds the shader
    Shader(const char* vertex_path, const char* fragment_path);

    // Activate the shader program
    void use() const;

    // Utility functions for setting uniforms
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
};

#endif // SHADER_H
