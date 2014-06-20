#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>

#include "Vector.h"

namespace {
GLuint vbo; // handle for vertex buffer
}

static void render_scene_cb(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glPointSize(10.0f);

    glDrawArrays(GL_POINTS, 0, 1);

    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}

static void initialize_glut_callbacks(void)
{
    glutDisplayFunc(render_scene_cb);
}

static void create_vertex_buffer(void)
{
    Vector3f vertices;

    glGenBuffers(1, &vbo); // allocate buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
    /* init glut */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 02");

    initialize_glut_callbacks();


    /* init glew */
    GLenum res = glewInit();

    if (res != GLEW_OK)
    {
        std::cout << "Error: " << glewGetErrorString(res) << std::endl;
        return 1;
    }



    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    create_vertex_buffer();
    glutMainLoop();

    return 0;
}
