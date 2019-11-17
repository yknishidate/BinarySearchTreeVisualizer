#include "graphicscircle.h"
#include "node.h"

GraphicsCircle::GraphicsCircle(qreal x, qreal y, qreal width, qreal height)
    :QGraphicsEllipseItem(x, y, width, height)
{

}

void GraphicsCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << "Selected:" << this->parent->num;
    }
}

void GraphicsCircle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        qDebug() << "DeleteKey";
    }
}
