#ifndef MyButtonRound_H
#define MyButtonRound_H

#include <QPushButton>

class MyButtonRound : public QPushButton
{
	Q_OBJECT
public:
	explicit MyButtonRound(QObject* parent = nullptr);
	void initStyleOption(QStyleOptionButton* style) const override;
	void paintEvent(QPaintEvent* event) override;

private:
	QStyleOptionButton* style_;

signals:
};

#endif	  // MyButtonRound_H
