#pragma once

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QTimer>
#include <QTransform>

#include "mainwindow.h"
#include "bullet.h"

class Gun : public QObject
{
	Q_OBJECT
public:
	explicit Gun(QObject *parent = 0);

	/// Creates gun and sets it on the scene
	/// @param scene Scene fo setting the gun
	/// @param button Form button for shooting the gun
	/// @param clButton Form button for returning to the start position
	/// @param slider Form slider to change angle
	/// @param speedSlider Form slider to change speed
	Gun(QGraphicsScene *scene
		, QPushButton *button
		, QPushButton *clButton
		, QSlider *slider
		, QSlider *speedSlider
	);

	/// Returnes the value of property
	qreal getBulletX();

	/// Returnes the value of property
	qreal getBulletY();

	/// Prints the gun on the scene
	void printGun();
	~Gun();
private:
	static qreal const length = 40;
	static qreal const calibre = 10;
	void createGunLines();
	qreal mAngle;
	qreal mSpeed;
	qreal mBulletStartX;
	qreal mBulletStartY;
	qreal mBulletX;
	qreal mBulletY;
	int mTimeDelay;
	QGraphicsScene *mScene;
	Bullet *mBullet;
	bool mBulletIsOnTheScene;
	bool mBulletIsFlying;
	QTimer *mTimer;
	QGraphicsLineItem *mGunLine1;
	QGraphicsLineItem *mGunLine2;
	QGraphicsLineItem *mGunLine3;
	QSlider *mSpeedSlider;
	QSlider *mSlider;

public slots:
	/// Starts the animation of gun shooting
	void shoot();

	/// Continues traectory according to the physical model
	void moveBullet();

	/// Deletes bullet from scene and returns gun to the start position
	void onClearButtonClicked();

	/// Rotates the barrel of gun
	/// @param newAngle New absolute value of angle
	void rotateGun(int newAngle);

	/// Changes initial speed of bullet
	/// @param newSpeed New absolute value of speed
	void changeSpeed(int newSpeed);
};
