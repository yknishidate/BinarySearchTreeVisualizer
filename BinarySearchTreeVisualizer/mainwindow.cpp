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

    tree = nullptr;
    firstRect = scene->sceneRect();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generateTreePushButton_clicked()
{
    scene->clear();
    nums.clear();

    // Get Sequence
    printConsole("Number Sequence: ");
    QString str = ui->lineEdit->text();
    if(str==""){
        printConsole("Empty", true);
        return;
    }
    printConsole(str, true);

    // Process Sequence
    QStringList strList = str.split(" ");
    for (int i=0; i<strList.size(); i++)
        if(strList[i] != "") nums.append(strList[i].toInt());

    delete(tree);
    tree = new BinarySearchTree(nums);
    scene->drawTree(tree);

    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    qDebug() << scene->sceneRect();
}

void MainWindow::on_clearPushButton_clicked()
{
    clearAllData();
}

void MainWindow::on_actionSave_triggered()
{
    QPixmap pixMap = view->grab();
    QString fileName = QFileDialog::getSaveFileName(this, "", "Untitled.png", tr("Images (*.png)"));
    if(fileName=="") return;
    pixMap.save(fileName);
    printConsole("Saved", true);
}

void MainWindow::on_insertNodePushButton_clicked()
{
    ///// Animation /////
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
//    timer->start();
    ////////////////////

    int number = ui->spinBox->value();
    if(tree!=nullptr){
        if(tree->root->insert(new Node(number)) == false){
            printConsole(number);
            printConsole(" already exists", true);
            return;
        }
        nums.append(number);
    }
    else{
        nums.append(number);
        tree = new BinarySearchTree(nums);
    }
    scene->clear();
    scene->drawTree(tree);
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    printConsole("Inserted: ");
    printConsole(number, true);
}

void MainWindow::clearAllData()
{
    delete(view);
    delete(scene);
    delete(tree); tree = nullptr;
    nums.clear();

    scene = new GraphicsScene(itemMenu, this);
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("QGraphicsView { background-color : #ffffff; }");
    view->setMinimumSize(400, 400);
    ui->gridLayout->addWidget(view);

    printConsole("Cleared", true);
}


template<class T>
void MainWindow::printConsole(T arg, bool br)
{
    ui->console->printConsole(arg, br);
}
