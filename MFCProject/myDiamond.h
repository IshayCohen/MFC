#pragma once
#include "myRectangle.h"

class myDiamond : public myRectangle
{
private:
	CPoint dots[4];
public:
	DECLARE_SERIAL(myDiamond)

	myDiamond(CPoint s, CPoint e) : myRectangle(s, e) {};
	myDiamond() {}
	~myDiamond() {}
	void draw(CDC* dc);
	void Moveto(CDC* dc, double newStart, double newEnd);
	virtual void Serialize(CArchive& archive);
	int getType();
};
