#include "vao.h"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::bind() const
{
    glBindVertexArray(ID);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

void VAO::linkAttrib(VBO &vbo, GLuint layout, GLint size, GLenum type,
                     GLsizei stride, void *offset)
{
    vbo.bind();
    glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
}

void VAO::destroy()
{
    glDeleteVertexArrays(1, &ID);
}
