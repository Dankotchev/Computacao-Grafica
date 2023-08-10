#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"

void cgrDesenharRetangulosTeste(){

    //std::cout << "Entrou na funcao de retang. de teste" << std::endl;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);   // r,g,b
    glVertex3f(-0.2f, 0.8f, 0.0f); // x,y,z ...
    glColor3f(1.0f, 1.0f, 0.0f);   
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);   
    glVertex3f(-0.8f, 0.2f, 0.0f);    
    glColor3f(0.0f, 0.0f, 1.0f);   
    glVertex3f(-0.8f, 0.8f, 0.0f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(20.0, 90.0, 0.0f);
    glVertex3f(80.0, 90.0, 0.0f);
    glVertex3f(80.0, 60.0, 0.0f);
    glVertex3f(20.0, 60.0, 0.0f);
    glEnd();
}