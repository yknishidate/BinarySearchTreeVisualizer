#include "graphicsscene.h"
#include <QtWidgets>

GraphicsScene::GraphicsScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    lineWidth = 4;
    circleDiameter = 100;
    pen = QPen(Qt::black, lineWidth);
    font = QFont("Segoe UI", 46);
}

void GraphicsScene::addNode(Node *node)
{
    // Circle
    node->circle = new QGraphicsEllipseItem(0, 0, circleDiameter, circleDiameter);
    node->circle->setPos(node->position.x(), node->position.y());
    node->circle->setPen(pen);
    node->circle->setFlags(QGraphicsItem::ItemIsSelectable);

    // Number
    node->number = new QGraphicsTextItem(QString::number(node->num), node->circle);
    node->number->setFont(font);
    node->number->setDefaultTextColor(Qt::black);
    node->number->setTextWidth(circleDiameter);

    // Align Center
    QTextBlockFormat format;
    format.setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    QTextCursor cursor = node->number->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    cursor.clearSelection();
    node->number->setTextCursor(cursor);

    addItem(node->circle);
}

void GraphicsScene::addEdge(Node *node)
{
    if(node->parent==nullptr) return;
    QVector2D a((node->position.x()+circleDiameter/2), (node->position.y()+circleDiameter/2));
    QVector2D b((node->parent->position.x()+circleDiameter/2), (node->parent->position.y()+circleDiameter/2));

    float dx = (node->parent->position.x()) - (node->position.x());
    float dy = (node->parent->position.y()) - (node->position.y());
    QVector2D dir(dx, dy);
    dir.normalize();

    a += dir*circleDiameter/2;
    b -= dir*circleDiameter/2;

    node->edge = new QGraphicsLineItem(a.x(), a.y(), b.x(), b.y());
    node->edge->setPen(pen);
    this->addItem(node->edge);
}

void GraphicsScene::drawTree(BinarySearchTree *tree)
{
    int space = (circleDiameter*1.1) * pow(2,tree->height()-1);
//    int totalW = circleDiameter*1.1;
//    for(int i=0; i<tree->height(); i++){
//        totalW *=
//    }
    drawNode(tree->getRoot(), space);
}

void GraphicsScene::drawNode(Node *node, int space)
{
    addNode(node);
    addEdge(node);
    if(node->left != nullptr){
        node->left->position = QVector2D(node->position.x()-space/2, node->position.y()+150);
        drawNode(node->left, space/2);
    }
    if(node->right != nullptr){
        node->right->position = QVector2D(node->position.x()+space/2, node->position.y()+150);
        drawNode(node->right, space/2);
    }
}
