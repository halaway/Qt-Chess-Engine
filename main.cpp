#include "mainwindow.h"
#include "board.h"
#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QApplication>
#include "window.h"
#include <iostream>
#include <string>

#include <fstream>
#include <QFile>
#include <QIODevice>
#include <QDebug>

int main(int argc, char *argv[])
{



    QApplication app (argc, argv);
    window Window;
    Window.show();
    return app.exec();


    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // Board b;
    // b.Print();
    // std::cout<<""<<std::endl;


    // std::pair<int, int> start = {6,0};
    // std::pair<int, int> end = {1,5};
    // // std::pair<int, int> other = {3,1};
    // // std::pair<int, int> other2 = {1,2};

    // b.Position_Piece(start, end);
    // // b.Position_Piece(end, other);
    // // b.Position_Piece(other, other2);
    // b.Print();




    //return a.exec();
}
