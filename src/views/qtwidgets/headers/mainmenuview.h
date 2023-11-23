#ifndef MainMenuView_H
#define MainMenuView_H

#include "IView.h"
#include <QWidget>

class MainMenuModel;
class MyButtonRect;
class MyButtonRound;

class MainMenuView : public QWidget
, public IMainMenuView
{
	Q_OBJECT
public:
	explicit MainMenuView(MainMenuModel* model, QWidget* parent = nullptr);
	virtual ~MainMenuView();

	IView* getView() override;

public slots:
	void clickedExit() override;
	void clickedLaunchLanGame() override;
	void clickedLaunchAIGame() override;
	void clickedShowSettings() override;
	void clickedShowStatistics() override;

private:
	void constructWindow();
	MainMenuModel* model_;

	MyButtonRound* button_exit_;
	MyButtonRect* button_launchLanGame_;
	MyButtonRect* button_launchAIGame_;
	MyButtonRect* button_showSettings_;
	MyButtonRect* button_showStatistics_;
};

#endif	  // MainMenuView_H
