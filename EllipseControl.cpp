#include "EllipseControl.h"
#include <GL/glu.h>

EllipseControl::EllipseControl()
{
	curEllipse = NULL;
}

EllipseControl::EllipseControl(std::vector<Figure *> *figures):FigureControl(figures)
{
	curEllipse = NULL;
}

EllipseControl::EllipseControl(int width, int height):FigureControl(width, height)
{
	curEllipse = NULL;
}

void EllipseControl::onMousePressEvent(QMouseEvent *event)
{
	if(event->button()==Qt::LeftButton)
	{
		if(curEllipse!=NULL)
		{
			Point curPoint(event->x(), height-event->y());
			for(Point p:curEllipse->getMarkPoints())
				if(p.distanceTo(curPoint)<=5)
				{
					setEP = MARKPOINT;
					return;
				}
		}
		curEllipse = new MyEllipse(Point(event->x(), height-event->y()), Point(event->x(), height-event->y()));
		ellipses.push_back(curEllipse);
		allFigures->push_back(curEllipse);
		setEP = ENDPOINT;
	}
}

void EllipseControl::onMouseMoveEvent(QMouseEvent *event)
{
	if (curEllipse == NULL)
		return;
	Point center = curEllipse->getCenter();
	switch(setEP)
	{
	case ENDPOINT: curEllipse->setEndPoint(Point(event->x(), height-event->y())); break;
	case MARKPOINT: curEllipse->setAxes(abs(event->x()-center.getX()), abs((height-event->y())-center.getY())); break;
	default: ;
	}
}

void EllipseControl::onKeyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Left: curEllipse->translate(Point(-2,0)); break;
	case Qt::Key_Right: curEllipse->translate(Point(2,0)); break;
	case Qt::Key_Up: curEllipse->translate(Point(0,2)); break;
	case Qt::Key_Down: curEllipse->translate(Point(0,-2)); break;
	case Qt::Key_Q: curEllipse->rotate(-90); break;
	case Qt::Key_E: curEllipse->rotate(90); break;
	default: ;
	}
}

void EllipseControl::onDraw()
{
	for(MyEllipse *ellipse : ellipses)
		ellipse->draw();
}

void EllipseControl::onMarkDraw()
{
	if(curEllipse!=NULL)
		curEllipse->markDraw();
}
