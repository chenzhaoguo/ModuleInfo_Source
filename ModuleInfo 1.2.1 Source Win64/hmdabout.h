/*
主要用以获取 头衔设备的imu、camera信息，另外加入了根据相关规则采集误差信息的功能。
误差标准：imu > 2ms;
        camera > 25ms
*/
#ifndef HMDABOUT_H
#define HMDABOUT_H

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
#define basetime 1000000000000000000

class HMDAbout : public QObject
{
    Q_OBJECT
public:
    HMDAbout();
    void setFileSavePath(QString filePath);                       //设置文件存放地址
    void setCollectState(bool imu_state,QString time);            //设置采集状态 IMU
    void setIMUCameraOnOff(bool IMU_state);                       //设置单独采集开关 IMU|Camera 误差
    ~HMDAbout();

private slots:
    void slot_setIMUData(QList<string> data);                     //获取设备返回的imu数据
private:
    QString imu_camera_file_path;                                 //文件存放地址
    QString m_time;                                               //创建时间
    bool    m_state_imu = false;                                  //采集状态  IMU
    bool    m_imu_on_off = false;                                 //imu 误差采集开关
    QList<QString> m_imu_data_box;                                //存放imu数据集合
};

#endif // HMDABOUT_H
