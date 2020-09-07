#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointer.h"

extern float frand();

Pointer::Pointer(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void Pointer::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void Pointer::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("Pointer::Pointer document is NULL\n");
		return;
	}

	double alpha = pDoc->getAlpha();

	glBegin(GL_POINTS);
	SetColor(source);

	glVertex2d(target.x * target.x, target.y);

	glEnd();
}

void Pointer::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}