#include "bullet.h"
#include "gun.h"


Bullet::Bullet(QObject *parent) :
QObject(parent)
{
}

Bullet::Bullet(Gun *gun, QGraphicsScene *scene)
{
	this->mGun = gun;
	this->mScene = scene;
	this->mCoordinateX = gun->getBulletX();
	this->mCoordinateY = gun->getBulletY();
	this->mBulletDraw = new QGraphicsEllipseItem(mCoordinateX, -mCoordinateY, 10, 10);
	scene->addItem(mBulletDraw);
	mBulletDraw->setBrush(QBrush(Qt::black));
}

void Bullet::setCoordinateX(qreal value)
{
	this->mCoordinateX = value;
}

void Bullet::setCoordinateY(qreal value)
{
	this->mCoordinateY = value;
}

void Bullet::printBullet()
{
	mBulletDraw->setPos(mCoordinateX, -mCoordinateY);
}

Bullet::~Bullet()
{
	delete mBulletDraw;
}
