#include "gridStarManager.h"
#include "curveKeyBuilder.h"
#include "QDebug"
#include "qmath.h"


GridStarManager::GridStarManager()
{
}

double GridStarManager::getMaxDistance(QString const &)
{
	return 1000;
}

bool GridStarManager::isMultistroke()
{
	return true;
}

double GridStarManager::getDistance(QList<int> const & key1, QList<int> const & key2)
{
	int m = key1.size();
	int n = key2.size();
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	double matrix[m + 1][n + 1];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j ==0 )
				matrix[i][j] = std::max(i, j);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			double dist = qAbs(key1[i - 1] - key2[j - 1]);
			int aboveCell = matrix[i - 1][j];
			int leftCell = matrix[i][j - 1];
			int diagonalCell = matrix[i - 1][j - 1];
			matrix[i][j] = std::min((double) std::min(aboveCell + 3, leftCell + 3),
									diagonalCell + dist);
		}
	}
	return (double) (matrix[m][n] * (abs(m - n) + 1)) / std::min(n, m);
}

QList<int> GridStarManager::getKey(PathVector const & path)
{
	QList<int> list;
	PathVector newPath = pointToGrid(addPointsVector(KeyBuilder::scaleGesture(path, scaleGestSize)));
	foreach (PointVector vect, newPath)
	{
		int num = 0;
		QPoint first;
		QPoint second;
		while (num + 1 < vect.size())
		{
			first = vect[num];
			second = vect[num + 1];
			if (first.y() == second.y()) {
				if (first.x() < second.x())
					list.append(0);
				else
					list.append(4);
			}
			else {
				if (first.x() == second.x()) {
					if (first.y() < second.y())
						list.append(2);
					else
						list.append(6);
				}
				else {
					if (first.x() < second.x())	{
						if (first.y() < second.y())
							list.append(1);
						else
							list.append(7);
					}
					else {
						if (first.y() < second.y())
							list.append(3);
						else
							list.append(5);
					}
				}
			}
			++num;
		}
	}
	return list;
}

PathVector GridStarManager::addPointsVector(PathVector path)
{
	PathVector newPath;
	foreach (PointVector vect, path)
	{
		PointVector newVect;
		int num = 0;
		QPoint first;
		QPoint second;
		while (num + 1 < vect.size())
		{
			first = vect[num];
			second = vect[num + 1];
			newVect.append(first);
			int countNewPoints = qRound(sqrt((first.x() - second.x()) * (first.x() - second.x())
				+ (first.y() - second.y()) * (first.y() - second.y()))
				/ sqrt(gridStarSize * gridStarSize + gridStarSize * gridStarSize));
			for (int i = 1; i < countNewPoints + 1; ++i)
			{
				int newX = first.x() + (second.x() - first.x()) * i / (countNewPoints + 1);
				int newY = first.y() + (second.y() - first.y()) * i / (countNewPoints + 1);
				newVect.append(QPoint(newX, newY));
			}
			++num;
		}
		newVect.append(vect.last());
		newPath.append(newVect);
	}
	return newPath;
}

PathVector GridStarManager::pointToGrid(PathVector path)
{
	PathVector newPath;
	foreach (PointVector vect, path)
	{
		PointVector newVect;
		foreach (QPoint point , vect)
		{
			QPoint addPoint = QPoint(qRound(point.x() / (double) gridStarSize), qRound(point.y() / (double) gridStarSize));
			if (newVect.isEmpty())
				newVect.append(addPoint);
			else
				if (newVect.last() != addPoint)
					newVect.append(addPoint);
		}
		newPath.append(newVect);
	}
	return newPath;
}
