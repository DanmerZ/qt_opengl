#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget = new OpenGLWidget(this);
    setCentralWidget(openGLWidget);

    openGLWidget->setFocus();
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());

    QVector<float> frustum = openGLWidget->getFrustum();
    ui->spinBoxLeft->setValue(frustum[0]);
    ui->spinBoxRight->setValue(frustum[1]);
    ui->spinBoxBottom->setValue(frustum[2]);
    ui->spinBoxTop->setValue(frustum[3]);
    ui->spinBoxNear->setValue(frustum[4]);
    ui->spinBoxFar->setValue(frustum[5]);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionWireframe_triggered(bool checked)
{
    openGLWidget->setPolygoneMode(checked);
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    openGLWidget->setProjection(checked);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    openGLWidget->setProjection(!checked);
}

void MainWindow::on_spinBoxNear_valueChanged(double nearValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[4] = nearValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}


void MainWindow::on_spinBoxFar_valueChanged(double farValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[5] = farValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}

void MainWindow::on_spinBoxLeft_valueChanged(double leftValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[0] = leftValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}

void MainWindow::on_spinBoxRight_valueChanged(double rightValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[1] = rightValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}

void MainWindow::on_spinBoxBottom_valueChanged(double bottomValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[2] = bottomValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}

void MainWindow::on_spinBoxTop_valueChanged(double topValue)
{
    QVector<float> frustum = openGLWidget->getFrustum();
    frustum[3] = topValue;
    openGLWidget->setFrustrum(frustum);
    ui->statusBar->showMessage(openGLWidget->getFrustrumInfo());
}
