#include "pch.h"
#include "myCircle.h"

IMPLEMENT_SERIAL(myCircle, myEllipse, 1)
void myCircle::draw(CDC* dc)
{
	CPen pen(PS_SOLID, 7, colorLine);
	CPen* old = dc->SelectObject(&pen);
	CBrush brush(colorBackgroundShape);
	CBrush* oldBrush = dc->SelectObject(&brush);
	int min = fmin(abs(startPoint.x - endPoint.x), abs(startPoint.y - endPoint.y));

	if (startPoint.x < endPoint.x && startPoint.y < endPoint.y)
	{
		setEndByXY(startPoint.x + min, startPoint.y + min);
	}
	else if (startPoint.x > endPoint.x && startPoint.y > endPoint.y)
	{
		setEndByXY(startPoint.x - min, startPoint.y - min);
	}
	else if (startPoint.x < endPoint.x && startPoint.y > endPoint.y)
	{
		setEndByXY(startPoint.x + min, startPoint.y - min);
	}
	else if (startPoint.x > endPoint.x && startPoint.y < endPoint.y)
	{
		setEndByXY((startPoint.x - min), (startPoint.y + min));
	}

	dc->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}
void myCircle::Moveto(CDC* dc, double newStart, double newEnd)
{
	startPoint = newStart;
	endPoint = newEnd;
	draw(dc);
}

void myCircle::Serialize(CArchive& archive)
{
	myEllipse::Serialize(archive);
}

int myCircle::getType()
{
	return 6;
}
