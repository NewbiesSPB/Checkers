#ifndef MyButtonRect_H
#define MyButtonRect_H

#include <QPushButton>

class MyButtonRect : public QPushButton
{
	Q_OBJECT
public:
	explicit MyButtonRect(QObject* parent = nullptr);
	virtual ~MyButtonRect();

	void initStyleOption(QStyleOptionButton* style) const override;
	void paintEvent(QPaintEvent* event) override;

private:
	QStyleOptionButton* style_;

signals:
};

#endif	  // MyButtonRect_H
