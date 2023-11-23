#ifndef GameView_H
#define GameView_H

#include <IView.h>
#include <QWidget>

class MyButtonRound;
class GameModel;
class QGraphicsView;
class BoardView;

class GameView : public QWidget
, public IGameView
{
	Q_OBJECT
public:
	explicit GameView(GameModel *model, QWidget *parent = nullptr);
	virtual ~GameView();

	IView *getView() override;
	void clickedBack() override;

protected:
	void resizeEvent(QResizeEvent *event) override;

private:
	void constructWindow();
	GameModel *model_;
	MyButtonRound *button_back_;
	QGraphicsView *scene_view_;
	BoardView *board_view_;
};

#endif	  // GameView_H
