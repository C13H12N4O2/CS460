//
// ScatteredLineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredlinebrush.h"
#include "math.h"

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	int width = pDoc->getWidth();

	glLineWidth((float)width);

	BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredLineBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	int width = pDoc->getWidth();
	int inputangle = pDoc->getAngle();
	double angle = inputangle * M_PI / 360;
	double r = size / 2;

	for (int i = 0; i <= size; i++) {
		int x = rand() % size - r;
		int y = rand() % size - r;

		glBegin(GL_LINES);
		SetColor(Point(source.x + x - cos(angle) * size, source.y + y - sin(angle) * size * width));
		SetColor(Point(target.x + x + cos(angle) * size, target.y + y + sin(angle) * size * width));

		glVertex2d(target.x + x - cos(angle) * size, target.y + y - sin(angle) * size * width);
		glVertex2d(target.x + x + cos(angle) * size, target.y + y + sin(angle) * size * width);
	}

	glEnd();
}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

