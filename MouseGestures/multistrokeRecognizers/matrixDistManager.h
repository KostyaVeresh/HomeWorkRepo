#pragma once

#include "abstractRecognizer.h"
#include "GeometricForms.h"

static const int scaleHeight = 500;
static const int scaleWidth = 500;

class MatrixDistManager : GesturesRecognizer<double **>
{
public:
	MatrixDistManager();
	double getMaxDistance(const QString &object);
	bool isMultistroke();
	double getDistance(double ** const &key1, double ** const &key2);
	double ** getKey(const PathVector &path);
private:
	PointVector scalePath(PointVector path);
};
