#ifndef GameModel_H
#define GameModel_H

#include "iuimodel.h"
#include <memory>

class MainWindowModel;
class IGameView;

class GameModel : IUiModel
{
public:
	explicit GameModel(MainWindowModel* parent);
	~GameModel();

	IView* getView() override;
	void clickedBack() override;

private:
	void createView();
	MainWindowModel* parent_;
	std::unique_ptr<IGameView> view_;
};

#endif	  // GameModel_H
