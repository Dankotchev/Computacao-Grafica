#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Crie uma janela em modo janela e seu contexto OpenGL */
    window = glfwCreateWindow(640, 480, "Hello World - Triângulo", NULL, NULL);
    if (!window)
    {
        /*Fecha a janela caso não de certo*/
        glfwTerminate();
        return -1;
    }
    

    /* Torna o contexto a janela atual */
    glfwMakeContextCurrent(window);

    /* especificacao da cor de fundo: red, green, blue, alpha */
    glClearColor(0.0, 0.0, 0.0, 1.0); 

    glPointSize(15);

    float x = -0.5f;

    /* Repetir até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*Modo imediato: primitiva de triâgulo
            Declaração para inicio
        */
        //glBegin(GL_TRIANGLES);

        // /*Vertices do triângulo*/
        // glColor3f(1.0f, 1.0f, 0.0f);   // r,g,b
        // glVertex3f(-0.2f, 0.8f, 0.0f); // x,y,z ...

        // glColor3f(0.0f, 1.0f, 1.0f);   
        // glVertex3f(-0.2f, 0.2f, 0.0f);

        // glColor3f(1.0f, 0.0f, 1.0f);   
        // glVertex3f(0.8f, 0.2f, 0.0f);                
        // glEnd();

        // glBegin(GL_TRIANGLES);
        // /*Vertices do triângulo*/
        // glColor3f(1.0f, 1.0f, 0.0f);   // r,g,b
        // glVertex3f(x, -1.0f, 0.0f); // x,y,z ...

        // /*sistema de estados: enquanto não alterar ele mantem o estado da cor*/
        // glColor3f(0.0f, 1.0f, 1.0f);   
        // glVertex3f(-x, -1.0f, 0.0f);

        // glColor3f(1.0f, 0.0f, 1.0f);   
        // glVertex3f(0.0f, -x, 0.0f);                
        // glEnd();

        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);   // r,g,b
        glVertex3f(x, -0.5f, 0.0f); // x,y,z ...

        glColor3f(0.0f, 1.0f, 0.0f);   
        glVertex3f(-x, -0.5f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);   
        glVertex3f(0.0f, -x, 0.0f);                
        glEnd();

        x+=0.00001f;
        if (x > 0.5f)
            x = -0.5f;
    
        
        /* Troca de buffer: front e back
            front:  "O que está sendo exibido"
            back:   Em processamento a próxima cena de objetos
            Encaminhamento do que foi desenhado para a janela
        */
        glfwSwapBuffers(window);

        /* Pesquisa e processamento de eventos
            Teclado, mouse, entrada/saída
        */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}