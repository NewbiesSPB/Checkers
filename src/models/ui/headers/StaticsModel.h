#ifndef StaticsModel_H
#define StaticsModel_H

class MainWindowModel;
class StaticsView;

class StaticsModel
{
public:
	explicit StaticsModel(MainWindowModel* parent);
	~StaticsModel();

private:
	MainWindowModel* parent_;
	StaticsView* view_;
};

#endif	  // StaticsModel_H
