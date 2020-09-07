#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

class Model : public ModelerView
{
public:
	Model(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) { }

	virtual void Track();

	virtual void Side();

	virtual void Background();

	virtual void Turtle();

	virtual void Tree();

	virtual void Kart(int);

	virtual void Head(int);

	virtual void Body();

	virtual void RightArm(int);

	virtual void RightHand();

	virtual void LeftArm(int);

	virtual void LeftHand();

	virtual void RightLeg();

	virtual void RightFoot();

	virtual void LeftLeg();

	virtual void LeftFoot();

	virtual void Mario(int);

	virtual void MarioKart();

	virtual void LuigiKart();

	virtual void AnimatingBG();

	virtual void AnimatingRed();

	//virtual void AnimatingBackRed();

	virtual void KartSpin();

	virtual void Shoot();

	virtual void AnimatingGreen();

	virtual void AnimatingRedXpos();

	virtual void draw();

	virtual void AnimatingMain();

	int count = 0;

	int RightArmAngle;

	int LeftArmAngle;

	int Moving = 0;

	int RedMoving = 0;

	double RedCount = 0;

	int Spin = 0;

	int SpinCount = 0;

	int ShootCount = 0;
	
	int TurtleShoot = 0;

	int MainCount = 0;

	int GreenMoving = 0;

	int GreenCount = 0;

	int RedXpos = 0;

	int RedXposCount = 0;

	int BackRedCount = 0;

	int BackRedMoving = 0;
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createModel(int x, int y, int w, int h, char *label)
{
	return new Model(x, y, w, h, label);
}

void Model::Track() {
	setDiffuseColor(COLOR_LESSBLACK);
	glPushMatrix();
	glTranslated(-5, 0, -100);
	drawBox(10, 0.01, 200);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-4.5, 0, -100);
	drawBox(1, 0.011, 200);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(3.5, 0, -100);
	drawBox(1, 0.011, 200);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(0, 0, 10);
	drawBox(0.5, 0.011, 4);
	glPopMatrix();

	for (int i = 100; i >= -100; i = i - 10) {
		glPushMatrix();
		glTranslated(0, 0, i);
		drawBox(0.5, 0.011, 4);
		glPopMatrix();
	}
}

void Model::Side() {
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(-15, 0, -100);
	drawBox(10, 0.01, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5, 0, -100);
	drawBox(10, 0.01, 200);
	glPopMatrix();
}

void Model::Tree() {
	setDiffuseColor(COLOR_BROWN);
	glPushMatrix();
	glTranslated(8, 0, 10);
	drawBox(1, 5, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(6, 3, 8);
	drawBox(4, 4, 4);
	glPopMatrix();
}

void Model::Background() {
	Track();
	glPushMatrix();
		Side();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, -10);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, -30);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, -50);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, 10);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, 30);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(0, 0, 50);
		Tree();
		glPopMatrix();

	glPushMatrix();
		glTranslated(-20, 0, -10);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(-20, 0, -30);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(-20, 0, -50);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(-20, 0, 10);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(-20, 0, 30);
		Tree();
		glPopMatrix();
	glPushMatrix();
		glTranslated(-20, 0, 50);
		Tree();
		glPopMatrix();
}

void Model::Turtle() {
	setDiffuseColor(COLOR_MARIOSKIN);
	glPushMatrix();
	glTranslated(0, 0, 0);
	drawBox(1, 0.5, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	drawBox(1, 0.5, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-0.1, 0.3, -0.1);
	drawBox(1.2, 0.25, 1.2);
	glPopMatrix();
}

void Model::Kart(int i) {

	// Main kart frame
	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glTranslated(-1, 0.5, -7.5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 0.5, 1.5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.6, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.5, 0.8, -1);
	glScaled(3, 1, 4);
	drawBox(1.5, 0.3, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.5, 0.8, -4.2);
	glScaled(3, 1, 4);
	drawBox(1.5, 0.3, 0.3);
	glPopMatrix();

	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	} else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}

	glPushMatrix();
	glRotated(30, 1.0, 0, 0);
	glTranslated(-1, 3.3, -3.3);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 1.5);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(30, 1.0, 0, 0);
	glTranslated(-0.8, 3.35, -3.29);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 1.5);
	glPopMatrix();

	glPushMatrix();
	glRotated(30, 1.0, 0, 0);
	glTranslated(0, 3.35, -3.29);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.72, 3.5);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.8, 1.72, 3.5);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 0.3);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1.0, 0, 0);
	glTranslated(0, 4.42, -2.02);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 0.38);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1.0, 0, 0);
	glTranslated(-0.8, 4.42, -2.02);
	glScaled(3, 1, 4);
	drawBox(0.1, 0.3, 0.38);
	glPopMatrix();

	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glRotated(30, 1.0, 0, 0);
	glTranslated(-0.2, 2.3, -3.8);
	drawCylinder(5, 0.18, 0.2);
	glPopMatrix();

	// Handle
	glPushMatrix();
	glRotated(90, 1, 90, 0);
	glTranslated(2.1, 3.82, -1.8);
	drawCylinder(3, 0.2, 0.2);
	glPopMatrix();

	setDiffuseColor(COLOR_LESSBLACK);
	glPushMatrix();
	glRotated(120, 1.0, 0, 0);
	glTranslated(1.3, -3.7, -3.3);
	drawCylinder(2, 0.2, 0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(120, 1.0, 0, 0);
	glTranslated(-1.8, -3.7, -3.3);
	drawCylinder(2, 0.2, 0.2);
	glPopMatrix();

	//Chair
	setDiffuseColor(COLOR_LESSBLACK);
	glPushMatrix();
	glTranslated(-1.34, 1.02, -5.02);
	glScaled(3, 1, 4);
	drawBox(0.8, 0.7, 0.5);
	glPopMatrix();

	glPushMatrix();
	glRotated(80, 1.0, 0, 0);
	glTranslated(-1.34, -5.02, -4.02);
	glScaled(3, 1, 4);
	drawBox(0.8, 0.7, 0.5);
	glPopMatrix();

	// Front bumper
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(-3, 0.5, 3.5);
	glScaled(3, 1, 4);
	drawBox(1.8, 1.5, 0.3);
	glPopMatrix();

	// Back bumper
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(-3, 0.5, -8.5);
	glScaled(3, 1, 4);
	drawBox(1.8, 1.1, 0.3);
	glPopMatrix();

	// Exhaust
	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-1, -7, -2.5);
	drawCylinder(2, 0.2, 0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(0.5, -7, -2.5);
	drawCylinder(2, 0.2, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 2.4, -7.9);
	drawCylinder(1, 0.4, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, 2.4, -7.9);
	drawCylinder(1, 0.4, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 2.4, -7);
	drawSphere(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, 2.4, -7);
	drawSphere(0.2);
	glPopMatrix();

	setDiffuseColor(COLOR_LESSBLACK);
	glPushMatrix();
	glTranslated(-1, 2.4, -7.92);
	drawCylinder(1, 0.3, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, 2.4, -7.92);
	drawCylinder(1, 0.3, 0.2);
	glPopMatrix();

	// Left kart frame
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(-3, 0.5, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 1.5);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-3, 0.8, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.5, 1.5);
	glPopMatrix();

	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(-3, 1.3, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 1.5);
	glPopMatrix();

	// Right kart frame
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(1, 0.5, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 1.5);
	glPopMatrix();

	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(1, 0.8, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.5, 1.5);
	glPopMatrix();

	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(1, 1.3, -5);
	glScaled(3, 1, 4);
	drawBox(0.5, 0.3, 1.5);
	glPopMatrix();

	//Wheels frame
	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(2.2, 1.1, -2.6);
	drawCylinder(4, 0.1, 0.1);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(-6.2, 1.1, -2.6);
	drawCylinder(4, 0.1, 0.1);
	glPopMatrix();

	// Wheels
	setDiffuseColor(COLOR_BLACK);
	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(-6.2, 1.1, 1.5);
	drawCylinder(1.5, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(-6.2, 1.1, -2.5);
	drawCylinder(1.5, 1, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(-6.2, 1.1, 1.4);
	drawCylinder(1.7, 0.8, 0.8);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(-6.2, 1.1, -2.6);
	drawCylinder(1.7, 0.8, 0.8);
	glPopMatrix();

	setDiffuseColor(COLOR_BLACK);
	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(2.2, 1.1, 1.5);
	drawCylinder(1.5, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(2.2, 1.1, -2.5);
	drawCylinder(1.5, 1, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_GRAY);
	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(2.2, 1.1, 1.4);
	drawCylinder(1.7, 0.8, 0.8);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1.0, 90, 0);
	glTranslated(2.2, 1.1, -2.6);
	drawCylinder(1.7, 0.8, 0.8);
	glPopMatrix();
}

void Model::Head(int i) {
	setDiffuseColor(COLOR_MARIOSKIN);
	glPushMatrix();
	glTranslated(-1.2, 3.7, -5);
	drawBox(1.9, 1.9, 1);
	glPopMatrix();

	setDiffuseColor(COLOR_BLACK);
	glPushMatrix();
	glTranslated(-0.8, 4.4, -4);
	drawBox(1, 0.2, 0.1);
	glPopMatrix();

	// Hat
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	glTranslated(-1.2, 5.6, -5);
	drawBox(1.9, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.2, 5.6, -4.5);
	drawBox(1.9, 0.2, 1);
	glPopMatrix();
}

void Model::Body() {
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(-1.3, 1.71, -5.01);
	drawBox(2.1, 2.1, 1.3);
	glPopMatrix();
}

void Model::RightArm(int i) {
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	//glTranslated(-2, 3, -5);
	drawBox(0.7, 0.7, 2);
	glPopMatrix();
}

void Model::RightHand() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	drawSphere(0.5);
	glPopMatrix();
}

void Model::LeftArm(int i) {
	if (i == 1) {
		setDiffuseColor(COLOR_RED);
	}
	else if (i == 2) {
		setDiffuseColor(COLOR_GREEN);
	}
	glPushMatrix();
	//glTranslated(1, 3, -5);
	drawBox(0.7, 0.7, 2);
	glPopMatrix();
}

void Model::LeftHand() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	drawSphere(0.5);
	glPopMatrix();
}

void Model::RightLeg() {
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(-1.3, 1.7, -5);
	drawBox(0.7, 0.7, 2);
	glPopMatrix();
}

void Model::RightFoot() {
	setDiffuseColor(COLOR_BROWN);
	glPushMatrix();
	glTranslated(-0.9, 2, -2.7);
	drawSphere(0.5);
	glPopMatrix();
}

void Model::LeftLeg() {
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(0.1, 1.7, -5);
	drawBox(0.7, 0.7, 2);
	glPopMatrix();
}

void Model::LeftFoot() {
	setDiffuseColor(COLOR_BROWN);
	glPushMatrix();
	glTranslated(0.4, 2, -2.7);
	drawSphere(0.5);
	glPopMatrix();
}

void Model::Mario(int i) {
	Body();
	glPushMatrix();
	Head(i);
		glPushMatrix();
		glTranslated(-2, 3, -5);
		glRotated(VAL(RIGHTARMANGLE), 1, 0, 0);
		RightArm(i);
		glTranslated(VAL(RHAND_X) + 0.3, VAL(RHAND_Y) + 0.3, VAL(LHAND_Z) + 2.3);
		RightHand();
		glPopMatrix();
	glPushMatrix();
		glTranslated(1, 3, -5);
		glRotated(VAL(LEFTARMANGLE), 1, 0, 0);
		LeftArm(i);
		glTranslated(VAL(LHAND_X) + 0.3, VAL(LHAND_Y) + 0.3, VAL(LHAND_Z) + 2.3);
		LeftHand();
		glPopMatrix();
	glPushMatrix();
		RightLeg();
		RightFoot();
		glPopMatrix();
	glPushMatrix();
		LeftLeg();
		LeftFoot();
		glPopMatrix();
	glPopMatrix();
}

void Model::MarioKart() {
	Kart(1);
	glPushMatrix();
		Mario(1);
		glPopMatrix();
}

void Model::LuigiKart() {
	Kart(2);
	glPushMatrix();
		Mario(2);
		glPopMatrix();
	glPopMatrix();
}

void Model::AnimatingBG() {
	if (count == -40) {
		count = 0;
	}

	Moving =+ count * 2;

	count--;
}

void Model::AnimatingRed() {
	if (RedCount == 120) {
		RedCount = 0;
		BackRedCount = 0;
	}

	if (RedCount < 20) {
		RedMoving =+ RedCount;
	}
	else if (RedCount == 20) {
		// None
	}
	else {
		RedMoving = -BackRedCount * 2;
		BackRedCount++;
	}

	RedCount++;
}
/*
void Model::AnimatingBackRed() {
	if (BackRedCount == 120) {
		BackRedCount = 0;
		BackRedMoving = 0;
	}

	if (BackRedCount >= 20) {
		BackRedMoving =+ BackRedCount;
	}

	BackRedCount++;
}
*/
void Model::KartSpin() {
	if (SpinCount == 120) {
		SpinCount = 0;
		Spin = 0;
	}

	if (SpinCount >= 20) {
		Spin =+ SpinCount * 20;
	}
	

	SpinCount++;
}

void Model::Shoot() {
	if (ShootCount == 120) {
		ShootCount = 0;
	}

	if (ShootCount <= 16) {
		TurtleShoot =+ ShootCount * 2;
	}
	else {
		TurtleShoot = 200;
	}

	ShootCount++;
}

void Model::AnimatingGreen() {
	if (GreenCount == 120) {
		GreenCount = 0;
	}

	if (GreenCount <= 60) {
		GreenMoving =+ GreenCount;
	}
		
	GreenCount++;
}

void Model::AnimatingRedXpos() {
	if (RedXposCount == 120) {
		RedXposCount = 0;
		RedXpos = 0;
		BackRedCount = 0;
	}

	if (20 < RedXposCount && RedXposCount < 50) {
		RedXpos =- BackRedCount;
		BackRedCount++;
	}

	RedXposCount++;
}

void Model::AnimatingMain() {
	AnimatingBG();
	Shoot();
	KartSpin();
	AnimatingGreen();
	AnimatingRed();
	AnimatingRedXpos();
	//AnimatingBackRed();
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void Model::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

	bool animation = ModelerApplication::Instance()->GetAnimation();
	
	if (animation) {
		AnimatingMain();
	}
	
	glPushMatrix();
	glTranslated(0, 0, Moving);
	Background();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.4, 0.4, 0.4);
	glTranslated(RedXpos, 0, RedMoving);
	glTranslated(VAL(KART_XPOS), VAL(KART_YPOS), VAL(KART_ZPOS));
	glRotated(Spin, 0, 1, 0);
	MarioKart();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(0.4, 0.4, 0.4);
	glTranslated(5, 0, -80);
	glTranslated(0, 0, GreenMoving * 2);
	LuigiKart();
	glPopMatrix();

	glTranslated(0, 0, 0);
	glTranslated(-1, 0, -30);
	glTranslated(0, 0, TurtleShoot);
	Turtle();

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];
	//controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	//controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	//controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	//controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	//controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[LEFTARMANGLE] = ModelerControl("Left Arm Rotate", -90, 90, 1, 0);
	controls[LHAND_X] = ModelerControl("X Position of Right Hand", -5, 5, 0.1f, 0);
	controls[LHAND_Y] = ModelerControl("Y Position of Right Hand", 0, 5, 0.1f, 0);
	controls[LHAND_Z] = ModelerControl("Z Position of Right Hand", -5, 5, 0.1f, 0);
	controls[RIGHTARMANGLE] = ModelerControl("Right Arm Rotate", -90, 90, 1, 0);
	controls[RHAND_X] = ModelerControl("X Position of Left Hand", -5, 5, 0.1f, 0);
	controls[RHAND_Y] = ModelerControl("Y Position of Left Hand", 0, 5, 0.1f, 0);
	controls[RHAND_Z] = ModelerControl("Z Position of Left Hand", -5, 5, 0.1f, 0);
	//controls[HEAD] = ModelerControl("Head Rotate", -90, 90, 1, 0);
	controls[KART_XPOS] = ModelerControl("X Position of Kart", -5, 5, 0.1f, 0);
	controls[KART_YPOS] = ModelerControl("Y Position of Kart", 0, 5, 0.1f, 0);
	controls[KART_ZPOS] = ModelerControl("Z Position of Kart", -5, 5, 0.1f, 0);
	//controls[ANIMATION] = ModelerControl("Luigi shoots a turtle", 0, 120, 0.1f, 0);

	ModelerApplication::Instance()->Init(&createModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}