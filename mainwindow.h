#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class OpenGLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionWireframe_triggered(bool checked);

    void on_spinBoxNear_valueChanged(double nearValue);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_spinBoxFar_valueChanged(double farValue);

    void on_spinBoxLeft_valueChanged(double leftValue);

    void on_spinBoxRight_valueChanged(double rightValue);

    void on_spinBoxBottom_valueChanged(double bottomValue);

    void on_spinBoxTop_valueChanged(double topValue);

private:
    Ui::MainWindow *ui;

    OpenGLWidget *openGLWidget;
};

#endif // MAINWINDOW_H
