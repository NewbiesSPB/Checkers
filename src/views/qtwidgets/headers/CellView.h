#ifndef CellView_H
#define CellView_H

#include <QGraphicsScene>

class CellView : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit CellView(Qt::GlobalColor color, QObject *parent = nullptr);
	virtual ~CellView();

private:
	void drawBackground(QPainter *painter, const QRectF &rect) override;

	Qt::GlobalColor color_;
};

#endif	  // CellView_H
