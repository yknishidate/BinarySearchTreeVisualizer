#include "graphicsview.h"

GraphicsView::GraphicsView(GraphicsScene *scene)
    : QGraphicsView (scene)
{

}

void GraphicsView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        emit deletePressed(true);
    }
}
