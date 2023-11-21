#include "SettingsModel.h"

SettingsModel::SettingsModel(MainWindowModel *parent) : parent_(parent)
{
}

SettingsModel::~SettingsModel()
{
}

void SettingsModel::clickedBack()
{
}

void SettingsModel::setHostPlayBlack(bool state)
{
	host_is_black_ = state;
}

bool SettingsModel::getHostPlayBlack() const
{
	return host_is_black_;
}

void SettingsModel::setAlwaysBeat(bool state)
{
	always_beat_ = state;
}

bool SettingsModel::getAlwaysBeat() const
{
	return always_beat_;
}

void SettingsModel::setReverseGame(bool state)
{
	reverse_game_ = state;
}

bool SettingsModel::getReverseGame() const
{
	return reverse_game_;
}

void SettingsModel::setHelpWithMove(bool state)
{
	show_avaliable_moves_ = state;
}

bool SettingsModel::getHelpWithMove() const
{
	return show_avaliable_moves_;
}
