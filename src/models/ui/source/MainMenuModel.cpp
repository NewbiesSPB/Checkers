#include "MainMenuModel.h"
#include "MainMenuView.h"
#include "MainWindowModel.h"

MainMenuModel::MainMenuModel(MainWindowModel *parent) : parent_(parent)
{
	createView();
}

MainMenuModel::~MainMenuModel()
{
}

IView *MainMenuModel::getView()
{
	return view_->getView();
}

void MainMenuModel::clickedBack()
{
	parent_->exit();
}

void MainMenuModel::createView()
{
	view_ = std::make_unique<MainMenuView>(this);
}

void MainMenuModel::clickedLaunchLanGame()
{
	parent_->launchLanGame();
}

void MainMenuModel::clickedLaunchAIGame()
{
}

void MainMenuModel::clickedShowSettings()
{
}

void MainMenuModel::clickedShowStatistics()
{
}
