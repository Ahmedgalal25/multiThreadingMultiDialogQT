#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include "mythread.h"
#include<chrono>
#include<QTimer>
#include<QDebug>
#include<QThread>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>
#include<opencv2/objdetect.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MyThread *mThread;
    cv::VideoCapture cap;
    cv::Mat matOriginal;
    cv::Mat g_img;

    QImage qimageOriginal;
    QTimer* tmrTimer;

private:
    Ui::MainWindow *ui;

signals:
    void signalFun(cv::Mat);

public slots:

    void processFrameAndUpdateGUI1();
private slots:
    void on_start_clicked();
    void on_stop_clicked();
};

#endif // MAINWINDOW_H
