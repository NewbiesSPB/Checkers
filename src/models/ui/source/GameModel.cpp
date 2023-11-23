#include "GameModel.h"
#include "GameView.h"
#include "MainWindowModel.h"

GameModel::GameModel(MainWindowModel *parent) : parent_(parent)
{
	createView();
}

GameModel::~GameModel()
{
}

IView *GameModel::getView()
{
	return view_->getView();
}

void GameModel::clickedBack()
{
	// TODO some logic to end game...
	parent_->showMainMenu();
}

void GameModel::createView()
{
	view_ = std::make_unique<GameView>(this);
}
