#pragma once
#include "Figure2D.h"

class myEllipse : public Figure2D
{
public:
	DECLARE_SERIAL(myEllipse)

	myEllipse(CPoint start, CPoint end) : Figure2D(start, end) {};
	myEllipse() {}
	~myEllipse() {}
	void draw(CDC* dc);
	void Moveto(CDC* dc, double newStart, double newEnd);
	//bool isInside(CPoint p);
	virtual void Serialize(CArchive& archive);
	int getType();
};