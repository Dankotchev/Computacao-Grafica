#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"


/**
    Exemplo para demonstrar uso de
     transformacao de translacao na chamada.
*/
void cgrDesenharCubo(float r, float g, float b){
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_LINE, GL_POINT, GL_FILL
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
        r, g, b,   r, g, b,   r, g, b,   r, g, b,
        r, g, b,   r, g, b,   r, g, b,   r, g, b,
        r, g, b,   r, g, b,   r, g, b,   r, g, b,
        r, g, b,   r, g, b,   r, g, b,   r, g, b,
        r, g, b,   r, g, b,   r, g, b,   r, g, b,
        r, g, b,   r, g, b,   r, g, b,   r, g, b
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
