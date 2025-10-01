#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// custom classes
#include "shader.h"
#include "vbo.h"
#include "vao.h"
#include "ebo.h"
#include "texture.h"
#include "transform.h"
#include "projection.h"

// vertices + indices
float vertices[] = {
    // positions            // colors               // texture coords
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
};

unsigned int indices[] = {
    0, 1, 2,
    0, 2, 3};

// prototypes
void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main()
{
    // init glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // load glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // enable depth test (good practice)
    glEnable(GL_DEPTH_TEST);

    // -------- SHADER --------
    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    // -------- VAO / VBO / EBO --------
    VAO vao;
    vao.bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);                   // pos
    vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float))); // color
    vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float))); // tex coords

    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    // -------- TEXTURES --------
    Texture text1("/Users/ssingh/documents/csc-572/lab_01/resources/wall.jpg");
    Texture text2("/Users/ssingh/documents/csc-572/lab_01/resources/awesomeface.png");

    // -------- TRANSFORMS --------
    Transform model1;
    model1.setRotation(glm::vec3(0.0f, 0.0f, 55.0f));
    model1.setPosition(glm::vec3(0.0f, 0.0f, -1.0f)); // push object into view

    Transform view;
    view.setPosition(glm::vec3(0.0f, 0.0f, 0.0f)); // camera at origin

    Projection p;
    // set orthographic projection matching your quad coordinates
    p.setOrthographic(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

    // -------- RENDER LOOP --------
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // clear buffers
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // use shader + global uniforms
        shader.use();
        shader.setMat4("view", view.getMatrix());
        shader.setMat4("projection", p.getMatrix());
        shader.setInt("text1", 0);
        shader.setInt("text2", 1);

        // bind textures
        text1.bind(0);
        text2.bind(1);

        vao.bind();

        // per-object model matrix
        shader.setMat4("model", model1.getMatrix());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // swap buffers & poll
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// input
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// viewport resize
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
