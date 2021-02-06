#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    h_limit = 500;
    v_limit = 400;
    timer = new QTimer(this);
    timer->start(15);


    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    QBrush brush(Qt::yellow);

    ofensivo = new grafbola(1);
    scene->addItem(ofensivo);
    plataforma = scene->addRect(0,v_limit-20,50,20,pen,brush);
    plataforma2 = scene->addRect(h_limit-50,250,50,20,pen,brush);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::actualizar()//Función para evaluar las condiciones de impacto de player1 definidas en bordercoliision
{
        ofensivo->actualizar(v_limit);


}
