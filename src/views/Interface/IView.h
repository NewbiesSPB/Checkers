#ifndef IView_H
#define IView_H

#include <cstdint>

enum WINDOW_NAME : uint8_t
{
	MAIN_MENU,
	SETTINGS,
	STATICS,
	GAME
};

class IView
{
public:
	virtual ~IView() = default;
	virtual IView* getView() = 0;
};

class IMainWindowView : public IView
{
public:
	virtual ~IMainWindowView() = default;
	virtual int launch()									= 0;
	virtual bool showMainMenu()								= 0;
	virtual bool showSettings()								= 0;
	virtual bool showStatistics()							= 0;
	virtual bool showGame()									= 0;
	virtual bool addWidget(WINDOW_NAME name, IView* view) = 0;
};

#endif	  // IView_H
