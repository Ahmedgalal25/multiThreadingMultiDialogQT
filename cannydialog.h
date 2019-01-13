#ifndef CANNYDIALOG_H
#define CANNYDIALOG_H

#include <QDialog>
#include<QTimer>
#include<QThread>
#include<chrono>
#include<QDebug>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>
#include<opencv2/objdetect.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
namespace Ui {
class CannyDialog;
}

class CannyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CannyDialog(cv::Mat img,QWidget *parent = nullptr);
    ~CannyDialog();
    QImage qimageOriginal;
    QTimer* tmrTimer;
    cv::Mat getImge();
    cv::Mat orignalImage;
    cv::Mat g_imgCanny;

public slots:
    void processFrameAndUpdateGUI();
private:
    Ui::CannyDialog *ui;
};

#endif // CANNYDIALOG_H
