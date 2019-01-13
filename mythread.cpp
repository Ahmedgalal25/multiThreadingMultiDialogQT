#include "mythread.h"


MyThread::MyThread(QObject *parent):QThread(parent)
{

}

void MyThread::run(){

    //slotFun(img);
    CannyDialog cannydialog(g_img);
    cannydialog.setWindowModality(Qt::WindowModal);
    cannydialog.exec();





}
void MyThread::slotFun(cv::Mat img){
    g_img=img;

}
