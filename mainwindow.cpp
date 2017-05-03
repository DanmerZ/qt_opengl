#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget = new OpenGLWidget(this);
    setCentralWidget(openGLWidget);

    openGLWidget->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
