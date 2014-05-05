#pragma once

#include "abstractRecognizer.h"
#include "GeometricForms.h"
#include "nearestposgridgesturesmanager.h"
#include "rectanglegesturesmanager.h"

static const int gridStarSize = 150;
static const int scaleGestSize = 1000;
const double weightMix1 = 0.8;
const double weightMix2 = 1 - weightMix1;

class GridStarManager : public GesturesRecognizer<QList<int> >
{
public:
	GridStarManager();
	double getMaxDistance(QString const &);
	bool isMultistroke();
	double getDistance(QList<int> const & key1, QList<int> const & key2);
	QList<int> getKey(PathVector const & path);

private:
	PathVector addPointsVector(PathVector path);
	PathVector deleteClosePoints(PathVector path);
	PathVector pointToGrid(PathVector path);
	double dist(QPoint first, QPoint second);
};


class MixedStarGesturesManager : public GesturesRecognizer<QPair<QList<int>, double *> >
{
public:
	MixedStarGesturesManager() {}

	double getMaxDistance(QString const &)
	{
		return 10000;
	}

	bool isMultistroke()
	{
		return true;
	}

	double getDistance(QPair<QList<int>, double *> const & key1, QPair<QList<int>, double *> const & key2)
	{
		double dist1 = (new GridStarManager())->getDistance(key1.first, key2.first);
		double dist2 = (new NearestPosGridGesturesManager())->getDistance(key1.second, key2.second);
		return dist1 * weightMix1 + dist2 * weightMix2;

	}

	QPair<QList<int>, double *> getKey(PathVector const & path)
	{
		QList<int> key1 = (new GridStarManager())->getKey(path);
		double * key2 = (new NearestPosGridGesturesManager())->getKey(path);
		return QPair<QList<int>, double *>(key1, key2);

	}
};
