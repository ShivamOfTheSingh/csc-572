#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

class EBO
{
public:
    unsigned int ID;
    EBO(const unsigned int *indices, GLsizeiptr size);

    void bind() const;
    void unbind() const;
    void destroy();
};

#endif
