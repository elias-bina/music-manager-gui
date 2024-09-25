#ifndef MMG_CONTEXT_MANAGEMENT_APP_CONTEXT
#define MMG_CONTEXT_MANAGEMENT_APP_CONTEXT

#include "ui/widgets/song-list.h"
class AppContext
{
private:
	/* data */
public:
	AppContext(/* args */);
	~AppContext();

	SongWidgetList songWidgets;
};

#endif
