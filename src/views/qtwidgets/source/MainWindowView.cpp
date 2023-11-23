#include "MainWindowView.h"
#include "MainWindowModel.h"

#include <QApplication>
#include <QBoxLayout>
#include <QMainWindow>
#include <QStackedWidget>
#include <iostream>

MainWindowView::MainWindowView(int argc, char *argv[], MainWindowModel *model, QWidget *parent)
: model_(model)
{
	app_  = new QApplication(argc, argv);
	view_ = new QMainWindow();
	QCoreApplication::setApplicationName("Checkers");
	QCoreApplication::setOrganizationName("NewbiesSPB");
	QCoreApplication::setApplicationVersion(QT_VERSION_STR);
	constructWindow();
}

MainWindowView::~MainWindowView()
{
}

int MainWindowView::launch()
{
	view_->show();
	return app_->exec();
}

void MainWindowView::exit()
{
	QCoreApplication::exit();
}

bool MainWindowView::showMainMenu()
{
	if (auto it = widget_list_.find(WINDOW_TYPE::MAIN_MENU); it != widget_list_.end())
	{
		widget_holder_->setCurrentWidget(it->second);
		return true;
	}
	return false;
}

bool MainWindowView::showSettings()
{
	if (auto it = widget_list_.find(WINDOW_TYPE::SETTINGS); it != widget_list_.end())
	{
		widget_holder_->setCurrentWidget(it->second);
		return true;
	}
	return false;
}

bool MainWindowView::showStatistics()
{
	if (auto it = widget_list_.find(WINDOW_TYPE::STATICS); it != widget_list_.end())
	{
		widget_holder_->setCurrentWidget(it->second);
		return true;
	}
	return false;
}

bool MainWindowView::showGame()
{
	if (auto it = widget_list_.find(WINDOW_TYPE::GAME); it != widget_list_.end())
	{
		widget_holder_->setCurrentWidget(it->second);
		return true;
	}
	return false;
}

bool MainWindowView::addWidget(WINDOW_TYPE name, IView *view)
{
	auto widget = dynamic_cast<QWidget *>(view);

	if (!widget)
	{
		std::cerr << "Widget cast failed/n";
		qDebug() << "Widget cast failed";
		return false;
	}

	if (widget_list_.insert(std::pair{name, widget}).second)
	{
		widget->setParent(view_);
		widget_holder_->addWidget(widget);
		return true;
	}
	return false;
}

IView *MainWindowView::getView()
{
	return this;
}

void MainWindowView::constructWindow()
{
	widget_holder_ = new QStackedWidget(view_);
	widget_holder_->setMinimumSize(1, 1);
	widget_holder_->setMaximumSize(600, 600);
	widget_holder_->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	view_->setCentralWidget(widget_holder_);
}
