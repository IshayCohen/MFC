#include "pch.h"
#include "myLine.h"

IMPLEMENT_SERIAL(myLine, Figure2D, 1)
void myLine::draw(CDC* dc)
{
	CPen pen(PS_SOLID, 7, colorLine);
	CPen* old = dc->SelectObject(&pen);
	CBrush brush(colorBackgroundShape);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->MoveTo(startPoint.x, startPoint.y); // draw line from start point
	dc->LineTo(endPoint.x, endPoint.y); // draw line to end point
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}

//bool myLine::isInside(CPoint p)
//{
//	/*if ((startPoint.x <= p.x && endPoint.x >= p.x && startPoint.y <= p.y && endPoint.y >= p.y) || 
//		(startPoint.x >= p.x && endPoint.x <= p.x && startPoint.y <= p.y && endPoint.y >= p.y) ||
//		(startPoint.x <= p.x && endPoint.x >= p.x && startPoint.y >= p.y && endPoint.y <= p.y) ||
//		(startPoint.x >= p.x && endPoint.x <= p.x && startPoint.y <= p.y && endPoint.y >= p.y))
//		return true;
//	return false;*/
//	if (startPoint.x <= p.x && endPoint.x >= p.x)
//	{
//		if ((startPoint.y <= p.y && endPoint.y >= p.y) || (startPoint.y >= p.y && endPoint.y <= p.y))
//			return true;
//	}
//	if (startPoint.x >= p.x && endPoint.x <= p.x)
//	{
//		if ((startPoint.y <= p.y && endPoint.y >= p.y) || (startPoint.y >= p.y && endPoint.y <= p.y))
//			return true;
//	}
//	return false;
//}

void myLine::Serialize(CArchive& archive)
{
	Figure2D::Serialize(archive);
}

int myLine::getType()
{
	return 1;
}
