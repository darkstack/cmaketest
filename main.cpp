#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "test.cpp"
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
float a=1.0f,b=1.0f,c=1.0f;

int test2()
{
   if(a!=0.0f)
   {
      a-= 0.001f;
   
   }
   else
   {
      a=.0f;
   }
   glClearColor(a,a,a,a);
   return 1;
}

int main(){
   player p1;
   int x = p1.getHealth();
   printf("%i",x);
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
        test2();

    }
   test* t = new test();
   t->getx();
   test p;

   return 0;
}
