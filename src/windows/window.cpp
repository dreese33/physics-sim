#include "window.h"

namespace Windows {

  /**
   * @brief Initialize window and OpenGL window hints
   */
  void Window::init() {
    glfwInit();

    // v3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // macOS specific config
    #ifdef __APPLE__
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }


  /**
   * @brief Runs main loop for the physics simulator
   *
   * @param window The main content view
   */
  void Window::run(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window))
    {
      // prevents flickering effect
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }
  }


  /**
   * @brief Construct a new Window:: Window object
   *
   * @param width Width of window
   * @param height Height of window
   */
  Window::Window(int width, int height)
  {
    // initialize window
    init();

    // create glfw window, terminate if fails
    GLFWwindow *window = glfwCreateWindow(width, height, "Physics Simulator", NULL, NULL);
    if (window == NULL)
    {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return;
    }

    // execute on current thread
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return;
    }

    // window dimensions on change screen size
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL Run Loop
    run(window);

    glfwTerminate();
  }
}
