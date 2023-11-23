#ifndef BoardView_H
#define BoardView_H

#include <QGraphicsScene>

class BoardView : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit BoardView(QObject *parent = nullptr);
	virtual ~BoardView();

private:
	void drawBackground(QPainter *painter, const QRectF &rect) override;

	uint8_t board_size_{9};
};

#endif	  // BoardView_H
