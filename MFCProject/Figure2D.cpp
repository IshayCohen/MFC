#include "pch.h"
#include "Figure2D.h"

IMPLEMENT_SERIAL (Figure2D,CObject,1)
Figure2D::Figure2D(CPoint s, CPoint e)
{
	startPoint = s;
	endPoint = e;
	colorLine = RGB(0, 0, 255);
	colorBackgroundShape = RGB(255, 255, 255);
}
Figure2D::Figure2D()
{
	CPoint s;
	startPoint = s;
	endPoint = s;
	colorLine = RGB(0, 0, 255);
	colorBackgroundShape = RGB(255, 255, 255);
}
CPoint Figure2D::getEnd()
{
	return endPoint;
}
bool Figure2D::isInside(CPoint p)
{
	if (startPoint.x <= p.x && endPoint.x >= p.x)
	{
		if ((startPoint.y <= p.y && endPoint.y >= p.y) || (startPoint.y >= p.y && endPoint.y <= p.y))
			return true;
	}
	if (startPoint.x >= p.x && endPoint.x <= p.x)
	{
		if ((startPoint.y <= p.y && endPoint.y >= p.y) || (startPoint.y >= p.y && endPoint.y <= p.y))
			return true;
	}
	return false;
}
void Figure2D::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	if (archive.IsStoring())
	{
		archive << startPoint;
		archive << endPoint;
		archive << colorLine;
		archive << colorBackgroundShape;
	}
	else
	{
		archive >> startPoint;
		archive >> endPoint;
		archive >> colorLine;
		archive >> colorBackgroundShape;
	}
}
CPoint Figure2D::getStart()
{
	return startPoint;
}
void Figure2D::setStart(CPoint start)
{
	startPoint = start;
}
void Figure2D::setEnd(CPoint end)
{
	endPoint = end;
}
void Figure2D::setEndByXY(int x, int y)
{
	endPoint.x = x;
	endPoint.y = y;
}
void Figure2D::setStartByXY(int x, int y)
{
	startPoint.x = x;
	startPoint.y = y;
}
void Figure2D::setShapeLineColor(COLORREF newColor)
{
	colorLine = newColor;
}
COLORREF Figure2D::getShapeLineColor()
{
	return colorLine;
}

void Figure2D::setShapeBackgroundColor(COLORREF newColor)
{
	colorBackgroundShape = newColor;
}

COLORREF Figure2D::getShapeBackgroundColor()
{
	return colorBackgroundShape;
}
