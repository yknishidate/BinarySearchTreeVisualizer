#ifndef NODE_H
#define NODE_H

#include <QtDebug>
#include <QVector2D>
#include <QGraphicsItem>
#include "graphicscircle.h"

class Node
{
public:
    int num;
    Node *left, *right;

    Node(int num);
    bool operator==(const Node &node);
    bool operator!=(const Node &node);
    bool insert(Node *node);
    bool remove(Node *node);

    int  calcHeight();
    bool isEqual(Node *node);
    bool isAVL();
    bool exists(Node *node);


    // Utility
    Node *getMax();
    Node *getMaxParent();
    bool isLeaf();
    bool hasOneChild();
    bool hasTwoChild();

    // for Debug
    void print();

    // for Graphics
    QVector2D position;
    QGraphicsLineItem *edge;
    QGraphicsLineItem *leftEdge;
    QGraphicsLineItem *rightEdge;
    GraphicsCircle *circle;
    QGraphicsTextItem *number;

    // for Other Tree Type
//    bool insertCompleteBST(Node *node);

public slots:
    void move();

};

#endif // NODE_H
