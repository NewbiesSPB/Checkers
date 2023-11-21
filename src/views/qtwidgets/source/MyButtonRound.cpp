#include "MyButtonRound.h"
#include <QPaintEvent>

MyButtonRound::MyButtonRound(QObject *parent)
{
	setMinimumSize(50, 50);
	setMaximumSize(500, 500);
	setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
}

void MyButtonRound::initStyleOption(QStyleOptionButton *style) const
{
	QPushButton::initStyleOption(style);
}

void MyButtonRound::paintEvent(QPaintEvent *event)
{
	QPushButton::paintEvent(event);

	QRegion region(event->rect(), QRegion::Ellipse);
	setMask(region);
}
