/*
主要功能区，提供头显成像显示，以及提供头衔设备imu|camera数据 获取途径，提供热插拔，imu、camera数据获取途径。

*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QMutex>
#include <QThread>
#include <QQueue>
#include <QDateTime>
#include <QTextCodec>
#include <QTextStream>
#include <QMainWindow>
#include <QMouseEvent>
#include <QFileDialog>
#include <QFontDatabase>
#include <QPropertyAnimation>
#include <QDesktopServices>
//外部
#include   "imr_driver.h"
#include   "driver_data.h"
//#include   "include/camera.h"
//#include   "include/utility.h"
//#include   "include/mynteye.h"
//摄像头相关
#include "opencv2/opencv.hpp"
//标准库
#include <iostream>
#include <list>
//#include <direct.h>
#include <unistd.h>
#include<fcntl.h>
#include <string>
#include "hmdabout.h"
#include "cameraabout.h"
#include "cameraabout_right.h"


using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void MainUIInit();                                               //主UI初始化
    void CameraInit();                                               //相机初始化
    static void HMDDataCollect(imrIMUData* data = NULL);             //imu 回调函数接收函数
    static void HMDDataCollectCamera(imrCameraData* camera_data);    //camera 回调接收函数
    static void HMDInOutInfo(bool in_out);                           //头显插拔 回调函数
    void AnimationControl(QObject *target, int msc, int x_s, int y_s,
                          int x_e, int y_e, int w, int h, int type); //控件动画效果
    ~MainWindow();
private slots:
    void showTimelimit_camera_show();                                //主摄像头显示
    void showTimelimit_con_state();                                  //设备连接状态
    void showTimelimit_work_show();                                  //任务状态
    void showTimelimit_camera();                                     //相机_data 采集
    void showTimelimit_imu();                                        //imu_data 采集
    void on_module_info_min_clicked();                               //窗口最小化
    void on_module_info_close_clicked();                             //窗口最大化
    void on_collect_start_clicked();                                 //开始采集
    void on_hmd_data_path_set_clicked();                             //文件存储路径
    void slot_save_isok();                                           //文件保存完毕
    //-------------------------------未使用------------------------------------------------------------
    void on_test_area_clicked();                                     //测试区域显示
    void on_imu_collect_clicked();                                   //测试区IMU数据以及图像数据采集 (误差)
    //------------------------------------------------------------------------------------------------
signals:
    void sig_imu_data_post(QList<string>);                           //头显 imu数据获取
    void sig_camera_data_post_left(QList<imrCameraData>);            //头显 图像数据获取
    void sig_camera_imu_post_left(double);                           //头显 IMU数据获取 LEFT
    void sig_camera_data_post_right(QList<imrCameraData>);           //头显 图像数据获取
    void sig_camera_imu_post_right(double);                          //头显 IMU数据获取 RIGHT
public slots:
    void mouseMoveEvent(QMouseEvent * event);                        //自定义标题部分鼠标事件
    void mousePressEvent(QMouseEvent * event );
    void mouseReleaseEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
    //-------------Timer 设置----------------------------------------
    QTimer*      m_timer_imu;                  //imu data 采集
    QTimer*      m_con_state;                  //imu camera 任务状态
    QTimer*      m_work_state;                 //采集 任务状态
    QTimer*      m_timer_camera;               //相机 data 采集
    QTimer*      m_timer_camera_show;          //相机 左右目 显示
    //-------------字符集设置------------------------------------------
    QStringList  m_fontList;                   //存放字符集
    QString      m_file_save_path;             //文件存放地址
    //-------------IMU CAMERA-LEFT|CAMERA-RIGHT----------------------
    HMDAbout*    m_hmd_about;                  //头显文件操作相关
    CameraAbout* m_camera_data;                //相机文件操作相关  LEFT
    CameraAbout_Right* m_camera_data_right;    //相机文件操作相关  RIGHT
    //--------------模组相关-------------------------------------------
    IMRDEVICE_HANDLE m_camera_pHandle;         //相机句柄
    DevicesInfo m_con_eq_info;                 //已连接设备的相关信息
    //--------------文件存储地址相关------------------------------------
    QDateTime current_date_time;               //获取系统当前时间
    QString current_date_collect;              //设置文件采集时间
    //--------------按键状态相关---------------------------------------
    QString m_common;                          //按键普通状态
    QString m_common_go;                       //按键任务执行中状态
    QString m_hover;                           //按键悬浮状态
    QString m_pressed;                         //按键点击状态
    //---------------------------------------------------------------
    int     m_work_type = -1;                  //任务类型
    //--------------自定义标题栏控制------------------------------------
    QPoint mousePosition;
    bool isMousePressed;
};

#endif // MAINWINDOW_H
