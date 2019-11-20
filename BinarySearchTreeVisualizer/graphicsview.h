#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include "graphicsscene.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(GraphicsScene *scene);
protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void deletePressed();
};

#endif // GRAPHICSVIEW_H
