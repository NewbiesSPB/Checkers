#include "MainWindowModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	MainWindowModel window(argc, argv);
	return window.launch();
}
