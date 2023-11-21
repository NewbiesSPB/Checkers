#include "MyButtonRect.h"
#include <QPaintEvent>

MyButtonRect::MyButtonRect(QObject *parent)
{
	setMinimumSize(50, 50);
	setMaximumSize(500, 500);
	setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
}

void MyButtonRect::initStyleOption(QStyleOptionButton *style) const
{
	QPushButton::initStyleOption(style);
}

void MyButtonRect::paintEvent(QPaintEvent *event)
{
	QPushButton::paintEvent(event);
}
