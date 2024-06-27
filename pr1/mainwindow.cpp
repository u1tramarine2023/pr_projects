#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_showButton_clicked(){
    ReadData();

    this->update();

}
void MainWindow::ReadData(){
    QStringList lines = ui->plainTextEdit->toPlainText()
                            .split('\n', Qt::SkipEmptyParts);
   Data.clear();
    for (int i = 0; i < lines.count(); ++i) {

        Data.push_back(lines.at(i).toInt());
    }
    max_num=Data[0];
    for (int i = 0; i < Data.size(); ++i) {
        if(Data[i]>max_num){
            max_num=Data[i];
        }
    }
}
void MainWindow::paintEvent(QPaintEvent* event) {

    QPainter painter(this);
    painter.begin(this);

    int StartX = ui->frame->geometry().left();
    int StartY = ui->frame->geometry().top();
    int widthFrame= ui->frame->width();
    int heightFrame= ui->frame->height();
    int space=15;
    //int width=20;
    int amount=Data.size();
    if(amount!=0){
    int width=widthFrame/max_num;
    int height=(heightFrame-(space*amount))/amount;

     painter.setBrush(QBrush(Qt::black));
    for (int i = 0; i < amount ; ++i) {
        painter.drawRect( StartX, StartY+(height+space)*i, Data[i]*width , height);
    }
    }
    painter.end();
}
