#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <vector>
#include <QTimer>



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
    void StartGame();
    void PreGame();
    void UserClick(bool isMarked);
    void GenerateField(int level);
private slots:
void on_startButton_clicked();
private:
    Ui::MainWindow *ui;
    QTimer* timer;
    std::vector<QObject*> AllSquares;
    int MarkedCount;
    int UserTrueCount;
    int UserFalseCount;
    int level=1;
    int fieldSize=5;
    int recordLevel=0;
};
#endif // MAINWINDOW_H
