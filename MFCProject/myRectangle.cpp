#include "pch.h"
#include "myRectangle.h"

IMPLEMENT_SERIAL(myRectangle, Figure2D, 1)
void myRectangle::draw(CDC* dc) 
{
	CPen pen(PS_SOLID, 7, colorLine);
	CPen* old = dc->SelectObject(&pen);
	CBrush brush(colorBackgroundShape);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->Rectangle(startPoint.x, startPoint.y, endPoint.x, endPoint.y); 
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}
void myRectangle::Moveto(CDC* dc,double newStart, double newEnd)
{
	startPoint = newStart;
	endPoint = newEnd;
	draw(dc);
}

//bool myRectangle::isInside(CPoint p)
//{
//	if ((startPoint.x <= p.x && endPoint.x >= p.x && startPoint.y <= p.y && endPoint.y >= p.y) ||
//		(startPoint.x >= p.x && endPoint.x <= p.x && startPoint.y <= p.y && endPoint.y >= p.y) ||
//		(startPoint.x <= p.x && endPoint.x >= p.x && startPoint.y >= p.y && endPoint.y <= p.y) ||
//		(startPoint.x >= p.x && endPoint.x <= p.x && startPoint.y <= p.y && endPoint.y >= p.y))
//		return true;
//	return false;
//}

void myRectangle::Serialize(CArchive& archive)
{
	Figure2D::Serialize(archive);
}

int myRectangle::getType()
{
	return 2;
}
