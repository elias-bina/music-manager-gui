#ifndef MMG_CONTEXT_MANAGEMENT_TOP_MENU
#define MMG_CONTEXT_MANAGEMENT_TOP_MENU

#include "context-management/app-context.h"

#include "ui/widgets/widget.h"


class TopMenu : RenderableWidget
{
private:
	AppContext* _context;

	void Save();

public:
	TopMenu(AppContext* context);
	~TopMenu();

	void Render();

};

#endif