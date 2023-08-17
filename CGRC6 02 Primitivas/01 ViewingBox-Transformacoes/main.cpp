#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"

/** assinatura das funcoes **/

/** configuracoes iniciais **/
void aplicarConfigInicial(GLFWwindow *window);

/** janela redimensionada**/
void ajustarJanela(GLFWwindow *window, int w, int h);

void desenharCena1(double t)
{
    glClear(GL_COLOR_BUFFER_BIT); // cor de fundo
    glClear(GL_DEPTH_BUFFER_BIT); // z-buffer

    glMatrixMode(GL_MODELVIEW);                 // indicar qual matriz sera modificada
    glLoadIdentity();                           // "reset" na matriz
    // glTranslatef(-1.0, 0.0, 0.0);
    // glTranslatef(100.0, 50.0, 0.0);             // translações
    glRotatef(30*t, 1.0, 0.0, 0.0);             // rotacionando ao longo de x
    glRotatef(15, 0.0, 1.0, 0.0);             // rotacionando ao longo de y
    glRotatef(15, 0.0, 0.0, 1.0);             // rotacionando ao longo de z
    // glScalef(8.0, 6.0, 3.0);                    // fator de escala
    // cgrDesenharCubo();
    cgrDesenharPiramide();
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

    double tempo; // util para animacoes, transicoes

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

/**
 * Configuracoes do world system **/
void aplicarConfigInicial(GLFWwindow *window)
{

    glEnable(GL_DEPTH_TEST); // habilita z-buffer (depth test)

    int largura, altura;
    glfwGetWindowSize(window, &largura, &altura); // obtem largura e altura

    // especificacao da cor de fundo
    // red, green, blue, alpha
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // registro de quais funcoes serao executadas apos eventos
    glfwSetWindowSizeCallback(window, ajustarJanela);
    ajustarJanela(window, largura, altura);
}

/** configuracao para ser executada a cada redimensionamento
 * e tambem na primeira vez que o codigo for ser executado **/
void ajustarJanela(GLFWwindow *window, int w, int h)
{
    std::cout << "Dimensoes atuais da janela: " << w << ", " << h << std::endl;

    // lower x, lower y, largura, altura (em pixels)
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); // indicar qual matriz sera modificada
    glLoadIdentity();            // "reset" na matriz de projecao

    // definicao do viewing box que sera utilizado (universo)
    // left, right, bottom, top, near, far (near e far com sinal trocado)
    // glOrtho(-1.0, 1.0,    -1.0, 1.0,  -1.0, 1.0);
    glOrtho(-2.0, 2.0,    -2.0, 2.0,  -2.0, 2.0);
    // glOrtho(0.0, 200.0, 0.0, 100.0, -10.0, 10.0);
}