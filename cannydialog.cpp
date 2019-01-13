#include "cannydialog.h"
#include "ui_cannydialog.h"

CannyDialog::CannyDialog(cv::Mat g_img,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CannyDialog)
{
    ui->setupUi(this);

    //ui->setupUi(this);
    ui->cannyLabel->setScaledContents(true);
    g_imgCanny=g_img;
    tmrTimer = new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
    tmrTimer->start(20);
    qDebug() << "The current thread is " << QThread::currentThreadId();
    //ui->cannyLabel->setText();
}

CannyDialog::~CannyDialog()
{
    delete ui;
}
void CannyDialog::processFrameAndUpdateGUI(){

    orignalImage=g_imgCanny;
    if(orignalImage.empty()==true) return;
    cv::cvtColor(orignalImage,orignalImage,CV_BGR2GRAY);
    cv::Canny(orignalImage,orignalImage,10,350);
    QImage qimageOriginal=  QImage( orignalImage.data,orignalImage.cols, orignalImage.rows,static_cast<int>(orignalImage.step),QImage::Format_Grayscale8 );
    ui->cannyLabel->setPixmap(QPixmap::fromImage(qimageOriginal));
}
