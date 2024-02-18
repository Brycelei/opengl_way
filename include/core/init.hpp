//#pragma once
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//float fov = 60.0f;
//
////当前帧率于上一帧的时间差
//float delta_time = 0.0f;
//float last_frame = 0.0f;
//
//GLFWwindow *main_window;
//
////camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float last_x = 800.0f / 2.0;
//float last_y = 600.0f / 2.0;
//bool first_mouse = true;
//
//
//void mouse_callback(GLFWwindow* window, double xpos_in, double ypos_in)
//{
//    float xpos = static_cast<float>(xpos_in);
//    float ypos = static_cast<float>(ypos_in);
//
//    if (first_mouse)
//    {
//        last_x = xpos;
//        last_y = ypos;
//        first_mouse = false;
//    }
//
//    float xoffset = xpos - last_x;
//    float yoffset = last_y - ypos;
//
//    last_x = xpos;
//    last_y = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//
//
//void framebuffer_size_callback(GLFWwindow *window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void process_input(GLFWwindow *window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//    {
//        glfwSetWindowShouldClose(window, true);
//    }
//    float camera_speed = 4.0f * delta_time;
//
//    // 相机WASD移动输入
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, delta_time);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, delta_time);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, delta_time);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, delta_time);
//}
//
//
//void opengl_init()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    main_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "gl", nullptr, nullptr);
//
//    if (main_window == nullptr)
//    {
//        cerr << "ERROR: Failed to create GLFW window !!!" << endl;
//        glfwTerminate();
//    }
//
//    
//    glfwMakeContextCurrent(main_window);
//    glfwSetFramebufferSizeCallback(main_window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(main_window, mouse_callback);
//    glfwSetScrollCallback(main_window, scroll_callback);
//
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        cerr << "ERROR: Failed to initialize GLAD !!!" << endl;
//        glfwTerminate();
//    }
//
//    // 隐藏GLFW光标
//    glfwSetInputMode(main_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    glViewport(0, 0, 800, 600);
//}
