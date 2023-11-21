#ifndef MainWindowModel_H
#define MainWindowModel_H

#include <memory>

class IMainWindowView;
class MainMenuModel;
class SettingsModel;
class StaticsModel;
class GameModel;

class MainWindowModel
{
public:
	explicit MainWindowModel(int argc, char* argv[]);
	virtual ~MainWindowModel();

	void showMainMenu();
	void showSettings();
	void showStatistics();
	void launchLanGame();
	void launchAIGame();
	void exit();
	int launch();

private:
	void createMainWindowView(int argc, char* argv[]);
	void createMainMenuModel();
	void createSettingsModel();
	void createStaticsModel();
	void createGameModel();
	IMainWindowView* getMainWindow() const;

	std::unique_ptr<IMainWindowView> main_window_view_;
	std::unique_ptr<MainMenuModel> main_menu_model_;
	std::unique_ptr<SettingsModel> settings_model_;
	std::unique_ptr<StaticsModel> statics_model_;
	std::unique_ptr<GameModel> game_model_;
};

#endif	  // MainWindowModel_H
