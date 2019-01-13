#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
     //high_resolution_clock::time_point t1 = high_resolution_clock::now();
   cap.open(0);
   //high_resolution_clock::time_point t2 = high_resolution_clock::now();
   //float duration = duration_cast<milliseconds>( t2 - t1 ).count();
   QString s;
   //s.setNum(duration);
   //ui->label_2->setText(s+" msec");
    qDebug() << "The main thread is " << QThread::currentThreadId();

   if(!cap.isOpened()){
      // ui->statues->setText("Error webcam not acessed sucesfully");
   }
   tmrTimer = new QTimer(this);
   connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI1()));
   tmrTimer->start(20);

    mThread = new MyThread(this);
    connect(this,SIGNAL(signalFun(cv::Mat)),mThread,SLOT(slotFun(cv::Mat)));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_start_clicked()
{
    mThread->start();
    emit signalFun(g_img);
    mThread->Stop= false;
}

void MainWindow::on_stop_clicked()
{
    mThread->Stop=true;
}
void MainWindow::processFrameAndUpdateGUI1(){
    cap.read(matOriginal);
    if(matOriginal.empty()==true) return;

    cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
    g_img=matOriginal;
   QImage qimageOriginal=  QImage( matOriginal.data,matOriginal.cols, matOriginal.rows,static_cast<int>(matOriginal.step),QImage::Format_RGB888 );
    ui->label->setPixmap(QPixmap::fromImage(qimageOriginal));
}
