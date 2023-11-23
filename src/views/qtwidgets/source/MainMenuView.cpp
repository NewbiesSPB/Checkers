#include "MainMenuView.h"
#include "MainMenuModel.h"
#include "MyButtonRect.h"
#include "MyButtonRound.h"

#include <QBoxLayout>

MainMenuView::MainMenuView(MainMenuModel *model, QWidget *parent) : model_(model)
{
	constructWindow();
}

MainMenuView::~MainMenuView()
{
}

IView *MainMenuView::getView()
{
	return this;
}

void MainMenuView::clickedExit()
{
	model_->clickedBack();
}

void MainMenuView::clickedLaunchLanGame()
{
	model_->clickedLaunchLanGame();
}

void MainMenuView::clickedLaunchAIGame()
{
}

void MainMenuView::clickedShowSettings()
{
}

void MainMenuView::clickedShowStatistics()
{
}

void MainMenuView::constructWindow()
{
	button_exit_ = new MyButtonRound(this);
	connect(button_exit_, &MyButtonRect::clicked, this, &MainMenuView::clickedExit);
	button_exit_->setText("exit");

	button_launchLanGame_ = new MyButtonRect(this);
	connect(button_launchLanGame_, &MyButtonRect::clicked, this, &MainMenuView::clickedLaunchLanGame);
	button_launchLanGame_->setText("Lan game");

	button_launchAIGame_ = new MyButtonRect(this);
	connect(button_launchAIGame_, &MyButtonRect::clicked, this, &MainMenuView::clickedLaunchAIGame);
	button_launchAIGame_->setText("AI game");

	button_showSettings_ = new MyButtonRect(this);
	connect(button_showSettings_, &MyButtonRect::clicked, this, &MainMenuView::clickedShowSettings);
	button_showSettings_->setText("Settings");

	button_showStatistics_ = new MyButtonRect(this);
	connect(button_showStatistics_, &MyButtonRect::clicked, this, &MainMenuView::clickedShowStatistics);
	button_showStatistics_->setText("Statics");

	QVBoxLayout *displayLayout = new QVBoxLayout(this);
	displayLayout->setSizeConstraint(QLayout::SetNoConstraint);
	displayLayout->setContentsMargins(0, 0, 0, 0);

	displayLayout->addWidget(button_exit_);
	displayLayout->addStretch(1);

	displayLayout->addWidget(button_launchLanGame_);
	displayLayout->addStretch(1);

	displayLayout->addWidget(button_launchAIGame_);
	displayLayout->addStretch(1);

	displayLayout->addWidget(button_showSettings_);
	displayLayout->addStretch(1);

	displayLayout->addWidget(button_showStatistics_);
}
