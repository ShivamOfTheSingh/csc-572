#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>
#include <iostream>

class Texture
{
public:
    unsigned int ID;

    // Constructor loads texture from file
    Texture(const char *texture_path);

    // Destructor cleans up GPU resource
    ~Texture();

    // Bind the texture for use
    void bind(GLenum texture_unit = GL_TEXTURE0) const;

    // Unbind the texture
    void unbind() const;
};

#endif
