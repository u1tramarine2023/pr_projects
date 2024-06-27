#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);




}
void MainWindow::on_pushButton_clicked(){
    if(ui->lineEdit->text().toInt())
    stack->push(ui->lineEdit->text().toInt());
    ui->lineEdit->clear();
    ui->showButton->click();
}
void MainWindow::on_popButton_clicked(){
    stack->pop();
     ui->showButton->click();
}



void MainWindow::on_showButton_clicked(){
    vector_stack = stack->print();
    max_num=vector_stack[0];
    std::string string_stack;
    for (int i = 0; i < vector_stack.size(); ++i) {
        int num=vector_stack[i];
        string_stack+=std::to_string(num) + " ";
        if(num>max_num){
            max_num=num;
        }
    }

    ui->label->setText(QString::fromStdString(string_stack));
    this->update();

}

void MainWindow::paintEvent(QPaintEvent* event) {

    QPainter painter;
    painter.begin(this);

    int StartX = ui->frame->geometry().left();
    int StartY = ui->frame->geometry().top();
    int widthFrame= ui->frame->width();
    int heightFrame= ui->frame->height();
    int space=15;
    //int width=20;
    int amount=vector_stack.size();
    if(amount!=0){
        int width=widthFrame/max_num;
        int height=(heightFrame-(space*amount))/amount;

        painter.setBrush(QBrush(Qt::black));
        for (int i = 0; i < amount ; ++i) {
            painter.drawRect( StartX, StartY+(height+space)*i, vector_stack[i]*width , height);
        }
    }
    painter.end();
}


MainWindow::~MainWindow()
{
    delete ui;
}
