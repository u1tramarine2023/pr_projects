#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <squarewidget.h>
#include <ctime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::StartGame);
    //генерация пустого поля
    for (int row = 0; row < fieldSize; ++row) {
        for (int col = 0; col < fieldSize; ++col) {
            SquareWidget* square = new SquareWidget( this, false, this);

            ui->gridLayout->addWidget(square, row, col, Qt::AlignCenter);
        }
    }


}
void MainWindow::on_startButton_clicked(){
    timer->start(1000+level*150);
    UserTrueCount=0;
    ui->labelLevel->setText(QString::number(level));
    GenerateField(level);

}
void MainWindow::GenerateField(int level){

    //генерация вектора из пар координат квадратов
    std::vector<std::pair<int, int>> markedPositions;
    int attemptCount=0;
    //смена сложности
    int complexity=0;

        fieldSize=5+level/10;

    if(level>8){
        complexity=2;}
    else if(level>4){
        complexity=1;};
    while ( markedPositions.size() < level) {
        attemptCount++;

        int row = rand() % fieldSize;
        int col = rand() % fieldSize;
        if( markedPositions.size()>=1 && attemptCount<1000){
            int prev_row=markedPositions[markedPositions.size()-1].first;
            int prev_col=markedPositions[markedPositions.size()-1].second;
            if (complexity==0){
                    if((row==prev_row && abs(col-prev_col)==1) ||
                   (col==prev_col && abs(row-prev_row)==1) ){

                }
                else continue;
            }
            else if (complexity==1){
                if((row==prev_row && abs(col-prev_col)==1) ||
                    (col==prev_col && abs(row-prev_row)==1) ||
                    (abs(row-prev_row)==1 && abs(col-prev_col)==1)){

                }
                else continue;
            }
        }
        if (std::find(markedPositions.begin(), markedPositions.end(), std::make_pair(row, col)) == markedPositions.end()) {
            markedPositions.emplace_back(row, col);
        }
    }
    foreach ( QObject* item, AllSquares) {
        ((SquareWidget*)item)->deleteLater();
    }

    AllSquares.clear();
    for (int row = 0; row < fieldSize; ++row) {
        for (int col = 0; col < fieldSize; ++col) {
            bool isMarked = std::find(markedPositions.begin(), markedPositions.end(), std::make_pair(row, col)) != markedPositions.end();
            SquareWidget* square = new SquareWidget(this, isMarked, this);
            AllSquares.push_back(square);
            ui->gridLayout->addWidget(square, row, col, Qt::AlignCenter);
        }
    }
}
void MainWindow::StartGame(){

    ui->labelState->setText("Game started ");

    foreach ( QObject* item, AllSquares) {
        ((SquareWidget*)item)->HideColor();
        timer->stop();
    }
}

void MainWindow::PreGame(){
    if(timer->isActive())
      {
        StartGame();
    }

}

void MainWindow::UserClick(bool isMarked){
    if (isMarked){
        UserTrueCount++;

        if (UserTrueCount==level){
            ui->labelState->setText("Win");
            ui->labelState->setStyleSheet("background-color: rgb(0, 170, 255) ;"
                                          "color: rgb(0, 0, 0);"
                                          "qproperty-alignment: AlignCenter;"
                                          "font: 16pt \"Segoe UI\";");

            level++;
            ui->startButton->click();

        }

    } else{

        ui->labelState->setText("Lose");
        ui->labelState->setStyleSheet("background-color: rgb(255, 0, 0);"
                                      "color: rgb(0, 0, 0);"
                                      "qproperty-alignment: AlignCenter;"
                                      "font: 16pt \"Segoe UI\";");
        if(recordLevel<level){
        recordLevel=level;
        }
        ui->labelLevelRecord->setText(QString::number(recordLevel));
        if(level>1){
        level--;
        }
        foreach ( QObject* item, AllSquares) {
            ((SquareWidget*)item)->RevealColor();

        }
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}

