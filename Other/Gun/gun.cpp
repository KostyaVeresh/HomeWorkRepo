#include "gun.h"
#include "qmath.h"

Gun::Gun(QObject *parent) :
QObject(parent)
{
}

Gun::Gun(
		QGraphicsScene *scene
		, QPushButton *button
		, QPushButton *clButton
		, QSlider *slider
		, QSlider *speedSlider
		)
		: mAngle(M_PI/4)
		, mSpeed(7)
		, mBulletStartX((length + 1) * qCos(mAngle))
		, mBulletStartY((length + 1) * qSin(mAngle))
		, mBulletX(mBulletStartX)
		, mBulletY(mBulletStartY)
		, mTimeDelay(100 / (mSpeed * qCos(mAngle)))
		, mBullet(NULL)
		, mBulletIsOnTheScene(false)
		, mBulletIsFlying(false)
{
	this->mScene = scene;
	this->mTimer = new QTimer(this);
	connect(button, SIGNAL(clicked()), this, SLOT(shoot()));
	connect(clButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
	connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(rotateGun(int)));
	connect(speedSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeSpeed(int)));
	connect(mTimer, SIGNAL(timeout()), this, SLOT(moveBullet()));
	createGunLines();
	mScene->addItem(mGunLine1);
	mScene->addItem(mGunLine2);
	mScene->addItem(mGunLine3);
	this->mSpeedSlider = speedSlider;
	this->mSlider = slider;
}

void Gun::createGunLines()
{
	qreal const length1 = calibre / 2 / qSin(mAngle);
	qreal const length2 = length - length1 * qCos(mAngle);
	mGunLine1 = new QGraphicsLineItem(
			length1
			, 0
			, length1 + length2 * qCos(mAngle)
			, -length2 * qSin(mAngle)
			);

	qreal const length3 = length1 * qTan(mAngle);
	qreal const length4 = length - length3 * qSin(mAngle);
	mGunLine2 = new QGraphicsLineItem(
			0
			, -length3
			, length4 * qCos(mAngle)
			, -length3 - length4 * qSin(mAngle)
			);

	mGunLine3 = new QGraphicsLineItem(
			length1 + length2 * qCos(mAngle)
			, -length2 * qSin(mAngle)
			, length4 * qCos(mAngle)
			, -length3 - length4 * qSin(mAngle)
			);
}

qreal Gun::getBulletX()
{
	return this->mBulletX;
}

qreal Gun::getBulletY()
{
	return this->mBulletY;
}

void Gun::printGun()
{
	qreal const length1 = calibre / 2 / qSin(mAngle);
	qreal const length2 = length - length1 * qCos(mAngle);
	mGunLine1->setLine(
			length1
			, 0
			, length1 + length2 * qCos(mAngle)
			, -length2 * qSin(mAngle)
			);
	qreal const length3 = length1 * qTan(mAngle);
	qreal const length4 = length - length3 * qSin(mAngle);
	mGunLine2->setLine(
			0
			, -length3
			, length4 * qCos(mAngle)
			, -length3 - length4 * qSin(mAngle)
			);
	mGunLine3->setLine(
			length1 + length2 * qCos(mAngle)
			, -length2 * qSin(mAngle)
			, length4 * qCos(mAngle)
			, -length3 - length4 * qSin(mAngle)
			);
 }

void Gun::shoot()
{
	if (mBulletIsOnTheScene) {
		return;
	}

	this->mBullet = new Bullet(this, mScene);
	mBulletIsOnTheScene = true;
	mBulletIsFlying = true;
	moveBullet();
}

void Gun::onClearButtonClicked()
{
	if (!mBulletIsOnTheScene) {
		return;
	}

	mTimer->stop();
	this->mBulletX = mBulletStartX;
	this->mBulletY = mBulletStartY;
	delete this->mBullet;
	mBulletIsOnTheScene = false;
	mSpeed = mSpeedSlider->value();
	rotateGun(mSlider->value());
}

void Gun::moveBullet()
{
	mBulletX = mBulletX + 10;
	int const coord = mBulletX - mBulletStartX;
	mBulletY = mBulletStartY + coord * qTan(mAngle) - qPow(coord, 2) * 9.8
			/ 100 / (2 * qPow(mSpeed * qCos(mAngle), 2));
	if (mBulletY <= 5) {
		mTimer->stop();
		mBulletIsFlying = false;
		return;
	}

	mBullet->setCoordinateX(mBulletX);
	mBullet->setCoordinateY(mBulletY);
	mBullet->printBullet();
	mTimer->start(mTimeDelay);
}

void Gun::rotateGun(int newAngle)
{
	if (mBulletIsFlying) {
		return;
	}

	mAngle = newAngle * M_PI / 180;
	this->mBulletStartX = (length + 1) * qCos(mAngle);
	this->mBulletStartY = (length + 1) * qSin(mAngle);
	this->mBulletX = mBulletStartX;
	this->mBulletY = mBulletStartY;
	printGun();
}

void Gun::changeSpeed(int newSpeed)
{
	if (mBulletIsFlying) {
		return;
	}

	mSpeed = newSpeed;
}

Gun::~Gun()
{
	delete mGunLine1;
	delete mGunLine2;
	delete mGunLine3;
}
