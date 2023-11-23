#include "GameView.h"
#include "BoardView.h"
#include "GameModel.h"
#include "MyButtonRound.h"

#include <QBoxLayout>
#include <QGraphicsView>

GameView::GameView(GameModel *model, QWidget *parent) : model_(model)
{
	constructWindow();
}

GameView::~GameView()
{
}

IView *GameView::getView()
{
	return this;
}

void GameView::clickedBack()
{
	model_->clickedBack();
}

void GameView::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	if (scene_view_->size().height() > scene_view_->size().width())
	{
		int size = scene_view_->size().width() - (scene_view_->size().width() % 9);
		board_view_->setSceneRect(0, 0, size, size);
	}
	else
	{
		int size = scene_view_->size().height() - (scene_view_->size().height() % 9);
		board_view_->setSceneRect(0, 0, size, size);
	}
}

void GameView::constructWindow()
{
	button_back_ = new MyButtonRound(this);
	connect(button_back_, &MyButtonRound::clicked, this, &GameView::clickedBack);
	button_back_->setText("back");

	QVBoxLayout *displayLayout = new QVBoxLayout(this);
	displayLayout->setSizeConstraint(QLayout::SetNoConstraint);
	displayLayout->setContentsMargins(0, 0, 0, 0);

	layout()->addWidget(button_back_);

	board_view_ = new BoardView(this);
	scene_view_ = new QGraphicsView();
	scene_view_->showMaximized();
	scene_view_->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	scene_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	scene_view_->setScene(board_view_);
	scene_view_->viewport()->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	layout()->addWidget(scene_view_);
	// displayLayout->addWidget(scene_view_->viewport());
}
