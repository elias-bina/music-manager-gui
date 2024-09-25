#ifndef MMG_CONTEXT_MANAGEMENT_APP_CONTEXT
#define MMG_CONTEXT_MANAGEMENT_APP_CONTEXT

#include "ui/widgets/song.h"
class AppContext
{
private:
	/* data */
public:
	AppContext(/* args */);
	~AppContext();

	SongWidget songWidget; // TODO: Should be a list
};

#endif
