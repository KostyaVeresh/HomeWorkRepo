# -------------------------------------------------
# Project created by QtCreator 2009-11-01T22:19:40
# -------------------------------------------------
QT += xml widgets
TARGET = MouseGestures
TEMPLATE = app
SOURCES += main.cpp \
	mousegestures.cpp \
	pathcorrector.cpp \
	serializer.cpp \
	validpathcreator.cpp \
	adopter.cpp \
	paintmanager.cpp \
	test/testwindow.cpp \
	test/xmlparser.cpp \
	multistrokeRecognizers/sumMultistrokeGesturesManager.cpp \
	multistrokeRecognizers/rectanglegesturesmanager.cpp \
	multistrokeRecognizers/nearestposgridgesturesmanager.cpp \
	multistrokeRecognizers/mixedgesturesmanager.cpp \
	multistrokeRecognizers/adaBoostManager.cpp \
    multistrokeRecognizers/gridStarManager.cpp \
    multistrokeRecognizers/gridStarClassifier.cpp \
    multistrokeRecognizers/matrixDistManager.cpp
	#integralrecognizer.cpp
HEADERS += mousegestures.h \
	pathcorrector.h \
	serializer.h \
	GeometricForms.h \
	validpathcreator.h \
	adopter.h \
	paintmanager.h \
	figures.h \
	abstractRecognizer.h \
	test/testwindow.h \
	test/xmlparser.h \
	multistrokeRecognizers/sorts.h \
	multistrokeRecognizers/distance.h \
	multistrokeRecognizers/curveKeyBuilder.h \
	multistrokeRecognizers/multistrokeGesturesManagers.h \
	#TrainingGesturesManager/TrainingGesturesManager.h \
	NeuralNetwork/neuralnetwork.h \
	test/testThread.h \
	multistrokeRecognizers/sumMultistrokeGesturesManager.h \
	multistrokeRecognizers/gridKeyBuilder.h \
	multistrokeRecognizers/rectanglegesturesmanager.h \
	multistrokeRecognizers/nearestposgridgesturesmanager.h \
	multistrokeRecognizers/rectangleClassifier.h \
	multistrokeRecognizers/mixedgesturesmanager.h \
	multistrokeRecognizers/adaBoostManager.h \
	recognizerInterface.h \
    multistrokeRecognizers/gridStarManager.h \
    multistrokeRecognizers/gridStarClassifier.h \
    multistrokeRecognizers/matrixDistManager.h \
    closerNeighboursRecognizer.h
	#integralrecognizer.h
FORMS += mousegestures.ui \
	test/testwindow.ui








