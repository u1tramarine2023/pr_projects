#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "mylist.h"
#include <QString>
#include <QPainter>
#include <string>
#include <fstream>
#include <QFileDialog>
#include "json.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_showButton_clicked();
    void on_pushButton_clicked();
    void on_popButton_clicked();
    void on_openButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<int> vector_stack;
    Stack* stack=new Stack();
    int max_num;
    nlohmann::json elements;

protected:
    void paintEvent(QPaintEvent* event);
};
#endif // MAINWINDOW_H
