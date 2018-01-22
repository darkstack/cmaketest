#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//extern struct gladGLversionStruct GLVersion;

//typedef void* (* GLADloadproc)(const char *name);
using namespace std;
class test {
    int x,y,z;
    public: 
    test()
    {
    x=y=z=0;
    }

    int getx()
    {
       return x;
    }

};

int main(){
    GLFWwindow* window;
    if (!glfwInit())
       return -1;
    window = glfwCreateWindow(640, 480, "test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents(); 
    }
   test* t = new test();
   t->getx();
   test p;

   return 0;
}
