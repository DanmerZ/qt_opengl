#include "openglwidget.h"
#include <QKeyEvent>
#include <QDebug>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), isWireframe(false)
{

}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (isWireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(1.0, 1.0, 0.5);

    glPointSize(1.0); // Set point size.
    glBegin(GL_POLYGON);
       glVertex3f(20.0f, 20.0f, 0.0f);
       glVertex3f(80.0f, 20.0f, 0.0f);
       glVertex3f(80.0f, 80.0f, 0.0f);
       glVertex3f(20.0f, 80.0f, 0.0f);
    glEnd();

    glColor3f(0.5, 0.0, 0.5);

    glBegin(GL_POLYGON);
       glVertex3f(2.0f, 2.0f, 0.0f);
       glVertex3f(8.0f, 2.0f, 0.0f);
       glVertex3f(8.0f, 8.0f, 0.0f);
       glVertex3f(2.0f, 8.0f, 0.0f);
    glEnd();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-w, w, -h, h, -1.0, 1.0);
    glOrtho(0.0f, 100.0f, 0.0f, 100.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.3f, 0.4f, 0.3f, 1.0f);
}

void OpenGLWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W)
    {
        isWireframe = true;
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else if (event->key() == Qt::Key_S)
    {
        isWireframe = false;
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
//    update();
}
