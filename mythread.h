#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>
#include <QDialog>
#include<QTimer>
#include<QtCore>
#include<chrono>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include"cannydialog.h"
class MyThread:public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent=nullptr);
    void run();
    bool Stop;
    cv::Mat g_img;

signals:



public slots:
    void slotFun(cv::Mat);


};

#endif // MYTHREAD_H
