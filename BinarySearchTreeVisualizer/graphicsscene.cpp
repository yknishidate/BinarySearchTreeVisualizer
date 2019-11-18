#include "graphicsscene.h"
#include "util.h"
#include <QtWidgets>

GraphicsScene::GraphicsScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    lineWidth = 5;
    circleDiameter = 100;
    pen = QPen(Qt::black, lineWidth);
    brush = QBrush(Qt::black);
    font = QFont("Acumin Pro", 50);
}

void GraphicsScene::addNode(Node *node)
{
    if(node==nullptr) return;
    // Circle
    node->circle = new GraphicsCircle(0, 0, circleDiameter, circleDiameter);
    node->circle->setPos(node->position.x(), node->position.y());
    node->circle->setPen(pen);
    node->circle->setFlags(QGraphicsItem::ItemIsSelectable);
    node->circle->parent = node;

    // Number
    node->number = new QGraphicsTextItem(QString::number(node->num), node->circle);
    node->number->setDefaultTextColor(Qt::black);
    int numDig = getNumDigits(node->num);
    if(numDig<=2) node->number->setFont(font);
    else          node->number->setFont(QFont("Acumin Pro", 50*2/numDig));

    // Align Center
    node->number->setTextWidth(circleDiameter);
    node->number->moveBy(0, (circleDiameter-node->number->boundingRect().height())/2 - 2);
    QTextBlockFormat format;
    format.setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    QTextCursor cursor = node->number->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    cursor.clearSelection();
    node->number->setTextCursor(cursor);

    addItem(node->circle);
}

void GraphicsScene::addLeftEdge(Node *node)
{
    if(node==nullptr || node->left==nullptr) return;

    QVector2D a((node->position.x()+circleDiameter/2), (node->position.y()+circleDiameter/2));
    QVector2D b((node->left->position.x()+circleDiameter/2), (node->left->position.y()+circleDiameter/2));

    float dx = (node->left->position.x()) - (node->position.x());
    float dy = (node->left->position.y()) - (node->position.y());
    QVector2D dir(dx, dy);
    dir.normalize();

    a += dir*circleDiameter/2;
    b -= dir*circleDiameter/2;

    node->leftEdge = new QGraphicsLineItem(a.x(), a.y(), b.x(), b.y());
    node->leftEdge->setPen(pen);
    this->addItem(node->leftEdge);
}

void GraphicsScene::addRightEdge(Node *node)
{
    if(node==nullptr || node->right==nullptr) return;

    QVector2D a((node->position.x()+circleDiameter/2), (node->position.y()+circleDiameter/2));
    QVector2D b((node->right->position.x()+circleDiameter/2), (node->right->position.y()+circleDiameter/2));

    float dx = (node->right->position.x()) - (node->position.x());
    float dy = (node->right->position.y()) - (node->position.y());
    QVector2D dir(dx, dy);
    dir.normalize();

    a += dir*circleDiameter/2;
    b -= dir*circleDiameter/2;

    node->rightEdge = new QGraphicsLineItem(a.x(), a.y(), b.x(), b.y());
    node->rightEdge->setPen(pen);
    this->addItem(node->rightEdge);
}

void GraphicsScene::drawTree(BinarySearchTree *tree)
{
    if(tree==nullptr) return;
    int height = tree->height();
    int space = (circleDiameter*1.1) * pow(2,height-1);

    drawNode(tree->getRoot(), space);
}

void GraphicsScene::drawNode(Node *node, int space)
{
    if(node==nullptr) return;

    addNode(node);
    if(node->left != nullptr){
        node->left->position = QVector2D(node->position.x()-space/2, node->position.y()+stepHeight);
        drawNode(node->left, space/2);
        addLeftEdge(node);
    }
    if(node->right != nullptr){
        node->right->position = QVector2D(node->position.x()+space/2, node->position.y()+stepHeight);
        drawNode(node->right, space/2);
        addRightEdge(node);
    }
}

int GraphicsScene::getGraphHeight(BinarySearchTree *tree)
{
    return stepHeight*tree->height() + circleDiameter;
}

int GraphicsScene::getGraphWidth(BinarySearchTree *tree)
{
    int graphicsWidth = 0;
    for(int i=-1; i<=tree->height()-2; i++)
        graphicsWidth += (circleDiameter*1.1) * pow(2, i);
    return 2*graphicsWidth + circleDiameter;
}
