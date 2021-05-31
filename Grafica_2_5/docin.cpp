#include <HSGIL/hsgil.hpp>
#include <iostream>
using namespace std;
using namespace luis;
int main(void) {
    RenderingWindow window(200, 200, "Vpri");
    Shader sh1("triangulo");
    float vertices[]  = {-0.5, -0.5, 0, 0, 0.5, 0, 0.5, -0.5, 0};
    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3*sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    while(window.isActive())
    {
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        sh1.use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);//
        window.pollEvents();
        window.swapBuffers();
    }
    
}