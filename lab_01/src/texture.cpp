#include "texture.h"

Texture::Texture(const char *texture_path)
{
    // Flip image vertically (OpenGL expects (0,0) bottom-left)
    stbi_set_flip_vertically_on_load(true);

    int w, h, n_channels;
    unsigned char *data = stbi_load(texture_path, &w, &h, &n_channels, 0);

    if (!data)
    {
        std::cerr << "Failed to load texture: " << texture_path << std::endl;
        ID = 0; // invalid texture
        return;
    }

    // Generate and bind texture
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    // Select format based on channel count
    GLenum format;
    if (n_channels == 1)
        format = GL_RED;
    else if (n_channels == 3)
        format = GL_RGB;
    else if (n_channels == 4)
        format = GL_RGBA;
    else
        format = GL_RGB; // fallback

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Free image data from CPU
    stbi_image_free(data);
}

Texture::~Texture()
{
    if (ID != 0)
    {
        glDeleteTextures(1, &ID);
    }
}

void Texture::bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
