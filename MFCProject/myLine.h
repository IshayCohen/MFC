#include "Figure2D.h"

class myLine : public Figure2D
{
public:
	DECLARE_SERIAL(myLine)

	myLine(CPoint s, CPoint e) :Figure2D(s, e) {};
	myLine() {}
	~myLine(){}
	void draw(CDC* dc);
	void Moveto(CDC* dc, double newStart, double newEnd) {};
	//bool isInside(CPoint p);
	virtual void Serialize(CArchive& archive);
	int getType();
};