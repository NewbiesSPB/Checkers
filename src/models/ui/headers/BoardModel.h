#ifndef BoardModel_H
#define BoardModel_H

#include <memory>

class GameModel;
class BoardView;

class BoardModel
{
public:
	explicit BoardModel(GameModel* parent);
	~BoardModel();

	BoardView* getView();

private:
	void createView();

	GameModel* parent_;
	std::unique_ptr<BoardView> view_;
};

#endif // BoardModel_H
