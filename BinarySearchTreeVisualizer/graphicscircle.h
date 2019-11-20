#ifndef GRAPHICSCIRCLE_H
#define GRAPHICSCIRCLE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

class Node;

class GraphicsCircle : public QGraphicsEllipseItem
{
public:
    GraphicsCircle(qreal x, qreal y, qreal width, qreal height);
    ~GraphicsCircle();

    Node *parent;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // GRAPHICSCIRCLE_H
