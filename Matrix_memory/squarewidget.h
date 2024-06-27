#ifndef SQUAREWIDGET_H
#define SQUAREWIDGET_H

#include <mainwindow.h>

#include <QColor>
#include <QPushButton>
#include <QTimer>

class SquareWidget : public QPushButton {

public:
    SquareWidget(QWidget* parent, bool isMarked_, MainWindow* master_) : QPushButton(parent) {
        setFixedSize(80, 80);

        if(isMarked_)
        {setStyleSheet("background-color: rgb(0, 0, 255);");}
            else
        { setStyleSheet("background-color:rgb(192, 192, 192);");}
        isMarked= isMarked_;
        master=master_;
        connect(this, &QPushButton::clicked, this, &SquareWidget::handleClick);

    }
    bool isMarked;

     void setColor(const QColor& color);
    void HideColor();
     void RevealColor();
    void handleClick();
private:
     int col;
    int row;
     MainWindow* master;
};

#endif // SQUAREWIDGET_H
