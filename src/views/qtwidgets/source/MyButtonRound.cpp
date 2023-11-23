#include "MyButtonRound.h"
#include <QPaintEvent>

MyButtonRound::MyButtonRound(QObject *parent)
{
	setMinimumSize(50, 50);
	setMaximumSize(500, 500);
	setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
}

MyButtonRound::~MyButtonRound()
{
}

void MyButtonRound::initStyleOption(QStyleOptionButton *style) const
{
	QPushButton::initStyleOption(style);
}

void MyButtonRound::paintEvent(QPaintEvent *event)
{
	QPushButton::paintEvent(event);

	QRegion region(this->geometry(), QRegion::Ellipse);
	setMask(region);
}
