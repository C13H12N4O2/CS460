//
// ScatteredPointBrush.cpp
//
// The implementation of Scattered Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredpointbrush.h"
#include "math.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)1);

	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredPointBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	double r = size / 2;
	double _2pi = 2 * M_PI;

	for (int i = 0; i <= size; i++) {
		int x = rand() % size - r;
		int y = rand() % size - r;

		glBegin(GL_POINTS);
		SetColor(Point(source.x + x - r + (r * cos(_2pi / 50)), source.y + y - r + (r * sin(_2pi / 50))));
		glVertex2d(target.x + x - r + (r * cos(_2pi / 50)), target.y + y - r + (r * sin(_2pi / 50)));
	}

	glEnd();
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

