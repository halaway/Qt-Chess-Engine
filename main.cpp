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

/**
 * @brief The entry point for the chess application.
 * Initializes the Qt application, creates the main window object,
 * and starts the event loop to display the window.
 */

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    window Window;
    Window.show();
    return app.exec();
}
