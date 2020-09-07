#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name):
	ImpBrush(pDoc, name) {
}

void LineBrush::BrushBegin(const Point source, const Point target) {
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc -> m_pUI;

	int size = pDoc -> getSize();

	glPointSize((float) size);
	BrushMove(source,l target);
}

void LineBrush::BrushMove(const Point source, const Point target) {
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		returnl
	}

	glBegin(GL_LINES);
	SetColor(source);
	glVertex2d(target.x, target.y);
	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target) {
}
