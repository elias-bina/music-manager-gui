#ifndef MMG_UI_WIDGETS_SONG_OBSERVER
#define MMG_UI_WIDGETS_SONG_OBSERVER

class SongObserver;

#include <memory>

#include "ui/widgets/song.h"


class SongObserver {
public:
	virtual void songUpdateNotify(std::shared_ptr<SongWidget> song_notifying) = 0;
};

#endif