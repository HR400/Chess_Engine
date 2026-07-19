#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <iostream>

using namespace std;

int main(){
    if(!glfwInit()){
        std::cerr<<"Failed to initialize GLFW"<<std::endl;
        return -1;
    }



glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

GLFWwindow* window =glfwCreateWindow(800,600,"Custom C++ chess Engine",nullptr,nullptr);
if(!window){
    std::cerr<<"Failed to create GLFW window"<<std::endl;
    glfwTerminate();
    return -1;
}
glfwMakeContextCurrent(window);

while(!glfwWindowShouldClose(window)){
    glClearColor(0.1f,0.1f,0.1f,0.1f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}