 #include "squarewidget.h"
\



void SquareWidget::setColor(const QColor& color) {
    setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                      .arg(color.red())
                      .arg(color.green())
                      .arg(color.blue()));
}
void SquareWidget::handleClick() {
    master->PreGame();
    if (isMarked){
        this->setColor(QColor(144, 238, 144));}
    else {
        this->setColor(QColor("Red"));
    };
    this->setDisabled(true);
    master->UserClick(isMarked);

}
void SquareWidget::HideColor(){
    setColor(QColor(192, 192, 192));
}
void SquareWidget::RevealColor(){
    if(isMarked && isEnabled() ){
     setColor(QColor(255, 140, 0));
    }
    this->setDisabled(true);
}
