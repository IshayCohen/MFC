#pragma once
#include "framework.h"



class Figure2D : public CObject 
{
protected:
	CPoint startPoint;
	CPoint endPoint;
	COLORREF colorLine, colorBackgroundShape;
	int type=0; // 1 = line, 2 = rectangle , 3 = square, 4 = diamond , 5 = ellipse, 6 = circle
public:
	DECLARE_SERIAL(Figure2D)

	Figure2D(CPoint s, CPoint e);
	Figure2D() ;
	virtual ~Figure2D() {};
	

	virtual void draw(CDC* dc) {};
	virtual void Moveto(CDC* dc, double newStart, double newEnd)  {};
	bool isInside(CPoint p);
	virtual void Serialize(CArchive& archive);
	CPoint getStart();
	CPoint getEnd();
	void setStart(CPoint start);
	void setEnd(CPoint end);
	void setEndByXY(int x, int y);
	void setStartByXY(int x, int y);
	void setShapeLineColor(COLORREF newColor);
	COLORREF getShapeLineColor();
	void setShapeBackgroundColor(COLORREF newColor);
	COLORREF getShapeBackgroundColor();
	virtual int getType() { return 0; };

};
