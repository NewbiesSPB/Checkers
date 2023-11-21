#include "MainWindowModel.h"
#include "GameModel.h"
#include "MainMenuModel.h"
#include "SettingsModel.h"
#include "StaticsModel.h"

#include "MainWindowView.h"

MainWindowModel::MainWindowModel(int argc, char *argv[])
{
	createMainWindowView(argc, argv);
	createMainMenuModel();
	createSettingsModel();
	createStaticsModel();
	createGameModel();
	main_window_view_->showMainMenu();
}

MainWindowModel::~MainWindowModel()
{
}

void MainWindowModel::showMainMenu()
{
}

void MainWindowModel::showSettings()
{
}

void MainWindowModel::showStatistics()
{
}

void MainWindowModel::launchLanGame()
{
}

void MainWindowModel::launchAIGame()
{
}

void MainWindowModel::exit()
{
}

int MainWindowModel::launch()
{
	return main_window_view_->launch();
}

void MainWindowModel::createMainWindowView(int argc, char *argv[])
{
	main_window_view_ = std::make_unique<MainWindowView>(argc, argv, this);
}

void MainWindowModel::createMainMenuModel()
{
	main_menu_model_ = std::make_unique<MainMenuModel>(this);
	main_window_view_->addWidget(WINDOW_NAME::MAIN_MENU, main_menu_model_->getView());
}

void MainWindowModel::createSettingsModel()
{
	settings_model_ = std::make_unique<SettingsModel>(this);
}

void MainWindowModel::createStaticsModel()
{
	statics_model_ = std::make_unique<StaticsModel>(this);
}

void MainWindowModel::createGameModel()
{
	game_model_ = std::make_unique<GameModel>(this);
}

IMainWindowView *MainWindowModel::getMainWindow() const
{
	return main_window_view_.get();
}
