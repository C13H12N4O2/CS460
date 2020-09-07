//
// ScatteredCircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredcirclebrush.h"
#include "math.h"

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredCircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void ScatteredCircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredCircleBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	double r = size / 2;

	glBegin(GL_POLYGON);
	

	for (int i = 0; i <= size; i++) {
		int x = rand() % size - r;
		int y = rand() % size - r;

		for (int j = 0; j <= 359; j++) {
			double angle = j * M_PI / 180;

			SetColor(Point(target.x + x + cos(angle) * (size / 2), target.y + y + sin(angle) * (size / 2)));
			glVertex2d(target.x + x + cos(angle) * (size / 2), target.y + y + sin(angle) * (size / 2));
		}
	}

	glEnd();
}

void ScatteredCircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

