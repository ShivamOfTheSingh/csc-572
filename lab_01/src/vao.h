#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include "vbo.h"

class VAO
{
public:
    unsigned int ID;
    VAO();

    void bind() const;
    void unbind() const;
    void linkAttrib(VBO &vbo, GLuint layout, GLint size, GLenum type,
                    GLsizei stride, void *offset);
    void destroy();
};

#endif
