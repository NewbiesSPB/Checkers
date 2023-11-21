#ifndef MainMenuModel_H
#define MainMenuModel_H

#include "iuimodel.h"
#include <memory>
class MainWindowModel;
class MainMenuView;

class MainMenuModel : public IUiModel
{
public:
	explicit MainMenuModel(MainWindowModel* parent);
	virtual ~MainMenuModel();

	IView* getView() override;

	void createView();
	void clickedExit();
	void clickedLaunchLanGame();
	void clickedLaunchAIGame();
	void clickedShowSettings();
	void clickedShowStatistics();

private:
	MainWindowModel* parent_;
	std::unique_ptr<MainMenuView> view_;
};

#endif	  // MainMenuModel_H
