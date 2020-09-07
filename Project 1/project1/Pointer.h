#ifndef POINTER_H
#define POINTER_H

#include "ImpBrush.h"

class Pointer : public ImpBrush
{
public:
	Pointer(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif