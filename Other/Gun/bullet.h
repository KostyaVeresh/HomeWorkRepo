#pragma once

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Gun;

///Bullet for the gun shooting
class Bullet : public QObject
{
	Q_OBJECT
public:
	explicit Bullet(QObject *parent = 0);

	/// Creates bullet and sets it on the scene
	/// @param mGun Gun for shooting the bullet
	/// @param mScene Scene for setting the bullet
	Bullet(Gun *mGun, QGraphicsScene *mScene);

	/// Prints bullet on scene by coordinates
	void printBullet();

	/// Changes the value of property
	/// @param value New value
	void setCoordinateX(qreal value);

	/// Changes the value of property
	/// @param value New value
	void setCoordinateY(qreal value);

	/// Deletes bullet
	~Bullet();
private:
	QGraphicsScene *mScene;
	QGraphicsEllipseItem *mBulletDraw;
	Gun *mGun;
	qreal mCoordinateX;
	qreal mCoordinateY;
};
