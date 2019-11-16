#ifndef NODE_H
#define NODE_H

#include <QtDebug>
#include <QVector2D>
#include <QGraphicsItem>

class Node
{
public:
    int num;
    Node *left, *right;

    Node(int num);
    bool operator==(const Node &node);
    bool operator!=(const Node &node);
    void insert(Node *node);
    int  calcHeight();
    void checkEqual(Node *node, bool &isEqual);
    void checkAVL(bool &isAVL);

    // for Debug
    void print();

    // for Graphics
    Node *parent;
    QVector2D position;
    QGraphicsLineItem *edge;
    QGraphicsEllipseItem *circle;
    QGraphicsTextItem *number;

};

#endif // NODE_H
