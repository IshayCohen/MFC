#include "pch.h"
#include "mySquare.h"

IMPLEMENT_SERIAL(mySquare, myRectangle, 1)
void mySquare::draw(CDC* dc)
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
		setEndByXY(startPoint.x - min, startPoint.y + min);
	}

	dc->Rectangle(startPoint.x, startPoint.y, endPoint.x, endPoint.y);  // square check
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}
void mySquare::Moveto(CDC* dc, double newStart, double newEnd)
{
	startPoint = newStart;
	endPoint = newEnd;
	draw(dc);
}

void mySquare::Serialize(CArchive& archive)
{
	myRectangle::Serialize(archive);
}

int mySquare::getType()
{
	return 3;
}
