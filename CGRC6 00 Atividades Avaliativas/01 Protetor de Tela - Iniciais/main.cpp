#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"
#define TAMANHOLR 20.0

/** assinatura das funcoes **/

/** configuracoes iniciais **/
void aplicarConfigInicial(GLFWwindow *window);

/** janela redimensionada**/
void ajustarJanela(GLFWwindow *window, int w, int h);

void desenharD(double t, double x, double y, double z){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x, y, z);
    glRotatef(15 * 2 * t, 0.0, 1.0, 0.0);

    cgrDesenharCubo(1, 0, 1.0);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);

    glTranslatef(2.0, 0.0, 0.0);
    cgrDesenharCubo(1, 1, 1);

    glTranslatef(2.0, -2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);

    glTranslatef(2.0, 0.0, 0.0);
    cgrDesenharCubo(1, 1, 1);

    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);

    glTranslatef(-2.0, 0.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(-2.0, -2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(-2.0, 0.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1, 1, 1);
}

void desenharQ(double t, double x, double y, double z)
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x, y - 4.0, z);
    glRotatef(15 * 2 * t, 0.0, 1.0, 0.0);

    cgrDesenharCubo(1.0f, 0.5f, 0.85f);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, 2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);

    glTranslatef(2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);

    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(0.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);

    glTranslatef(-2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(-2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);
    glTranslatef(-2.0, 0.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 1.0);

    glTranslatef(5.0, 1.0, 0.0);
    cgrDesenharCubo(0.0, 1.0, 1.0);
    glTranslatef(-2.0, 2.0, 0.0);
    cgrDesenharCubo(0.0, 1.0, 1.0);

    glTranslatef(4.0, -4.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 0.0);
    glTranslatef(2.0, -2.0, 0.0);
    cgrDesenharCubo(1.0, 1.0, 0.0);
}

void desenharCena1(double t)
{
    glClear(GL_COLOR_BUFFER_BIT); // cor de fundo
    glClear(GL_DEPTH_BUFFER_BIT); // z-buffer

    desenharD(t, -10.0, 0.0, 0.0);
    desenharD(t, 0.0, 0.0, 0.0);
    desenharQ(t, 10.0, 0.0, 0.0);
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Projeção Ortogonal - Figuras 3D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // aplicando configuracoes --> outros nomes: init ou setup
    aplicarConfigInicial(window);

    double tempo;

    /* Loop until the user closes the window */
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        tempo = glfwGetTime(); // contador de tempo incremental

        desenharCena1(tempo);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void aplicarConfigInicial(GLFWwindow *window)
{
    glEnable(GL_DEPTH_TEST);

    int largura, altura;
    glfwGetWindowSize(window, &largura, &altura);

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    glfwSetWindowSizeCallback(window, ajustarJanela);
    ajustarJanela(window, largura, altura);
}

void ajustarJanela(GLFWwindow *window, int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-TAMANHOLR, TAMANHOLR, -20.0, 20.0, -2.0, 2.0);
}