#include <iostream>
#include <GLFW/glfw3.h>

#define GLFW_MAJOR_VERSION 3
#define GLFW_MINOR_VERSION 3
#define DEFAULT_WINDOW_HEIGHT 600
#define DEFAULT_WINDOW_WIDTH 800

void setWindowHints();

int main()
{
    std::cout << "Starting window..." << std::endl;
    glfwInit();

    setWindowHints();
    GLFWwindow *window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "fun-window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Window is null :(" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
        glfwPollEvents();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void setWindowHints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // required by macos for opengl3+
}
