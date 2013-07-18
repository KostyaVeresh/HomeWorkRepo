#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gun.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	scene = new QGraphicsScene;
	ui->graphicsView->setScene(scene);
	ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
	gun = new Gun(
		scene
		, ui->startButton
		, ui->clearButton
		, ui->rotateSlider
		, ui->speedSlider
	);
	gun->printGun();
}

MainWindow::~MainWindow()
{
	delete ui;
	delete gun;
}
