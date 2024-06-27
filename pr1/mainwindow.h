#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>

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
    int max_num;
private slots:
    void on_showButton_clicked();
private:
    Ui::MainWindow *ui;
    std::vector<int> Data;
    void ReadData();

protected:
    void paintEvent(QPaintEvent* event);
};
#endif // MAINWINDOW_H
