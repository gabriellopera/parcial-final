#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "grafbola.h"
#include "bola.h"
#define pi 3.141617
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void actualizar();

private slots:
    void on_textEdit_copyAvailable(bool b);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *plataforma, *plataforma2;
    QPen pen;
    QTimer *timer;
    QList<grafbola *> bars;
    grafbola *ofensivo, *defensivo;
    int h_limit, v_limit;
    QString name,name2,name3;

};
#endif // MAINWINDOW_H
