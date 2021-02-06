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
    timer->start(15);


    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    QBrush brush(Qt::yellow);



    plataforma = scene->addRect(0,v_limit-20,50,20,pen,brush);
    plataforma2 = scene->addRect(h_limit-50,250,50,20,pen,brush);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


    //ofensivo->set
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::actualizar()//Función para evaluar las condiciones de impacto de player1 definidas en bordercoliision
{
        //ofensivo->actualizar(v_limit);


}

void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    name=ui->lineEdit->text();
    velocidad=name.toFloat();


    timer->start(3);
    bars.push_back(new grafbola(1));
    bars.back()->actualizar(v_limit);
    scene->addItem(bars.back());


    for(V0o = Voo; V0o<(Hd*4); V0o += 1){
        for(angle = 1; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0;t<300 ; t++){
                x = Vxo*t;
                y = Yo + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((Xd - x),2)+pow((Yd - y),2)) < d02){
                    if(y<0) y = 0;
                    ImprimirResultados(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 1;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
