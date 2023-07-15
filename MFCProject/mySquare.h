#pragma once
#include "myRectangle.h"

class mySquare : public myRectangle
{
public:
	DECLARE_SERIAL(mySquare)

	mySquare(CPoint s, CPoint e) : myRectangle(s, e) {};
	mySquare() {}
	~mySquare() {}
	void draw(CDC* dc);
	void Moveto(CDC* dc, double newStart, double newEnd);
	void Resize(CDC* dc, double newStart, double newEnd) {};
	virtual void Serialize(CArchive& archive);
	int getType();
};
