#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include "test.cpp"
#include "game.cpp"
//extern struct gladGLversionStruct GLVersion;

//typedef void* (* GLADloadproc)(const char *name);
using namespace std;

int main(int argc,char** argv[]){
   glm::mat4 test; 
   Game game;
   int x,y;
   player p1;
   GLFWwindow* window;
   if (!glfwInit())
      return -1;
   window = glfwCreateWindow(640, 480, "test",NULL, NULL);
   if (!window)
   {
      glfwTerminate();
      return -1;
   }
   glfwMakeContextCurrent(window);
   gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
   glfwSwapInterval(1);
   glfwGetWindowSize(window,&x,&y);
   game.setSize(x,y);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0,x,y,0.0f,0.0f,1.0f);
   while (!glfwWindowShouldClose(window))
   {
      glfwGetWindowSize(window,&x,&y);
      glClear(GL_COLOR_BUFFER_BIT);
      game.process();
      glfwSwapBuffers(window);
      glfwPollEvents();
      game.printSize();
   }

   return 0;
}
