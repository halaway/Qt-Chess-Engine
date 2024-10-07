#include "window.h"
#include "board.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPainter>
#include <QLabel>
#include <QMap>
#include <QPixmap>
#include <QMouseEvent>
#include <QPushButton>
#include <cstdlib>
#include <deque>

/*
 *
 * WINDOW DECLARATION
 * Handling board creation and Logic
 *
 */


window::window(QWidget *parent)
    : QWidget(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this))
{
    // Setting up the View
    SetUpView();

    // Setting up the Scene 
    SetUpScene();

    // Setting the Window Attributes
    SetUpWindow();

    // QMap Containing Images ang File paths
    pieceImages = FilePath();

    RenderBoard();
}

// Initializing Scene
void window::SetUpView(){
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setGeometry(0, 0, 400, 400);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

// Initializing Scene
void window::SetUpScene(){
     scene->setSceneRect(0, 0, 400, 400);
}

// Initializing Window Attributes
void window::SetUpWindow(){
    setFixedSize(400, 400);
    this->setWindowTitle("Chess Engine");
}

// Rendering our Board and Pieces
void window::RenderBoard()
{

    // Setting Board Attributes
    const int boardSize = 8;
    const int squareSize = 50;
    const QColor color1 = QColor(255, 255, 255);
    const QColor color2 = QColor(118, 188, 104); // 118, 188, 104 || 128, 141, 96

    // Board
    auto init_board = inner_board.board;

    scene->clear();

    for (int row = 0; row < boardSize; ++row)
    {
        for (int col = 0; col < boardSize; ++col)
        {
            QColor squareColor = ((row + col) % 2 == 0) ? color1 : color2;
            QBrush brush(squareColor);
            QPen pen(Qt::black);
            QRectF rect(col * squareSize, row * squareSize, squareSize, squareSize);

            // Draw the square
            scene->addRect(rect, pen, brush);

            const Board::BoardPiece &piece = init_board[row][col];
            if (!piece.is_empty)
            {
                std::string imageKey = piece.p_name + (piece.is_opponent ? "_black" : "_white");
                QPixmap piecePixmap = pieceImages.value(imageKey.c_str());
                if (!piecePixmap.isNull())
                {
                    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(piecePixmap);
                    item->setPos(col * squareSize, row * squareSize);
                    item->setScale(static_cast<double>(squareSize) / piecePixmap.width());
                    scene->addItem(item);
                }
            }
        }
    }

    QPen gridPen(Qt::black, 1, Qt::SolidLine);
    for (int i = 0; i <= boardSize; ++i)
    {
        scene->addLine(i * squareSize, 0, i * squareSize, boardSize * squareSize, gridPen);
        scene->addLine(0, i * squareSize, boardSize * squareSize, i * squareSize, gridPen);
    }
}

// Storing File Paths into QMap
QMap<QString, QPixmap> window::FilePath()
{
    // Setting QMap and attributes to iterate through
    QMap<QString, QPixmap> p_images;
    QStringList pieceTypes = {"rook", "knight", "bishop", "queen", "king", "pawn"};
    QStringList colors = {"black", "white"};

    // Iterating available colors
    for (const QString &color : colors)
    {
        // Iterating available peices
        for (const QString &piece : pieceTypes)
        {
            QString key = QString("%1_%2").arg(piece).arg(color);
            QString path = QString(":/imageFolder/%1_%2.png").arg(((piece == "knight") ? "horse" : piece)).arg(color);

            // Assigning piece name to file path
            p_images[key] = QPixmap(path);
        }
    }

    return p_images;
}

// Initializing Random Seed
void window::initializeRandomSeed()
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned>(time(NULL)));
        seeded = true;
    }
}

// Creating Moves based on seed generation
std::pair<int, int> window::CreateMove()
{

    int s_xpos = rand() % 8;
    int s_ypos = rand() % 8;

    return std::pair<int, int>{s_xpos, s_ypos};
}

// Creating a Valid Opponent Move
void window::OpponentMove()
{
    initializeRandomSeed();

    std::pair<int, int> startMove;
    std::pair<int, int> endMove;
    bool validMoveFound = false;

    while (!validMoveFound)
    {
        startMove = CreateMove();
        endMove = CreateMove();

        if (inner_board.OpponentPosition(startMove, endMove) &&
            inner_board.board[startMove.first][startMove.second].is_opponent == true &&
            inner_board.board[endMove.first][endMove.second].is_empty == true)
        {
            validMoveFound = true;

            inner_board.board[endMove.first][endMove.second] = inner_board.board[startMove.first][startMove.second];

            inner_board.board[startMove.first][startMove.second] = Board::BoardPiece{true, "-", true};

            // qDebug() << startMove.first << " " << startMove.second;
            // qDebug() << endMove.first << " " << endMove.second;

            //inner_board.Position_Piece(startMove, endMove);
        }
    }

    return;
}

// Handling Click Events
void window::mousePressEvent(QMouseEvent *event)
{
    int cellSize = 50;

    int col = event->x() / cellSize;
    int row = event->y() / cellSize;

    // Insert into deque
    positions.push_back(std::pair<int, int>{row, col});

    // qDebug() << row << " " << col;

    // Check if there are exactly two positions
    if (positions.size() == 2)
    {
        auto firstPos = positions.front();
        auto secondPos = positions.back();

        // Check if the two positions are different
        if (firstPos != secondPos)
        {
            // Check move is valid using inner_board
            if (inner_board.Position_Piece(firstPos, secondPos))
            {
                // qDebug() << "Move is valid";

                // Generating Move
                OpponentMove();

                // Creating Board
                RenderBoard();

                // Clearing Deque of Moves
                positions.clear();
            }
            else
            {
                positions.clear();
            }
        }
        else
        {

            positions.clear();
        }
    }

    return;
}
