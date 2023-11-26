#ifndef GameModel_H
#define GameModel_H

#include "iuimodel.h"
#include <memory>

class MainWindowModel;
class IGameView;
class BoardModel;

class GameModel : IUiModel
{
public:
	explicit GameModel(MainWindowModel* parent);
	~GameModel();

	IView* getView() override;
	void clickedBack() override;

private:
	void createView();
	void createBoardModel();

	MainWindowModel* parent_;
	std::unique_ptr<IGameView> view_;
	std::unique_ptr<BoardModel> board_model_;
};

#endif	  // GameModel_H
