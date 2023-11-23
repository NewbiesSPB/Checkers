#ifndef StatisticsModel_H
#define StatisticsModel_H

class MainWindowModel;
class StaticsView;

class StatisticsModel
{
public:
	explicit StatisticsModel(MainWindowModel* parent);
	~StatisticsModel();

private:
	MainWindowModel* parent_;
	StaticsView* view_;
};

#endif	  // StatisticsModel_H
