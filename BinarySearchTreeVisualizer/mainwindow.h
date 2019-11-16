#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicsscene.h"
#include "binarysearchtree.h"

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

private slots:
    void on_generateTreePushButton_clicked();

    void on_clearPushButton_clicked();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QMenu *itemMenu;
    GraphicsScene *scene;
    QGraphicsView *view;

    QList<int> nums;
};

#endif // MAINWINDOW_H
