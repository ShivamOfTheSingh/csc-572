#include "vbo.h"

VBO::VBO(const void *data, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::destroy()
{
    glDeleteBuffers(1, &ID);
}
