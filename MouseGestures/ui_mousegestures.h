/********************************************************************************
** Form generated from reading UI file 'mousegestures.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEGESTURES_H
#define UI_MOUSEGESTURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseGestures
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionTest;
    QAction *actionGenerate_gestures;
    QAction *actionSave_test_gestures;
    QAction *actionOpen_test_gestures;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGroupBox *gbGestures;
    QHBoxLayout *horizontalLayout;
    QTableWidget *twObjectPathTable;
    QGraphicsView *gvGesture;
    QGraphicsView *gvEditGesture;
    QTextEdit *teObject;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTraininng_algorithm;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MouseGestures)
    {
        if (MouseGestures->objectName().isEmpty())
            MouseGestures->setObjectName(QStringLiteral("MouseGestures"));
        MouseGestures->resize(913, 601);
        MouseGestures->setDockNestingEnabled(true);
        MouseGestures->setProperty("autoScrillMargin", QVariant(true));
        actionOpen = new QAction(MouseGestures);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MouseGestures);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionTest = new QAction(MouseGestures);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionGenerate_gestures = new QAction(MouseGestures);
        actionGenerate_gestures->setObjectName(QStringLiteral("actionGenerate_gestures"));
        actionSave_test_gestures = new QAction(MouseGestures);
        actionSave_test_gestures->setObjectName(QStringLiteral("actionSave_test_gestures"));
        actionOpen_test_gestures = new QAction(MouseGestures);
        actionOpen_test_gestures->setObjectName(QStringLiteral("actionOpen_test_gestures"));
        centralWidget = new QWidget(MouseGestures);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(widget);

        gbGestures = new QGroupBox(centralWidget);
        gbGestures->setObjectName(QStringLiteral("gbGestures"));
        gbGestures->setMinimumSize(QSize(489, 0));
        horizontalLayout = new QHBoxLayout(gbGestures);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        twObjectPathTable = new QTableWidget(gbGestures);
        if (twObjectPathTable->columnCount() < 1)
            twObjectPathTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twObjectPathTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        twObjectPathTable->setObjectName(QStringLiteral("twObjectPathTable"));
        twObjectPathTable->setMinimumSize(QSize(100, 0));
        twObjectPathTable->setAutoFillBackground(false);

        horizontalLayout->addWidget(twObjectPathTable);

        gvGesture = new QGraphicsView(gbGestures);
        gvGesture->setObjectName(QStringLiteral("gvGesture"));
        gvGesture->setMinimumSize(QSize(300, 101));

        horizontalLayout->addWidget(gvGesture);

        gvEditGesture = new QGraphicsView(gbGestures);
        gvEditGesture->setObjectName(QStringLiteral("gvEditGesture"));

        horizontalLayout->addWidget(gvEditGesture);


        verticalLayout->addWidget(gbGestures);

        teObject = new QTextEdit(centralWidget);
        teObject->setObjectName(QStringLiteral("teObject"));
        teObject->setMaximumSize(QSize(16777215, 25));
        teObject->setReadOnly(true);

        verticalLayout->addWidget(teObject);

        MouseGestures->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MouseGestures);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 913, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTraininng_algorithm = new QMenu(menuBar);
        menuTraininng_algorithm->setObjectName(QStringLiteral("menuTraininng_algorithm"));
        MouseGestures->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MouseGestures);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MouseGestures->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MouseGestures);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MouseGestures->setStatusBar(statusBar);
        toolBar = new QToolBar(MouseGestures);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MouseGestures->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTraininng_algorithm->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_test_gestures);
        menuFile->addAction(actionSave_test_gestures);
        menuFile->addAction(actionTest);
        menuTraininng_algorithm->addAction(actionGenerate_gestures);

        retranslateUi(MouseGestures);

        QMetaObject::connectSlotsByName(MouseGestures);
    } // setupUi

    void retranslateUi(QMainWindow *MouseGestures)
    {
        MouseGestures->setWindowTitle(QApplication::translate("MouseGestures", "MouseGestures", 0));
        actionOpen->setText(QApplication::translate("MouseGestures", "Open", 0));
        actionSave->setText(QApplication::translate("MouseGestures", "Save", 0));
        actionTest->setText(QApplication::translate("MouseGestures", "Test", 0));
        actionGenerate_gestures->setText(QApplication::translate("MouseGestures", "Generate gestures", 0));
        actionSave_test_gestures->setText(QApplication::translate("MouseGestures", "Save test gestures", 0));
        actionOpen_test_gestures->setText(QApplication::translate("MouseGestures", "Open test gestures", 0));
        gbGestures->setTitle(QApplication::translate("MouseGestures", "Gestures", 0));
        QTableWidgetItem *___qtablewidgetitem = twObjectPathTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MouseGestures", "object", 0));
        menuFile->setTitle(QApplication::translate("MouseGestures", "File", 0));
        menuTraininng_algorithm->setTitle(QApplication::translate("MouseGestures", "Traininng algorithm", 0));
        toolBar->setWindowTitle(QApplication::translate("MouseGestures", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MouseGestures: public Ui_MouseGestures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEGESTURES_H
