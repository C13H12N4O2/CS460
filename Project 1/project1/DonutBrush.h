//
// DonutBrush.h
//
// The header file for Point Brush. 
//

#ifndef DONUTBRUSH_H
#define DONUTBRUSH_H

#include "ImpBrush.h"

class DonutBrush : public ImpBrush
{
public:
	DonutBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif