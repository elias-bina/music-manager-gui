#ifndef MMG_UI_WIDGETS_WIDGET
#define MMG_UI_WIDGETS_WIDGET

class RenderableWidget
{
private:
	/* data */
public:
	RenderableWidget(/* args */);
	~RenderableWidget();

	virtual void Render() = 0;
};

#endif