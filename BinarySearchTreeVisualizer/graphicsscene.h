#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "node.h"
#include "binarysearchtree.h"

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

private:
    std::vector<QGraphicsEllipseItem*> nodes;
    int lineWidth;
    int circleDiameter;
    QPen pen;
    QFont font;
};

#endif // GRAPHICSSCENE_H
