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
    bool insert(Node *node);
    int  calcHeight();
    void checkEqual(Node *node, bool &isEqual);
    bool isEqual(Node *node);
    void checkAVL(bool &isAVL);
    bool isAVL();
    void checkExists(Node *node, bool &exists);
    bool exists(Node *node);

    // for Debug
    void print();

    // for Graphics
    Node *parent;
    QVector2D position;
    QGraphicsLineItem *edge;
    QGraphicsEllipseItem *circle;
    QGraphicsTextItem *number;

public slots:
    void move();

};

#endif // NODE_H
