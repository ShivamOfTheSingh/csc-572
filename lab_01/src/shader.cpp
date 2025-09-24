#include "shader.h"

using namespace std;

Shader::Shader(const char *vertex_path, const char *fragment_path)
{
    // 1. Read vertex shader code
    ifstream vertex_file(vertex_path);
    stringstream vertex_stream;
    vertex_stream << vertex_file.rdbuf();
    string vertex_code = vertex_stream.str();
    const char *vertex_shader_str = vertex_code.c_str();

    // 2. Read fragment shader code
    ifstream fragment_file(fragment_path);
    stringstream fragment_stream;
    fragment_stream << fragment_file.rdbuf();
    string fragment_code = fragment_stream.str();
    const char *fragment_shader_str = fragment_code.c_str();

    // 3. Compile vertex shader
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_shader_str, nullptr);
    glCompileShader(vertex);

    // Check vertex compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
             << infoLog << endl;
    }

    // 4. Compile fragment shader
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_shader_str, nullptr);
    glCompileShader(fragment);

    // Check fragment compile errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
             << infoLog << endl;
    }

    // 5. Link shaders
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    // Check linking errors
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
             << infoLog << endl;
    }

    // 6. Delete shaders (no longer needed after linking)
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
