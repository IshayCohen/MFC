#include "pch.h"
#include "myDiamond.h"
IMPLEMENT_SERIAL(myDiamond, myRectangle, 1)
void myDiamond::draw(CDC* dc)
{
	CPen pen(PS_SOLID, 7, colorLine);
	CPen* old = dc->SelectObject(&pen);

	CBrush brush(colorBackgroundShape);
	CBrush* oldBrush = dc->SelectObject(&brush);
	dots[0] = CPoint(startPoint.x, startPoint.y);
	if (startPoint.x == endPoint.x && startPoint.y != endPoint.y)
	{
		dots[1].SetPoint(startPoint.x - (endPoint.y - startPoint.y) / 2, (endPoint.y + startPoint.y) / 2);
		dots[2].SetPoint(startPoint.x, endPoint.y);
		dots[3].SetPoint(startPoint.x + (endPoint.y - startPoint.y) / 2, (endPoint.y + startPoint.y) / 2);
	}
	else
	{
		dots[1].SetPoint((startPoint.x + endPoint.x) / 2, startPoint.y - (startPoint.x - endPoint.x) / 2);
		dots[2].SetPoint(endPoint.x, startPoint.y);
		dots[3].SetPoint((startPoint.x + endPoint.x) / 2, startPoint.y + (startPoint.x - endPoint.x) / 2);
	}

	dc->Polygon(dots, 4);
	dc->SelectObject(old);
	dc->SelectObject(oldBrush);
}
void myDiamond::Moveto(CDC* dc, double newStart, double newEnd)
{
	startPoint = newStart;
	endPoint = newEnd;
	draw(dc);
}

void myDiamond::Serialize(CArchive& archive)
{
	myRectangle::Serialize(archive);
}

int myDiamond::getType()
{
	return 4;
}
