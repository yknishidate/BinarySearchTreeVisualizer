#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("BinarySearchTree Visualizer"));
    setUnifiedTitleAndToolBarOnMac(true);

    // Setup GraphicsView
    scene = new GraphicsScene(itemMenu, this);
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("QGraphicsView { background-color : #ffffff; }");
    view->setMinimumSize(400, 400);
    ui->gridLayout->addWidget(view);

    // Setup TextEdit
    int fontWidth = QFontMetrics(ui->console->currentCharFormat().font()).averageCharWidth();
    ui->console->setTabStopWidth(4*fontWidth);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateTreePushButton_clicked()
{
    scene->clear();

    // Process Sequence
    QStringList strList = ui->lineEdit->text().split(" ");
    QList<int> nums;
    for (int i=0; i<strList.size(); i++)
        nums.append(strList[i].toInt());

    BinarySearchTree* tree = new BinarySearchTree(nums);
    tree->print(); // qDebug
    scene->drawTree(tree);
//    int width = 200, height = 200;
//    view->setFixedSize(width+2*view->frameWidth(), height+2*view->frameWidth());
//    view->scale(0.5, 0.5);
}

template<class T>
void MainWindow::printConsole(T arg, bool br)
{
    ui->console->printConsole(arg, br);
}

void MainWindow::on_clearPushButton_clicked()
{
    scene->clear();
}
