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
    nums.clear();
    printConsole("Number Sequence: ");
    printConsole(ui->lineEdit->text(), true);
    // Process Sequence
    QStringList strList = ui->lineEdit->text().split(" ");
    for (int i=0; i<strList.size(); i++)
        if(strList[i] != "") nums.append(strList[i].toInt());


    BinarySearchTree* tree = new BinarySearchTree(nums);
    scene->drawTree(tree);

//    int treeRectSize = qMax(scene->getGraphWidth(tree), scene->getGraphHeight(tree));
//    int width = scene->getGraphWidth(tree);
//    scene->setSceneRect(-2, -2, +width/2 - 50 +4, scene->getGraphHeight(tree)+4);

    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    qDebug() << scene->sceneRect();
}

template<class T>
void MainWindow::printConsole(T arg, bool br)
{
    ui->console->printConsole(arg, br);
}

void MainWindow::on_clearPushButton_clicked()
{
    delete(view);
    delete(scene);
    scene = new GraphicsScene(itemMenu, this);
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("QGraphicsView { background-color : #ffffff; }");
    view->setMinimumSize(400, 400);
    ui->gridLayout->addWidget(view);
    printConsole("Cleared", true);
}

void MainWindow::on_actionSave_triggered()
{
    QPixmap pixMap = view->grab();
    QString filter = "Image (*.png)";
    QString fileName = QFileDialog::getSaveFileName(this, "", "Untitled.png", tr("Images (*.png)"));
    if(fileName=="") return;
    pixMap.save(fileName);
    printConsole("Saved", true);
}
