#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"


/**
    Exemplo para demonstrar uso de
     transformacao de translacao na chamada.
*/
void cgrDesenharCubo(){
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE, GL_POINT, GL_FILL
    //glPointSize(15.0f);

    // vertices do cubo (modelo, objeto) estao no intervalo [-1, 1]
    GLfloat verticesCubo[] =
    {
        -1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
         1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
        -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
        -1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
    };

    GLfloat coresCubo[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    glColorPointer(3, GL_FLOAT, 0, coresCubo);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Limpa os estados */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

/**
    Figura geometrica - piramide
*/
void cgrDesenharPiramide(){

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // modo de tracado - linhas (inspecao visual)
    glLineWidth(1.0); // expessura da linha

    // glScalef(4.0, 4.0, 4.0);

    GLfloat verticesPiramide[] = {
        -0.5, 0.0, 0.5,   0.0, 1.0, 0.0,   0.5, 0.0, 0.5,
        -0.5, 0.0, -0.5,  0.0, 1.0, 0.0,  -0.5, 0.0, 0.5,
       
        -0.5, 0.0, -0.5,  0.0, 1.0, 0.0,   0.5, 0.0,-0.5,
         0.5, 0.0,-0.5,  0.0, 1.0, 0.0,   0.5, 0.0, 0.5,

        -0.5, 0.0, 0.5,  -0.5, 0.0, -0.5,   0.5,0.0,0.5, // base - 2 triangulos
        -0.5, 0.0, -0.5,  0.5, 0.0,-0.5,  0.5,0.0,0.5
    };

    GLfloat coresPiramide[]={
        0, 0, 0.4,      0, 0, 0.4,      0, 0, 0.4,            // azul escuro
        1, 0.5, 0,      1, 0.5, 0,      1, 0.5, 0,            // laranja
        1, 1, 0,        1, 1, 0,        1, 1, 0,                  // amarelo
        0, 1, 0.5,      0, 1, 0.5,      0, 1, 0.5,              // verde
        0.0,0.0,0.0,    0.0,0.0,0.0,    0.0,0.0,0.0,         // preto
        0.0,0.0,0.0,    0.0,0.0,0.0,    0.0,0.0,0.0          // preto
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verticesPiramide); // size, tipo, deslocamento inicial, ponteiro
    glColorPointer(3,  GL_FLOAT, 0, coresPiramide);     // size, tipo, deslocamento inicial, ponteiro

    glDrawArrays(GL_TRIANGLES, 0, 6*3); // desenha os pontos da piramide

    // limpa estados
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}