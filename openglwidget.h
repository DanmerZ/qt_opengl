#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent = nullptr);

protected:
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();

    void keyPressEvent(QKeyEvent *event);

    bool isWireframe;
};

#endif // OPENGLWIDGET_H
