//
// LineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"
#include "math.h"

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	int width = pDoc->getWidth();

	glLineWidth( (float)width );

	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	int width = pDoc->getWidth();
	int inputangle = pDoc->getAngle();
	double angle = inputangle * M_PI / 360;

	glBegin(GL_LINES);
	SetColor(source);

	glVertex2d(target.x - cos(angle) * size, target.y - sin(angle) * size * width);
	glVertex2d(target.x + cos(angle) * size, target.y + sin(angle) * size * width);

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

