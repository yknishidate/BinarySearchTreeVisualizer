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
    view = new GraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("QGraphicsView { background-color : #ffffff; }");
    view->setMinimumSize(400, 400);
    ui->gridLayout->addWidget(view);

    tree = nullptr;
    firstRect = scene->sceneRect();

    // Connect
    connect(view, SIGNAL(deletePressed(bool)), this, SLOT(deletePressed(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////// Generate //////////
void MainWindow::on_generateTreePushButton_clicked()
{
    scene->clear();
    nums.clear();

    if(!processNumberSequence()) return;
    delete(tree);
    tree = new BinarySearchTree(nums);
    scene->drawTree(tree);

    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    printConsole("TreeHeight: ");
    printConsole(tree->height(), true);
}

////////// Clear //////////
void MainWindow::on_clearPushButton_clicked()
{
    delete(view);
    delete(scene);
    delete(tree); tree = nullptr;
    nums.clear();

    scene = new GraphicsScene(itemMenu, this);
    view = new GraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("QGraphicsView { background-color : #ffffff; }");
    view->setMinimumSize(400, 400);
    ui->gridLayout->addWidget(view);

    connect(view, SIGNAL(deletePressed(bool)), this, SLOT(deletePressed(bool)));

    printConsole("--- Cleared ---", true);
}

////////// Save //////////
void MainWindow::on_actionSave_triggered()
{
    QPixmap pixMap = view->grab();
    QString fileName = QFileDialog::getSaveFileName(this, "", "Untitled.png", tr("Images (*.png)"));
    if(fileName=="") return;
    pixMap.save(fileName);
    printConsole("Saved", true);
}

////////// Insert //////////
void MainWindow::on_insertNodePushButton_clicked()
{
    int number = ui->spinBox->value();
    if(tree!=nullptr){
        if(tree->root->insert(new Node(number)) == false){
            printError("ERROR: Already exists");
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

    printConsole("Inserted  : ");
    printConsole(number, true);
    printConsole("TreeHeight: ");
    printConsole(tree->height(), true);
}

////////// Delete //////////
void MainWindow::deletePressed(bool arg)
{
    // 派生クラスのポインタにキャスト
    GraphicsCircle *selectedCircle = dynamic_cast<GraphicsCircle*>( scene->selectedItems()[0] );
    Node *selectedNode = selectedCircle->parent;
    qDebug() << "Delete Node(Main)" << selectedNode->num;

    tree->remove(selectedNode);
    nums.removeOne(selectedNode->num);

    scene->clear();
    scene->drawTree(tree);
}

bool MainWindow::processNumberSequence()
{
    QString str = ui->lineEdit->text();
    QStringList strList = str.split(" ");

    for (int i=0; i<strList.size(); i++){
        bool ok;
        int num = strList[i].toInt(&ok);
        if(ok)
            nums.append(num);
        else {
            printError("ERROR: Please enter numbers or spaces");
            return false;
        }
    }

    if(nums.empty()){
        printError("ERROR: Number Sequence is empty");
        return false;
    }

    printConsole("Number Sequence: ");
    printConsole(str, true);
    return true;
}


template<class T>
void MainWindow::printConsole(T arg, bool br)
{
    ui->console->printConsole(arg, br);
}

void MainWindow::printError(QString arg)
{
    ui->console->printError(arg);
}
