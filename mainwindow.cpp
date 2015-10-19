#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTimer>
#include <QFile>
#include <QFileInfo>
#include <QTextFormat>
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <QMenu>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //discoveryAgent = new QBluetoothDeviceDiscoveryAgent();

    ui->setupUi(this);
    VALEURSON = 50;
    ui->label_3->setText(QString::number(VALEURSON));
    ui->label->setStyleSheet("color : #DD0A21 ");
    //Bouton 1
    QFile fichier("/storage/sdcard0/Download/img/ar.png");
    if(fichier.exists()) {
        qDebug("Bouton_0");
    ui->pushButton->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/ar.png);""background-repeat: no-repeat;""background-position: center;");
    }
    //Bouton2
    QFile fichier1("/storage/sdcard0/Download/img/fr.png");
    if(fichier1.exists()){
        ui->pushButton_2->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/fr.png);""background-repeat: no-repeat;""background-position: center;");
    }
    fichier1.close();

    QFile fichierB_R("/storage/sdcard0/Download/img/B_Right.png");
    if(fichierB_R.exists()){
        ui->pushButton_6->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/B_Right.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierB_R.close();

    QFile fichierB_TOP("/storage/sdcard0/Download/img/B_TOP.png");
    if(fichierB_TOP.exists()){
        ui->pushButton_3->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/B_TOP.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierB_TOP.close();

    QFile fichierB_BOT("/storage/sdcard0/Download/img/B_BOT.png");
    if(fichierB_BOT.exists()){
        ui->pushButton_4->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/B_BOT.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierB_BOT.close();

    QFile fichierB_L("/storage/sdcard0/Download/img/B_Left.png");
    if(fichierB_L.exists()){
        ui->pushButton_5->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/B_Left.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierB_L.close();
    QFile fichierV_L("/storage/sdcard0/Download/img/V_L.png");
    if(fichierV_L.exists()){
        ui->pushButton_8->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/V_L.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierV_L.close();

    QFile fichierV_M("/storage/sdcard0/Download/img/V_M.png");
    if(fichierV_M.exists()){
        qDebug("Bouton_2");
        ui->pushButton_7->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/V_M.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierV_M.close();

    QFile fichierV("/storage/sdcard0/Download/img/V.png");
    if(fichierV.exists()){
        qDebug("Bouton_2");
        ui->label_4->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/V.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierV.close();

    QFile fichierACT("/storage/sdcard0/Download/img/ACTION.png");
    if(fichierACT.exists()){
        qDebug("Bouton_2");
        ui->label_5->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/ACTION.png);""background-repeat: no-repeat;""background-position: center; ");
    }
    fichierACT.close();
    QFile fichierconf("/storage/sdcard0/Download/Pupitre/titre.txt");
    if(fichierconf.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!fichierconf.atEnd())
        {
             QString RDLINE = fichierconf.readLine();
             NamePup << RDLINE;
        }
    }
    fichierconf.close();

    tableFormat.setBorder(0);
    PupNbr = 1;
    STATE = 0;
    strPupNbr= '0' + QString::number(PupNbr);
    myNickName = client.nickName();
    CheckWifiState();
//connect(ui->SonSlider, SIGNAL(valueChanged(int)),this, SLOT(on_SonSlider_Move()));// initialis  e le slider
connect(&client, SIGNAL(newMessage(QString,QString)),
        this, SLOT(appendMessage(QString,QString)));

}
void MainWindow::appendMessage(const QString &from, const QString &message)
{
    qDebug() << "Ping Receive";
    if (from.isEmpty() || message.isEmpty())
        return;
    if (message.contains(QString::number(PupNbr) + "ping"))
    {
        STATE = 1;
        if (PupNbr < 10)
       client.sendMessage(strPupNbr + "pong");
        else
            client.sendMessage(strPupNbr + "pong");
    }


}
void MainWindow::CheckWifiState()
{
    if(STATE)
    {
        ui->label->setStyleSheet("color : #1EC81B ");

        /*
        QFile fichierC_G("/storage/sdcard0/Download/img/circle-green.png");
        if(fichierC_G.exists()){
            qDebug("Bouton_2");
            ui->label_2->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/circle-green.png);""background-repeat: no-repeat;""background-position: center; ");
        }
        fichierC_G.close();
        */
    }
    else
    {
        ui->label->setStyleSheet("color : #DD0A21 ");

        /*
        QFile fichierC_R("/storage/sdcard0/Download/img/circle-red.png");
        if(fichierC_R.exists()){
            qDebug("Bouton_2");
            ui->label_2->setStyleSheet("background-image: url( /storage/sdcard0/Download/img/circle-red.png);""background-repeat: no-repeat;""background-position: center; ");
        }
        fichierC_R.close();
        */
    }
    STATE = 0;
     QTimer::singleShot(10000, this, SLOT(CheckWifiState()));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label->setStyleSheet("color : #DD0A21 ");
    PupNbr--;
    if (PupNbr <= 1)
    {
        PupNbr = 1;
        ui->label->setText(NamePup[PupNbr - 1].mid(0,NamePup[0].count() - 1));
    }
    else
    {

    ui->label->setText(NamePup[PupNbr - 1].mid(0,NamePup[PupNbr - 1].count() - 1));
    }

    if(PupNbr <= 9)
        strPupNbr = '0' + QString::number(PupNbr);
    else
        strPupNbr= QString::number(PupNbr);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setStyleSheet("color : #DD0A21 ");
    PupNbr++;
    if (PupNbr <= NamePup.count())
    {
        ui->label->setText(NamePup[PupNbr - 1].mid(0,NamePup[PupNbr - 1].count() - 1));
    }
    else
    {
        PupNbr--;
        ui->label->setText(NamePup[PupNbr - 1].mid(0,NamePup[PupNbr - 1].count() - 1));
    }

    if(PupNbr <= 9)
        strPupNbr = '0' + QString::number(PupNbr);
    else
        strPupNbr= QString::number(PupNbr);
}
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::CheckForRfcomm()
{

}

void MainWindow::on_pushButton_clicked()
{
    client.sendMessage(strPupNbr + "!H");

}
void MainWindow::on_pushButton_2_clicked(){
    client.sendMessage(strPupNbr + "!OIFG");
}

void MainWindow::on_pushButton_7_clicked()
{
    VALEURSON = VALEURSON + 10;
    if (VALEURSON >= 100)
    {
        VALEURSON = 100;
        STRINGSON=QString::number(VALEURSON - 1);
        client.sendMessage(strPupNbr+ "!V" + STRINGSON);
    }
    else
    {
        if (VALEURSON <= 9)
        {
            STRINGSON=QString::number(VALEURSON);
            client.sendMessage(strPupNbr + "!V" + '0' +STRINGSON);
        }
        else
        {
            STRINGSON=QString::number(VALEURSON);
            client.sendMessage(strPupNbr + "!V" + STRINGSON);
        }
    }
    ui->label_3->setText(STRINGSON);
}
void MainWindow::on_pushButton_8_clicked()
{
    VALEURSON = VALEURSON - 10;
    if (VALEURSON <= 0)
    {
        VALEURSON = 0;
        STRINGSON=QString::number(VALEURSON);
        client.sendMessage(strPupNbr + "!V" + STRINGSON);
    }
    else
    {
        if (VALEURSON <= 9)
        {
        STRINGSON=QString::number(VALEURSON);
        client.sendMessage(strPupNbr +"!V"+ '0' + STRINGSON);
        }
        else
        {
            STRINGSON=QString::number(VALEURSON);
            client.sendMessage(strPupNbr + "!V" + STRINGSON);
        }
    }
    ui->label_3->setText(STRINGSON);
}
void MainWindow::on_pushButtonVar_clicked()
{
    if (ui->pushButtonVar->text().toInt() <= 9)
    {
        QString msg(strPupNbr + "!L0" + ui->pushButtonVar->text());
        client.sendMessage(msg);
        qDebug() << msg;

    }
    else
    client.sendMessage(strPupNbr + "!L" + ui->pushButtonVar->text());
    qDebug()<< ui->pushButtonVar->text();
}
void MainWindow::on_pushButton_3_clicked()
{
        if(ui->pushButtonVar->text().toInt() + 1 >= 16)
        {
            int inc = ui->pushButtonVar->text().toInt();
            if ( inc == 15 )
            {
                ui->centralWidget->setStyleSheet("background-color: #FF0000;");
            }

            ui->pushButtonVar->setText(QString::number(inc));
        }
        else
        {
        int inc = ui->pushButtonVar->text().toInt() + 1;
        if (inc == 15)
           ui->centralWidget->setStyleSheet("background-color: #FF0000;");
        else
            ui->centralWidget->setStyleSheet("background-color: #3A1400;");

        ui->pushButtonVar->setText(QString::number(inc));
        }
}

void MainWindow::on_pushButton_4_clicked()
{
        if(ui->pushButtonVar->text().toInt() - 1 <= 0)
        {
            int inc = ui->pushButtonVar->text().toInt();
            ui->pushButtonVar->setText(QString::number(inc));
        }
        else
        {
        int inc = ui->pushButtonVar->text().toInt() - 1;
        ui->pushButtonVar->setText(QString::number(inc));
        }
            ui->centralWidget->setStyleSheet("background-color: #3A1400;");
}
