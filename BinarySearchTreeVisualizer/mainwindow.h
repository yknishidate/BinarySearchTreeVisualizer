#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicsscene.h"
#include "binarysearchtree.h"
#include "graphicsview.h"

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    template <class T> void printConsole(T arg, bool br = false);
    void printError(QString arg);
    bool processNumberSequence();

private slots:
    void on_generateTreePushButton_clicked();

    void on_clearPushButton_clicked();

    void on_actionSave_triggered();

    void on_insertNodePushButton_clicked();

    void deletePressed(bool arg);

private:
    Ui::MainWindow *ui;
    QMenu *itemMenu;
    GraphicsScene *scene;
    GraphicsView *view;
    BinarySearchTree* tree;
    QList<int> nums;
};

#endif // MAINWINDOW_H
