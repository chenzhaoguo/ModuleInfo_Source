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
#include <iostream>
#include <QDateTime>

#include <fstream>

#include "driver_data.h"
#include "imr_driver.h"

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
    void setCollectStateCamera(bool camera_state,QString time);   //设置采集状态 Camera
    void setIMUCameraOnOff(bool IMU_state);                       //设置单独采集开关 IMU|Camera 误差
    ~CameraAbout();

private slots:
    void slot_setCameraData(imrCameraData data);                  //获取设备返回的相机数据
private:
    QString imu_camera_file_path;                                 //文件存放地址
    QString m_time;                                               //创建时间
    bool    m_state_camera = false;                               //采集状态  Camera
    bool    m_camera_on_off = false;                              //camera 误差采集开关
    QImage* m_image = NULL;                                       //待保存图像
};

#endif // CAMERAABOUT_H
