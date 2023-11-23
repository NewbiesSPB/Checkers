#ifndef MainMenuModel_H
#define MainMenuModel_H

#include "iuimodel.h"
#include <memory>
class MainWindowModel;
class IMainMenuView;

class MainMenuModel : public IUiModel
{
public:
	explicit MainMenuModel(MainWindowModel* parent);
	virtual ~MainMenuModel();

	IView* getView() override;
	void clickedBack() override;

	void clickedLaunchLanGame();
	void clickedLaunchAIGame();
	void clickedShowSettings();
	void clickedShowStatistics();

private:
	void createView();

	MainWindowModel* parent_;
	std::unique_ptr<IMainMenuView> view_;
};

#endif	  // MainMenuModel_H
