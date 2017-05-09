#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent = nullptr);

    void setPolygoneMode(bool isWireframe);

    QString getFrustrumInfo() const;
    QVector<float> getFrustum() const;
    void setFrustrum(float left_, float right_, float bottom_, float top_, float near_, float far_);
    void setFrustrum(QVector<float> frustum);

    void setProjection(bool isOrtho);

protected:
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();

    void keyPressEvent(QKeyEvent *event);

    bool isWireframe;
    bool isOrtho;

private:

    float _left, _right, _bottom, _top, _near, _far;
    float _w, _h;
};

#endif // OPENGLWIDGET_H
