#include "graphicscircle.h"
#include "node.h"

GraphicsCircle::GraphicsCircle(qreal x, qreal y, qreal width, qreal height)
    :QGraphicsEllipseItem(x, y, width, height)
{

}

GraphicsCircle::~GraphicsCircle()
{
//    qDebug() << "GraphicsCircle deleted";
}

void GraphicsCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << "Selected(GraphicsCircle::mousePressEvent):" << this->parent->num;
    }
}

void GraphicsCircle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        qDebug() << "DeleteKey";
    }
}
