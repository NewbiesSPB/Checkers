#include "MainWindowModel.h"
#include "GameModel.h"
#include "MainMenuModel.h"
#include "SettingsModel.h"
#include "StatisticsModel.h"

#include "MainWindowView.h"

MainWindowModel::MainWindowModel(int argc, char *argv[])
{
	createView(argc, argv);
	createMainMenuModel();
	createSettingsModel();
	createStatisticsModel();
	createGameModel();
	main_window_view_->showMainMenu();
}

MainWindowModel::~MainWindowModel()
{
}

void MainWindowModel::showMainMenu()
{
	main_window_view_->showMainMenu();
}

void MainWindowModel::showSettings()
{
}

void MainWindowModel::showStatistics()
{
}

void MainWindowModel::launchLanGame()
{
	// TODO call GameModel to init lan game
	main_window_view_->showGame();
}

void MainWindowModel::launchAIGame()
{
	// TODO call GameModel to init ai game
}

void MainWindowModel::exit()
{
	main_window_view_->exit();
}

int MainWindowModel::launch()
{
	return main_window_view_->launch();
}

void MainWindowModel::createView(int argc, char *argv[])
{
	main_window_view_ = std::make_unique<MainWindowView>(argc, argv, this);
}

void MainWindowModel::createMainMenuModel()
{
	main_menu_model_ = std::make_unique<MainMenuModel>(this);
	main_window_view_->addWidget(WINDOW_TYPE::MAIN_MENU, main_menu_model_->getView());
}

void MainWindowModel::createSettingsModel()
{
	settings_model_ = std::make_unique<SettingsModel>(this);
}

void MainWindowModel::createStatisticsModel()
{
	statistics_model_ = std::make_unique<StatisticsModel>(this);
}

void MainWindowModel::createGameModel()
{
	game_model_ = std::make_unique<GameModel>(this);
	main_window_view_->addWidget(WINDOW_TYPE::GAME, game_model_->getView());
}

IMainWindowView *MainWindowModel::getMainWindow() const
{
	return main_window_view_.get();
}
