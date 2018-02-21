#include "opencv1.h"
#include "ui_opencv1.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <qmath.h>
using namespace cv;

opencv1::opencv1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::opencv1)
{
    ui->setupUi(this);
    //绑定mat控件，必须在setupUi之后
    mview = new QpMatView(ui->graphicsView);
}

opencv1::~opencv1()
{
    delete ui;
}



//显示原图  3通道图转单通道
void opencv1::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.bmp)"));

        image = cv::imread(fileName.toStdString());



    //打开图片
    //    image = imread("D:/machine vision/pic/5maoyingbi.bmp");


    //3通道图转单通道
        cvtColor(image,imagemid,CV_BGR2GRAY);



    //显示到控件上
    mview->imshow(imagemid);
}


//阈值分割
void opencv1::on_pushButton_2_clicked()
{
    //阈值分割
   threshold(imagemid,imagemid,230,255,1);

   mview->imshow(imagemid);
}


//高斯滤波
void opencv1::on_pushButton_5_clicked()
{
    GaussianBlur(imagemid, imagemid, Size(9,9), 2,2);
    mview->imshow(imagemid);
}




//边缘提取
void opencv1::on_pushButton_3_clicked()
{
    Canny(imagemid,imagemid,100,200,3);

    mview->imshow(imagemid);
}



//一键处理
void opencv1::on_pushButton_4_clicked()
{
    opencv1::on_pushButton_5_clicked();
    opencv1::on_pushButton_2_clicked();
    opencv1::on_pushButton_3_clicked();
    opencv1::on_pushButton_6_clicked();
    opencv1::on_pushButton_7_clicked();
}


//轮廓提取
void opencv1::on_pushButton_6_clicked()
{


    std::vector<Vec4i> hierarchy;

    findContours(imagemid, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));





    mview->imshow(imagemid);






}



//面积计算

void opencv1::on_pushButton_7_clicked()
{
    for(int i = 0; i < contours.size(); i ++)
    {
        if(i % 2 == 1)
        {

            result = QString::number( contourArea(contours[i]));
            ui->listWidget->addItem(result);
            if(170000<contourArea(contours[i])&&contourArea(contours[i])<180000)
            {
                yiyuan++;
            }

            if(113000<contourArea(contours[i])&&contourArea(contours[i])<115000)
            {
                wumao++;
            }
            if(96000<contourArea(contours[i])&&contourArea(contours[i])<100000)
            {
                yimao++;
            }
        }
    }

    ui->listWidget_2->addItem(QString::number( yiyuan));
    ui->listWidget_3->addItem(QString::number( wumao));
    ui->listWidget_4->addItem(QString::number( yimao));

    // 计算矩:
  /*  std::vector<Moments> mu(contours.size());
   for (int i = 0; i < contours.size(); i++)
        {
            mu[i] = moments(contours[i], false);
        }
    //  计算中心矩:
    std::vector<Point2f> mc(contours.size());
       for (int i = 0; i < contours.size(); i++)
       {
           mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
       }




       for (int i = 0; i< contours.size(); i++)
          {
              printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n",
                     i, mu[i].m00, contourArea(contours[i]), arcLength(contours[i], true));
        }

  */

}
