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
    printConsole(ui->lineEdit->text(), true);
    // Process Sequence
    QStringList strList = ui->lineEdit->text().split(" ");
    for (int i=0; i<strList.size(); i++)
        if(strList[i] != "") nums.append(strList[i].toInt());

    BinarySearchTree* tree = new BinarySearchTree(nums);
    scene->drawTree(tree);
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
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

void MainWindow::on_actionSave_triggered()
{
    QPixmap pixMap = view->grab();
    QString filter = "Image (*.png)";
    QString fileName = QFileDialog::getSaveFileName(this, "", "Untitled.png", tr("Images (*.png)"));
    pixMap.save(fileName);
}
