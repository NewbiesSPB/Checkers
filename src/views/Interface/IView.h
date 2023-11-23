#ifndef IView_H
#define IView_H

#include <cstdint>

enum WINDOW_TYPE : uint8_t
{
	MAIN_MENU,
	SETTINGS,
	STATICS,
	GAME
};

class IView
{
public:
	virtual ~IView()		 = default;
	virtual IView* getView() = 0;
};

class IMainWindowView : public IView
{
public:
	virtual ~IMainWindowView()							  = default;
	virtual int launch()								  = 0;
	virtual void exit()									  = 0;
	virtual bool showMainMenu()							  = 0;
	virtual bool showSettings()							  = 0;
	virtual bool showStatistics()						  = 0;
	virtual bool showGame()								  = 0;
	virtual bool addWidget(WINDOW_TYPE name, IView* view) = 0;
};

class IMainMenuView : public IView
{
public:
	virtual ~IMainMenuView()			 = default;
	virtual void clickedExit()			 = 0;
	virtual void clickedLaunchLanGame()	 = 0;
	virtual void clickedLaunchAIGame()	 = 0;
	virtual void clickedShowSettings()	 = 0;
	virtual void clickedShowStatistics() = 0;
};

class ISettingsView : public IView
{
public:
	virtual ~ISettingsView()			= default;
	virtual void clickedBack()			= 0;
	virtual void setHostPlayBlack(bool) = 0;
	virtual void setAlwaysBeat(bool)	= 0;
	virtual void setReverseGame(bool)	= 0;
	virtual void setHelpWithMove(bool)	= 0;
};

class IGameView : public IView
{
public:
	virtual ~IGameView()	   = default;
	virtual void clickedBack() = 0;
};

#endif	  // IView_H
