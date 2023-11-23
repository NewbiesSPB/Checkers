#include "BoardView.h"
#include <QPainter>

BoardView::BoardView(QObject *parent)
{
}

BoardView::~BoardView()
{

}

void BoardView::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setRenderHint(QPainter::Antialiasing);
	int tempRow	   = 0;
	int tempColumn = 0;
	QString letter = "ABCDEFGH";
	QString number = "12345678";
	QFont font	   = painter->font();
	font.setPointSize(this->sceneRect().width() / board_size_ / 3);
	for (int row = 0; row < board_size_; row++)
	{
		for (int column = 0; column < board_size_; column++)
		{
			if (!row && (column != 0))
			{
				painter->setBrush(Qt::black);
				painter->setFont(font);
				painter->drawText(tempRow,
								  tempColumn,
								  this->sceneRect().width() / board_size_,
								  this->sceneRect().width() / board_size_,
								  Qt::AlignCenter,
								  letter.at(column - 1));
			}
			else if (!column && (row != 0))
			{
				painter->setBrush(Qt::black);
				painter->setFont(font);
				painter->drawText(tempRow,
								  tempColumn,
								  this->sceneRect().width() / board_size_,
								  this->sceneRect().width() / board_size_,
								  Qt::AlignCenter,
								  number.at(row - 1));
			}
			else if ((row + column) & 1)
			{
				painter->setBrush(Qt::gray);
				painter->drawRect(tempRow,
								  tempColumn,
								  this->sceneRect().width() / board_size_,
								  this->sceneRect().width() / board_size_);
			}
			else if (row != 0)
			{
				painter->setBrush(Qt::black);
				painter->drawRect(tempRow,
								  tempColumn,
								  this->sceneRect().width() / board_size_,
								  this->sceneRect().width() / board_size_);
			}
			tempRow += this->sceneRect().width() / board_size_;
		}
		tempRow = 0;
		tempColumn += this->sceneRect().width() / board_size_;
	}

	Q_UNUSED(rect);
}
