#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "androidrfcomm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    QStringList global_devicemac;
    QStringList global_devicename;
    const QString MACHINENAME("RNB");

    rfcomm= new AndroidRfComm();

    QMap<QString,QString> map=rfcomm->getPairedDevices();
    QMapIterator<QString,QString> iterator(map);

    if (rfcomm->isEnabled()) {

        while (iterator.hasNext()) {

            iterator.next();
            QString InfosMAC=iterator.key();
            QString InfosNAME=iterator.value();

            if(InfosNAME.contains(MACHINENAME)){

                global_devicename << InfosNAME;
                global_devicemac << InfosMAC;
                rfcomm->connect(global_devicename[0]);
            }

            ui->label->setText(global_devicename[0]);


        }

    }
}

void MainWindow::on_pushButton_2_clicked(){

    rfcomm->sendLine(" ''WIKO'' ecrit depuis le bluetooth de ma savonette");

}
