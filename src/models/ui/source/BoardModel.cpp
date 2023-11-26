#include "BoardModel.h"

#include "BoardView.h"

BoardModel::BoardModel(GameModel* parent) : parent_(parent)
{

}

BoardModel::~BoardModel()
{

}

BoardView* BoardModel::getView()
{
	return view_->getView();
}

void BoardModel::createView()
{
	view_ = std::make_unique<BoardView>();
}
