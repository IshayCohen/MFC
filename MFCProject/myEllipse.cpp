#include "pch.h"
#include "myEllipse.h"

IMPLEMENT_SERIAL(myEllipse, Figure2D, 1)
void myEllipse::draw(CDC* dc)
{
	CPen pen(PS_SOLID, 7, colorLine);
	CPen* old = dc->SelectObject(&pen);
	CBrush brush(colorBackgroundShape);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y); 
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}
void myEllipse::Moveto(CDC* dc, double newStart, double newEnd)
{
	startPoint = newStart;
	endPoint = newEnd;
	draw(dc);
}

//bool myEllipse::isInside(CPoint p)
//{
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

void myEllipse::Serialize(CArchive& archive)
{
	Figure2D::Serialize(archive);
}

int myEllipse::getType()
{
	return 5;
}
