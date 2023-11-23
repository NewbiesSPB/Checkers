#ifndef MainWindowView_H
#define MainWindowView_H

#include "IView.h"

#include <QObject>
#include <map>

class MainWindowModel;
class QStackedWidget;
class QApplication;
class QMainWindow;
class QWidget;

class MainWindowView : public QObject
, public IMainWindowView
{
	Q_OBJECT

public:
	explicit MainWindowView(int argc, char* argv[], MainWindowModel* model, QWidget* parent = nullptr);
	virtual ~MainWindowView();

	int launch() override;
	void exit() override;
	bool showMainMenu() override;
	bool showSettings() override;
	bool showStatistics() override;
	bool showGame() override;
	bool addWidget(WINDOW_TYPE name, IView* view) override;
	IView* getView() override;

private:
	void constructWindow();
	QMainWindow* view_;
	QApplication* app_;
	MainWindowModel* model_;
	QStackedWidget* widget_holder_;

	std::map<WINDOW_TYPE, QWidget*> widget_list_;
};
#endif	  // MainWindowView_H
