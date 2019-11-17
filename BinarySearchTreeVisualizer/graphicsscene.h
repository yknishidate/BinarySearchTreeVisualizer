#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "node.h"
#include "binarysearchtree.h"
//#include "graphicscircle.h"

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GraphicsScene(QMenu *itemMenu, QObject *parent = 0);
    void addNode(Node *node);
    void addEdge(Node *node);
    void drawTree(BinarySearchTree *tree);
    void drawNode(Node *node, int space);
    int getGraphWidth(BinarySearchTree *tree);
    int getGraphHeight(BinarySearchTree *tree);

private:
    int lineWidth;
    int circleDiameter;
    int stepHeight = 150;
    QPen pen;
    QFont font;
    QBrush brush;
};

#endif // GRAPHICSSCENE_H
