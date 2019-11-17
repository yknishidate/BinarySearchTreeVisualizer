#include "console.h"

Console::Console(QObject *parent)
{

}

void Console::printConsole(QString arg, bool br)
{
    QTextCursor prev_cursor = textCursor();
    moveCursor (QTextCursor::End);
    insertPlainText (arg);
    if(br) insertPlainText("\n");
}
void Console::printConsole(int arg, bool br)
{
    QTextCursor prev_cursor = textCursor();
    moveCursor (QTextCursor::End);
    insertPlainText(QString::number(arg));
    if(br) insertPlainText("\n");
}
void Console::printConsole(float arg, bool br)
{
    QTextCursor prev_cursor = textCursor();
    moveCursor (QTextCursor::End);
    insertPlainText(QString::number(arg));
    if(br) insertPlainText("\n");
}
void Console::printError(QString arg)
{
    setTextColor("#ff4444");
    append(arg);
    setTextColor(Qt::white);
    insertPlainText("\n");
}
