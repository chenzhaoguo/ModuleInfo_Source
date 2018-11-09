/*
主要用以获取 头衔设备的imu、camera信息，另外加入了根据相关规则采集误差信息的功能。
误差标准：imu > 2ms;
        camera > 25ms
*/
#ifndef CAMERAABOUT_H
#define CAMERAABOUT_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QMutex>
#include <QImage>
#include <QThread>
#include <QObject>
#include <QScreen>
#include <QMutex>
#include <iostream>
#include <QDateTime>
#include <opencv2/opencv.hpp>
#include <fstream>

#include "driver_data.h"
#include "imr_driver.h"

using namespace cv;
using namespace std;
#define _G0 9.8019967f
#define PI 3.141593
#define basetime 1000000000000000000

class CameraAbout : public QObject
{
    Q_OBJECT
public:
    CameraAbout();
    void setFileSavePath(QString filePath);                       //设置文件存放地址
    void OpenFile();                                              //打开文件存储
    void setCollectStateCamera(bool camera_state,QString time);   //设置采集状态 Camera
    void setFileClose();                                          //关闭文件
    void getNowDataNum(int num);                                  //获取写入的文件数量 imu_camera
    ~CameraAbout();

private slots:
    void slot_setCameraData(QList<imrCameraData> data);           //获取设备返回的相机数据
    void slot_setCameraImu(double imu);
signals:
    void sig_save_ok();                                           //文件保存完毕
private:
    QString imu_camera_file_path;                                 //文件存放地址
    QString m_time;                                               //创建时间
    bool    m_state_camera = false;                               //采集状态  Camera
    bool    m_camera_on_off = false;                              //camera 误差采集开关
    QImage* m_image = NULL;                                       //待保存图像
    QString cam0_data = "";                                       //文件的存储地址
    QFile   new_imu_data_0;                                       //文件操作句柄
    QTextStream *imu_data_0;                                      //文件读写句柄
    int     m_imu_camera_num = 0;                                 //imu_camera 实际存储数量
    int     now_num = 0;                                          //当前存储数量
};

#endif // CAMERAABOUT_H
