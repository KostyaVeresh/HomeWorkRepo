#pragma once

#include "abstractRecognizer.h"
#include <QString>
#include <QMap>
#include <QWidget>
#include <QMouseEvent>
#include "GeometricForms.h"
#include "validpathcreator.h"
#include "pathcorrector.h"
#include "paintmanager.h"
#include "adopter.h"
#include "recognizerInterface.h"
#include "test/xmlparser.h"
#include <QDebug>

const QString pathToLearnFile = "closerNeighboursTest.xml";
static const int numberOfNeighbours = 12;

template <typename TKey>
class CloserNeighboursRecognizer : public RecognizerInterface
{
public:
	CloserNeighboursRecognizer(GesturesRecognizer<TKey> *recognizer)
	{
		mGesturesManager = recognizer;
		mLearnGestures = XmlParser::parseXml(pathToLearnFile);
	}

	void setIdealGestures(const QList<Entity> & objects)
	{
		mObjects.clear();
		QMap<QString, PathVector> gestures;
		foreach (Entity entity, objects)
		{
			PathVector paths;
			if (!mGesturesManager->isMultistroke())
				paths.push_back(ValidPathCreator::createPath(entity.second));
			else
				paths = entity.second;
			QPair<PathVector, QStringList> pair(paths, QStringList());
			mObjects.insert(entity.first, pair);
			gestures.insert(entity.first, paths);
		}
		mGesturesManager->initIdealGestures(gestures);
	}

	QString recognizeObject(PathVector const & gesture)
	{
		mGesture = gesture;
		mGesturesManager->setKey(mGesture);
		mGesture.clear();
		if (mObjects.empty())
			return "";
		QMap<QString, int> countNeighbours;
		QMap<QString, QList<double> > countDists;
		foreach (QString obj, mObjects.keys())
		{
			countNeighbours.insert(obj, 0);
		}

		TKey gestKey = mGesturesManager->getKey(gesture);

		foreach (QString object, mLearnGestures.keys())
		{
			QList<double> list;
			list.append(mGesturesManager->getDistance(gestKey, mGesturesManager->getKey(mLearnGestures[object].first)));
			countDists.insert(object, list);
			foreach (QString pathStr, mLearnGestures[object].second)
			{
				PathVector path = Parser::stringToPath(pathStr);
				TKey key = mGesturesManager->getKey(path);
				countDists[object].append(mGesturesManager->getDistance(gestKey, key));
			}
		}

		for (int i = 0; i < numberOfNeighbours; ++i)
		{
			double minDist = 10000;
			QString gest;
			foreach (QString object, countDists.keys())
			{
				foreach (double dist, countDists[object])
				{
					if (dist < minDist)
					{
						minDist = dist;
						gest = object;
					}
				}
			}
			++countNeighbours[gest];
			countDists[gest].removeAll(minDist);
		}

		int maxCount = -1;
		QString recognized = "";
		foreach (QString str, countNeighbours.keys())
		{
			if (countNeighbours[str] > maxCount)
			{
				maxCount = countNeighbours[str];
				recognized = str;
			}
		}
		return recognized;
	}

private:
	QMap<QString, QPair<PathVector, QStringList> > mObjects;
	GesturesRecognizer<TKey> * mGesturesManager;
	QMap<QString, UsersGestures> mLearnGestures;
	PathVector mGesture;
};
