//
// CircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "donutbrush.h"
#include "math.h"

extern float frand();

DonutBrush::DonutBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void DonutBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void DonutBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("CircleBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	double x[360], y[360];
	glBegin(GL_LINES);
	SetColor(source);

	for (int i = 0; i <= 359; i++) {
		double angle = i * M_PI / 180;
		x[i] = (angle) / 2;
		y[i] = (angle) / 2;
	}

	for (int i = 0; i <= 358; i++) {
		glVertex2f(target.x * x[i], target.y * y[i]);
		glVertex2f(target.x * x[i + 1], target.y * y[i + 1]);
	}
	glEnd();
}

void DonutBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

