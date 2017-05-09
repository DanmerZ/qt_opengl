#include "openglwidget.h"
#include <QKeyEvent>
#include <QDebug>

#define _USE_MATH_DEFINES
#include <math.h>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      isWireframe(false),
      isOrtho(true),
      _left(-5.0),
      _right(5.0),
      _bottom(-5.0),
      _top(5.0),
      _near(5.0),
      _far(100.0),
      _w(1.0),
      _h(1.0)
{

}

void OpenGLWidget::setPolygoneMode(bool isWireframe)
{
    this->isWireframe = isWireframe;
    this->update();
}

QString OpenGLWidget::getFrustrumInfo() const
{
    return QString("L: %1 R: %2 B: %3 T: %4 N: %5, F: %6")
            .arg(_left).arg(_right).arg(_bottom).arg(_top).arg(_near).arg(_far);
}

QVector<float> OpenGLWidget::getFrustum() const
{
    return QVector<float>{_left, _right, _bottom, _top, _near, _far};
}

void OpenGLWidget::setFrustrum(float left_, float right_, float bottom_, float top_, float near_, float far_)
{
    _left = left_;
    _right = right_;
    _bottom = bottom_;
    _top = top_;
    _near = near_;
    _far = far_;

    update();
}

void OpenGLWidget::setFrustrum(QVector<float> frustum)
{
    _left = frustum[0];
    _right = frustum[1];
    _bottom = frustum[2];
    _top = frustum[3];
    _near = frustum[4];
    _far = frustum[5];

    update();
}

void OpenGLWidget::setProjection(bool isOrtho)
{
    this->isOrtho = isOrtho;
    update();
}

void drawDisc(float R, float X, float Y, float Z)
{
    int N = 40;
    float t = 0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(X, Y);
    for (int i = 0; i < N; i++)
    {
        glVertex3f(X + R * sinf(t), Y + R * cosf(t), Z);
        t += 2 * M_PI / (N - 1);
    }
    glEnd();
}

void drawHelix(float R, float X, float Y, float Z)
{
    float t = 0.0;

    glBegin(GL_LINE_STRIP);
    for(t = -10 * M_PI; t <= 10 * M_PI; t += M_PI/20.0)
    {
       glVertex3f(R * cos(t), R * sin(t), t - 60.0);
       //glVertex3f(R * cos(t), t  60.0, R * sin(t));
    }
    glEnd();
}

void OpenGLWidget::paintGL()
{
    glViewport(0, 0, _w, _h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (isOrtho)
        glOrtho(_left, _right, _bottom, _top, _near, _far);
    else
        glFrustum(_left, _right, _bottom, _top, _near, _far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (isWireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    drawHelix(4.0, 0.0, 0.0, 0.0);

//    glEnable(GL_DEPTH_TEST);
//    glColor3f(1.0, 0.0, 0.0); //red
//    drawDisc(20.0, 25.0, 75.0, 3.0);
//    glColor3f(1.0, 1.0, 1.0);
//    drawDisc(10.0, 25.0, 75.0, 4.5);
//    glDisable(GL_DEPTH_TEST); // white

//    glEnable(GL_DEPTH_TEST);
//    glColor3f(1.0, 1.0, 1.0); // white
//    drawDisc(10.0, 75.0, 75.0, 0.5);
//    glColor3f(1.0, 0.0, 0.0); // red
//    drawDisc(20.0, 75.0, 75.0, 0.0);
//    glDisable(GL_DEPTH_TEST);


//    glEnable(GL_DEPTH_TEST);
//    for (int i = 0; i < 5; i++)
//    {
//        glColor3f(0.2* i, 0.1 * i, 0.07*i+0.3);
//        drawDisc((i+1)*5, 50.0, 50.0, (0.6-i)*0.1);
//    }
//    glDisable(GL_DEPTH_TEST);


//    glEnable(GL_DEPTH_TEST);

//    glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_TRIANGLE_STRIP);
//        float t = 0.0f;
//        float X = 20.0, Y = 70.0;
//        float R = 15.0;
//        int num = 100;
//        for (int i = 0; i < num; i++)
//        {
//            glVertex3f(X + R * cosf(t), Y + R * sinf(t), 0.5);
//            glVertex3f(X + (R-5.0) * cosf(t), Y + (R-5.0) * sinf(t), 0.5);
//            t += 4 * 3.1415 / num;
//            glVertex3f(X + R * cosf(t), Y + R * sinf(t), 0.5);
//            glVertex3f(X + (R-5.0) * cosf(t), Y + (R-5.0) * sinf(t), 0.5);
//           // R += 0.1;
//        }
//    glEnd();

//    glColor3f(1.0, 0.0, 0.0);
//    glBegin(GL_TRIANGLE_STRIP);
//        t = 0.0f;
//        X = 40.0, Y = 70.0;
//        R = 15.0;
//        num = 100;
//        for (int i = 0; i < num; i++)
//        {
//            glVertex3f(X + R * cosf(t), Y + R * sinf(t), 0.0);
//            glVertex3f(X + (R-5.0) * cosf(t), Y + (R-5.0) * sinf(t), 0.0);
//            t += 4 * 3.1415 / num;
//            glVertex3f(X + R * cosf(t), Y + R * sinf(t), 0.0);
//            glVertex3f(X + (R-5.0) * cosf(t), Y + (R-5.0) * sinf(t), 0.0);
//           // R += 0.1;
//        }
//    glEnd();

//    glDisable(GL_DEPTH_TEST);

}

void OpenGLWidget::resizeGL(int w, int h)
{
    _w = w; _h = h;
    glViewport(0, 0, _w, _h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (isOrtho)
        glOrtho(_left, _right, _bottom, _top, _near, _far);
    else
        glFrustum(_left, _right, _bottom, _top, _near, _far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
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
    update();
}
