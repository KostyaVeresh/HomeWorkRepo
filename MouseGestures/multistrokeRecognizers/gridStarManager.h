#pragma once

#include "abstractRecognizer.h"
#include "GeometricForms.h"

static const int gridStarSize = 25;
static const int scaleGestSize = 300;

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
	PathVector pointToGrid(PathVector path);
};
