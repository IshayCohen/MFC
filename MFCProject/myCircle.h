#pragma once
#include "myEllipse.h"

class myCircle : public myEllipse
{
public:
	DECLARE_SERIAL(myCircle)

	myCircle(CPoint start, CPoint end) : myEllipse(start, end) {};
	myCircle() {}
	~myCircle() {}
	void draw(CDC* dc);
	void Moveto(CDC* dc, double newStart, double newEnd);
	virtual void Serialize(CArchive& archive);
	int getType();
};
