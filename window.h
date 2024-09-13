#ifndef WINDOW_H
#define WINDOW_H

#include "board.h"
#include <QSharedDataPointer>
#include <QWidget>
#include <vector>
#include <string>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <deque>
#include <QMap>





class QPushButton;
class window : public QWidget
{

public:
    explicit window(QWidget *parent = 0);
    void RenderBoard();
    void OpponentMove();
    void initializeRandomSeed();
    std::pair<int, int> CreateMove();
    QMap<QString, QPixmap> FilePath();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QPushButton *m_button;
    QGraphicsScene *scene;
    QGraphicsView *view;
    std::deque< std::pair<int, int>> positions;
    Board inner_board;

};

#endif // WINDOW_H
