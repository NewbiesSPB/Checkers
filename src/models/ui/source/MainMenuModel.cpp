#include "MainMenuModel.h"
#include "MainMenuView.h"

MainMenuModel::MainMenuModel(MainWindowModel *parent) : parent_(parent)
{
	view_ = std::make_unique<MainMenuView>(this);
}

MainMenuModel::~MainMenuModel()
{
}

IView *MainMenuModel::getView()
{
	return view_->getView();
}

void MainMenuModel::createView()
{
}

void MainMenuModel::clickedExit()
{
}

void MainMenuModel::clickedLaunchLanGame()
{
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
