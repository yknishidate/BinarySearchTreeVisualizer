#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets>

class Console : public QTextEdit
{
public:
    Console(QObject *parent = 0);
    void printConsole(QString arg, bool br = false);
    void printConsole(int arg, bool br = false);
    void printConsole(float arg, bool br = false);
    void printError(QString arg);
};

#endif // CONSOLE_H
