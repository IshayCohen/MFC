#pragma once

#include "Figure2D.h"
class myRectangle : public Figure2D {


public:
	DECLARE_SERIAL(myRectangle)

	myRectangle(CPoint start, CPoint end) : Figure2D(start, end) {};
	myRectangle() {}
	~myRectangle() {}
	 void draw(CDC* dc);
	 void Moveto(CDC* dc, double newStart, double newEnd) ;
	 void Resize(CDC* dc, double newStart, double newEnd) {};
	 //bool isInside(CPoint p);
	 virtual void Serialize(CArchive& archive);
	 int getType();
};
