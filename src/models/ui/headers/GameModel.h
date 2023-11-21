#ifndef GameModel_H
#define GameModel_H

class MainWindowModel;
class GameModelView;

class GameModel
{
public:
	explicit GameModel(MainWindowModel* parent);
	~GameModel();

private:
	MainWindowModel* parent_;
	GameModelView* view_;
};

#endif	  // GameModel_H
