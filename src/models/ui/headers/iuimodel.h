#ifndef IUiModel_H
#define IUiModel_H

#include "IView.h"

class IUiModel
{
public:
	virtual ~IUiModel()		   = default;
	virtual IView* getView()   = 0;
	virtual void clickedBack() = 0;
};

#endif	  // IUiModel_H
