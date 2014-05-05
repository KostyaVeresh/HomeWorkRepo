#include "matrixDistManager.h"
#include "curveKeyBuilder.h"
#include "QDebug"


MatrixDistManager::MatrixDistManager()
{
}

double MatrixDistManager::getMaxDistance(const QString &object)
{
	return 10000;
}

bool MatrixDistManager::isMultistroke()
{
	return true;
}

double MatrixDistManager::getDistance(double ** const &key1, double ** const &key2)
{
	return 0;
}

double ** MatrixDistManager::getKey(const PathVector &path)
{
	double **matrix = new double*[path.size()];
	for (int i = 0; i < 5; ++i)
		matrix[i] = new double[path.size()];
	foreach (PointVector path1, path)
	{
		foreach (PointVector path2, path)
		{
			PathVector vectPath1;
			PathVector vectPath2;
		}
	}
	return matrix;
}

PointVector MatrixDistManager::scalePath(PointVector path)
{
	PathVector vect;
	vect.append(path);
	int height = KeyBuilder::lowerBound(vect) - KeyBuilder::upperBound(vect);
	int width = KeyBuilder::rightBound(vect) - KeyBuilder::leftBound(vect);
	return vect[0];

}
