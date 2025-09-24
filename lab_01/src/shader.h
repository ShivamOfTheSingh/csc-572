#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Shader
{
public:
    // The shader id
    unsigned int ID;

    // constructor
    Shader(const char* vertex_path, const char* fragment_path);

    // calls the shader program in the render loop
    void use();

    // functions to work with uniforms
    void setBool(const string &name, bool value) const;
    void setInt(const string &name, int value) const;
    void setFloat(const string &name, float value) const;
};

#endif