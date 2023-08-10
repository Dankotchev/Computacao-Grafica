#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World - Triângulo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // especificacao da cor de fundo
    // red, green, blue, alpha
    glClearColor(1.0, 1.0, 1.0, 1.0); 


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   // r,g,b
        glVertex3f(-0.2f, 0.8f, 0.0f); // x,y,z ...

        glColor3f(1.0f, 1.0f, 0.0f);   
        glVertex3f(-0.2f, 0.2f, 0.0f);

        glColor3f(1.0f, 1.0f, 1.0f);   
        glVertex3f(0.8f, 0.2f, 0.0f);                
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}