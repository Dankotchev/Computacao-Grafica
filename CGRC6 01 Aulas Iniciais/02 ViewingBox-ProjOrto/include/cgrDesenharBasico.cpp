#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"

void cgrDesenharRetangulosTeste(){

    // std::cout << "Entrou na funcao de retang. de teste" << std::endl;

    /* Retângulo vermelho, dentro de um viewBox ortogonal com os parametros de:
            left, right,    bottom, top,    near, far (near e far com sinal trocado)
    glOrtho(-1.0, 1.0,      -1.0, 1.0,      -1.0, 1.0)
    */
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);   // r,g,b
    glVertex3f(-0.2f, 0.8f, 0.0f); // x,y,z ... 
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glVertex3f(-0.8f, 0.2f, 0.0f);    
    glVertex3f(-0.8f, 0.8f, 0.0f);
    glEnd();

    /* Retângulo Verde, dentro de um viewBox ortogonal com os parametros de:
            left, right,    bottom, top,    near, far (near e far com sinal trocado)
    glOrtho(0.0, 200.0,     0.0, 150.0,     -1.0, 1.0);
    */
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex3f(20.0, 90.0, 0.0f);
    glVertex3f(80.0, 90.0, 0.0f);
    glVertex3f(80.0, 60.0, 0.0f);
    glVertex3f(20.0, 60.0, 0.0f);
    glEnd();
}