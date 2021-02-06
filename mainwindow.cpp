#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    h_limit = 800;
    v_limit = 400;
    timer = new QTimer(this);
    timer->start(1000);


    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());




    //ofensivo->set
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::actualizar()//Función para evaluar las condiciones de impacto de player1 definidas en bordercoliision
{
    for (int i = 0;i< bars.size() ;i++ ) {
        bars.at(i)->actualizar(v_limit);
        //borderCollision(bars.at(i)->getEsf());
    }
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    name=ui->lineEdit->text();
    name2=ui->lineEdit_2->text();
    name3=ui->lineEdit_3->text();
    float posHo=name.toFloat();
    float posHd=name2.toFloat();
    float disD=name3.toFloat();

    QBrush brush(Qt::yellow);



    plataforma = scene->addRect(0,v_limit-20,50,20,pen,brush);
    plataforma2 = scene->addRect(h_limit-50,250,50,20,pen,brush);

    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    float V0o = 0;
    int t = 0;
    int angle = 0;

    timer->start(3);
    bars.push_back(new grafbola(1));
    bars.back()->actualizar(v_limit);
    scene->addItem(bars.back());

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    for(V0o = 20; V0o<(posHd*4); V0o += 1){
        for(angle = 1; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0;t<300 ; t++){
                x = Vxo*t;
                y = posHo + Vy0*t -(0.5*10*t*t);
                if(sqrt(pow((disD - x),2)+pow((posHd - y),2)) < (0.05*disD)){
                    if(y<0){ y = 0;}
                    timer->start(3);
                    bars.push_back(new grafbola(1));
                    bars.back()->actualizar(v_limit);
                    scene->addItem(bars.back());
                    flag += 1;
                    V0o += 1;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3){ break;}

        }
        if(flag == 3){ break;}
    }



}
