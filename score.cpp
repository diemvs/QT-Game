#include "score.h"

#include <QFont>
#include <QTextEdit>
#include <QString>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    setPlainText(QString ("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increse(){
    score++;
    setPlainText(QString ("Score: ")+ QString::number(score));
}

int Score::getScore(){
    return score;
}
