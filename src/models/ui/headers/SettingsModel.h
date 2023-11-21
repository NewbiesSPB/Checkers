#ifndef SettingsModel_H
#define SettingsModel_H

class MainWindowModel;
class GameSettingsView;

class SettingsModel
{
public:
	explicit SettingsModel(MainWindowModel* parent);
	~SettingsModel();

	void clickedBack();
	void setHostPlayBlack(bool state);
	bool getHostPlayBlack() const;
	void setAlwaysBeat(bool state);
	bool getAlwaysBeat() const;
	void setReverseGame(bool state);
	bool getReverseGame() const;
	void setHelpWithMove(bool state);
	bool getHelpWithMove() const;

private:
	bool host_is_black_;
	bool always_beat_;
	bool reverse_game_;
	bool show_avaliable_moves_;

	MainWindowModel* parent_;
	GameSettingsView* view_;
};

#endif	  // SettingsModel_H
