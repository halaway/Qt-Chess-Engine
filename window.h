#ifndef WINDOW_H
#define WINDOW_H

#include "board.h"
#include <QWidget>
#include <vector>
#include <string>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <deque>
#include <QMap>

/*
 * Class: window
 *  Represents the main window for the chess application. Sets up 
 *  the graphical components such as the chessboard and pieces using QGraphicsView and QGraphicsScene.
 *  The class is responsible for initializing the scene, view, and board rendering logic, 
 *  as well as managing the display of chess pieces using a QMap of images.
 * */

class QPushButton;
class window : public QWidget
{

public:
    /**
     * @brief Construct a new window object
     * 
     * @param parent 
     */
    explicit window(QWidget *parent = 0);

    /**
     * @brief Sets Up the View object with rendering options and scroll bar policies.
     * 
     */
    void SetUpView();

    /**
     * @brief Configures the scene's geometry for the chessboard display.
     * 
     */
    void SetUpScene();

    /**
     * @brief Configures the Window with size and title properties.
     * 
     */
    void SetUpWindow();

    /**
     * @brief Renders the initial chessboard along with each piecce and the grid layout. 
     * 
     */
    void RenderBoard();

    /**
     * @brief Initializes the opponent move corresponding with an initial start and end position
     * 
     */
    void OpponentMove();

    /**
     * @brief Loads the chess piece images from file paths 
     * 
     * @return QMap<QString, QPixmap> 
     */
    QMap<QString, QPixmap> FilePath();

    void initializeRandomSeed();
    std::pair<int, int> CreateMove();

protected:
    /**
     * @brief Listens for sequential click events for storing and updating piece moves
     * 
     * @param event 
     */
    void mousePressEvent(QMouseEvent *event) override;

private:
    QPushButton *m_button;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Board inner_board;
    QMap<QString, QPixmap> pieceImages;
    std::deque<std::pair<int, int>> positions;
};

#endif // WINDOW_H
