//
// TriangleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "trianglebrush.h"
#include "math.h"

extern float frand();

TriangleBrush::TriangleBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void TriangleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void TriangleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("CircleBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();

	glBegin(GL_TRIANGLES);
	SetColor(source);

	glVertex2d(target.x, target.y + size);
	glVertex2d(target.x + cos(45) * size / 2, target.y - size * (1 / 2));
	glVertex2d(target.x - cos(45) * size / 2, target.y - size * (1 / 2));

	glEnd();
}

void TriangleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

