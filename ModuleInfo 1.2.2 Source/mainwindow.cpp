#include "mainwindow.h"
#include "ui_mainwindow.h"

//标题栏的长度
const static int pos_min_x = 0;
const static int pos_max_x = 450;       //控制x轴可选长度
const static int pos_min_y = 0;
const static int pos_max_y = 30;        //控制y轴可选长度

QThread*     m_thread;                  //文件操作线程 -IMU
QThread*     m_thread_camera;           //相机文件操作线程 -LEFT
QThread*     m_thread_camera_right;     //相机文件操作线程 -RIGHT

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //热插拔激活
    imrSetHMDHotplugCallback(MainWindow::HMDInOutInfo);
    //主UI初始化 设置初始化
    MainUIInit();
    //模组部分初始化
    CameraInit();
}
//主UI初始化
void MainWindow::MainUIInit(){
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明，允许鼠标穿过
    setWindowFlags(Qt::FramelessWindowHint);//去除窗口标题栏
    //setWindowFlags(Qt::Window|Qt::FramelessWindowHint |Qt::WindowSystemMenuHint|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);
    //resize(750,290);
    resize(450,290);
    //加载自定义字体集
    int lcdFontId = QFontDatabase::addApplicationFont(":/Azo Sans/Rui Abreu - AzoSans-Medium.otf"); // 从source资源文件
    if (lcdFontId != -1) // -1为加载失败
    {
        m_fontList << QFontDatabase::applicationFontFamilies(lcdFontId);
        ui->module_title->setFont(m_fontList.at(0));
    }

    //获取当前时间  设置文件夹日期
    current_date_time = QDateTime::currentDateTime();
    current_date_collect = current_date_time.toString(QString::fromLocal8Bit("yyyy-MM-dd_hh_mm_")) + QString::fromLocal8Bit("imu_camera");

    //设置文件存放地址 默认
    m_file_save_path = QCoreApplication::applicationDirPath() + "/" + current_date_collect;
    ui->hmd_data_path->setFocusPolicy(Qt::NoFocus);//焦点不可选
    ui->hmd_data_path->setText(m_file_save_path);

    //按键初始化
    m_common = QString::fromLocal8Bit("QPushButton{font:15px '微软雅黑';background-color: #FF4D4D4D;border:0;color:white;}");
    m_common_go = QString::fromLocal8Bit("QPushButton{font:15px '微软雅黑';background-color: #FF4D4D4D;border:1 outset  #39F354;color:white;}");
    m_hover = QString::fromLocal8Bit("QPushButton::hover{border:0 white;background-color:rgba(255,255,255,0.1);color:white;font:15px '微软雅黑'}");
    m_pressed = QString::fromLocal8Bit("QPushButton::pressed{border:1px solid rgba(255,255,255,0.2); background-color:rgba(255,255,255,0.2);color:white;font:15px '微软雅黑'}");

    //类初始化部分  IMU CAMERA-LEFT CAERAM -RIGHT
    m_hmd_about = new HMDAbout();
    m_camera_data = new CameraAbout();
    m_camera_data_right = new CameraAbout_Right();

    //注册 信号槽类型
    qRegisterMetaType<QList<string> >("QList<string>");
    qRegisterMetaType<QList<imrCameraData> >("QList<imrCameraData>");
    qRegisterMetaType<imrCameraData>("imrCameraData");
    //imu 数据 保存
    connect(this,SIGNAL(sig_imu_data_post(QList<string>)),m_hmd_about,SLOT(slot_setIMUData(QList<string>)),Qt::QueuedConnection);
    //camera 数据 保存
    connect(this,SIGNAL(sig_camera_data_post_left(QList<imrCameraData>)),m_camera_data,SLOT(slot_setCameraData(QList<imrCameraData>)),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_camera_data_post_right(QList<imrCameraData>)),m_camera_data_right,SLOT(slot_setCameraData(QList<imrCameraData>)),Qt::QueuedConnection);
    //左右目相机时间戳 存储
    connect(this,SIGNAL(sig_camera_imu_post_left(double)),m_camera_data,SLOT(slot_setCameraImu(double)),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_camera_imu_post_right(double)),m_camera_data_right,SLOT(slot_setCameraImu(double)),Qt::QueuedConnection);
    //左右目数据存储状态
    //connect(m_camera_data,SIGNAL(sig_save_ok()),this,SLOT(slot_save_isok()));
    //connect(m_camera_data_right,SIGNAL(sig_save_ok()),this,SLOT(slot_save_isok()));

    //线程初始化
    m_thread = new QThread(this);             //IMU
    m_thread_camera = new QThread(this);
    m_thread_camera_right = new QThread(this);

    //注意记得启动线程
    m_thread->start();
    m_thread_camera->start();
    m_thread_camera_right->start();

    m_hmd_about->moveToThread(m_thread);
    m_camera_data->moveToThread(m_thread_camera);
    m_camera_data_right->moveToThread(m_thread_camera_right);

    //imu 数据获取
    m_timer_imu = new QTimer(this);
    connect(m_timer_imu, SIGNAL(timeout()), this, SLOT(showTimelimit_imu()));
    //相机显示
    m_timer_camera_show = new QTimer(this);
    connect(m_timer_camera_show, SIGNAL(timeout()), this, SLOT(showTimelimit_camera_show()));
    //相机 左右目图片获取
    m_timer_camera = new QTimer(this);
    connect(m_timer_camera, SIGNAL(timeout()), this, SLOT(showTimelimit_camera()));
    //检测设备连接状态
    m_con_state = new QTimer(this);
    connect(m_con_state, SIGNAL(timeout()), this, SLOT(showTimelimit_con_state()));
    //任务执行状态
    m_work_state = new QTimer(this);
    connect(m_work_state, SIGNAL(timeout()), this, SLOT(showTimelimit_work_show()));


    m_timer_imu->start( 1000 );
    m_timer_camera->start( 1 );
    m_con_state->start( 1000 );
    m_timer_camera_show->start( 20 );
    //用户
    ui->test_area->hide();
}
bool hmd_in_out;  //头显插入拔出
//相机初始化
//------------------------WINDOWS-----------------------------------------------------------------------------
#ifdef Q_OS_WIN
void MainWindow::CameraInit(){
    //打开MR，请求所有设备信息
    m_camera_pHandle = imrOpenIMR();
    //初始化头显插拔
    if(m_camera_pHandle != NULL){
        //获取 |已连接| 设备的信息 IMU数据回调信息
        m_con_eq_info= imrSearchDevices(m_camera_pHandle);
        //初始化
        for (int i = 0; i < m_con_eq_info.devNum; ++i) {
            imrConnectDevice(m_camera_pHandle, m_con_eq_info._devInfo[i]._id, 0, MainWindow::HMDDataCollect);
        }
        if (m_camera_pHandle == NULL)
        {
            assert(m_camera_pHandle != NULL);
        }
        //初始化相机配置信息
        CameraConfig cc = { 0 };
        cc._cb = MainWindow::HMDDataCollectCamera;
        //初始化相机
        if(imrInitCamera(m_camera_pHandle, cc)){
            //折中处理
            hmd_in_out = true;
        }else{
            ui->test_area->setEnabled(false);
        }
        //采集软件中  仅仅对  【模组部分】   进行了采集   其他部分不提供相应采集功能
        if(m_con_eq_info.devNum > 0){
            switch (m_con_eq_info._devInfo->_type) {
            case IMR_HMD:
                ui->type->setText(QString::fromLocal8Bit("模组"));
                break;
            case IMR_CAMERA_LEFT:
                ui->type->setText(QString::fromLocal8Bit("左相机"));
                break;
            case IMR_CAMERA_RIGHT:
                ui->type->setText(QString::fromLocal8Bit("右相机"));
                break;
            case IMR_HAND_LEFT:
                ui->type->setText(QString::fromLocal8Bit("左手柄"));
                break;
            case IMR_HAND_RIGHT:
                ui->type->setText(QString::fromLocal8Bit("右手柄"));
                break;
            default:
                break;
            }
        }
    }
}
#elif defined Q_OS_LINUX
//------------------------LINUX-----------------------------------------------------------------------------
void MainWindow::CameraInit(){
    //打开MR，请求所有设备信息
    m_camera_pHandle = imrOpenIMR();
    //初始化头显插拔
    if(m_camera_pHandle != NULL){
        //获取 |已连接| 设备的信息 IMU数据回调信息
        m_con_eq_info= imrSearchDevices(m_camera_pHandle);
        //初始化
        imrConnectDevice(m_camera_pHandle, NULL, 0, MainWindow::HMDDataCollect);

        //初始化相机配置信息
        CameraConfig cc = { 0 };
        cc._cb = MainWindow::HMDDataCollectCamera;
        //初始化相机
        if(imrInitCamera(m_camera_pHandle, cc)){
            imrStartCamera(m_camera_pHandle);
            //折中处理
            hmd_in_out = true;
        }else{
            ui->test_area->setEnabled(false);
        }
        //采集软件中  仅仅对  【模组部分】   进行了采集   其他部分不提供相应采集功能
        if(m_con_eq_info.devNum > 0){
            switch (m_con_eq_info._devInfo->_type) {
            case IMR_HMD:
                ui->type->setText(QString::fromLocal8Bit("模组"));
                break;
            case IMR_CAMERA_LEFT:
                ui->type->setText(QString::fromLocal8Bit("左相机"));
                break;
            case IMR_CAMERA_RIGHT:
                ui->type->setText(QString::fromLocal8Bit("右相机"));
                break;
            case IMR_HAND_LEFT:
                ui->type->setText(QString::fromLocal8Bit("左手柄"));
                break;
            case IMR_HAND_RIGHT:
                ui->type->setText(QString::fromLocal8Bit("右手柄"));
                break;
            default:
                break;
            }
        }
    }
}
#endif
//临时存放
imrIMUData imu_temp;                              //imu 主页显示 变量
QList<string> imu_box;                            //imu 传输容器
QList<string> imu_cache;                          //imu 缓存容器
bool state = true;                                //采集按钮状态开关
bool collect_state = false;                       //数据采集   开关
//--------------采集开关 imu | camera-----------------------------
bool m_imu_collet = false;
bool m_camera_collect = false;
//--------------------------------------------------------------
QMutex m_mutex;            //imu 存储锁
//获取待采集的数据集合
void MainWindow::HMDDataCollect(imrIMUData*data){
    if(collect_state && m_imu_collet){
        //        char  imu_one[200];
        //        long long time_stamp = basetime + data->_timeStamp * 1000000;
        //        sprintf(imu_one,"%lld,%f,%f,%f,%f,%f,%f",time_stamp,
        //                data->_gyr[0] * (PI / 180),
        //                data->_gyr[1] * (PI / 180),
        //                data->_gyr[2] * (PI / 180),
        //                data->_acc[0] * _G0,
        //                data->_acc[1] * _G0,
        //                data->_acc[2] * _G0);
        //        imu_box.push_back(imu_one);
        //----------------------缓存版本--------------------------
        QMutexLocker locker(&m_mutex);
        char  imu_one[200];
        long long time_stamp = basetime + data->_timeStamp * 1000000;
        sprintf(imu_one,"%lld,%f,%f,%f,%f,%f,%f",time_stamp,
                data->_gyr[0] * (PI / 180),
                data->_gyr[1] * (PI / 180),
                data->_gyr[2] * (PI / 180),
                data->_acc[0] * _G0,
                data->_acc[1] * _G0,
                data->_acc[2] * _G0);
        imu_cache.push_back(imu_one);
        if(imu_cache.size() == 2000){
            imu_box = imu_cache;
            imu_cache.clear();
        }
    }
    imu_temp._timeStamp = data->_timeStamp;
    imu_temp._type = data->_type;
    for(int i =0;i < 3;++i){
        imu_temp._acc[i] = data->_acc[i];
        imu_temp._gyr[i] = data->_gyr[i];
    }
}
imrCameraData camera_temp;                         //camera 双目显示
imrCameraData camera_left;                         //camera LEFT
imrCameraData camera_right;                        //camera RIGHT

QMap<int,QList<imrCameraData> > camera_box_left;   //camera 传输容器 LEFT
QMap<int,QList<imrCameraData> > camera_box_right;  //camera 传输容器 RIGHT

QQueue<imrCameraData> camera_cache_left;           //camera 缓存容器 LEFT
QQueue<imrCameraData> camera_cache_right;          //camera 缓存容器 RIGHT

bool write_end = false;                            //等待写入状态 camera 数据 时间戳
int  now_group = 0;                                //当前写入组 camera
int  group = 0;                                    //实时写入组 camera
//获取待采集的相机数据集合
void MainWindow::HMDDataCollectCamera(imrCameraData *camera_data){
    if(collect_state && m_camera_collect){
        unsigned char* temp_left =  new unsigned char[camera_data->_size];
        unsigned char* temp_right =  new unsigned char[camera_data->_size];

        memcpy(temp_left,camera_data->_image,camera_data->_size);
        memcpy(temp_right,camera_data->_image,camera_data->_size);

        camera_left._image = temp_left;
        camera_left._type = camera_data->_type;
        camera_left._timeStamp = camera_data->_timeStamp;
        camera_left._size = camera_data->_size;

        camera_right._image = temp_right;
        camera_right._type = camera_data->_type;
        camera_right._timeStamp = camera_data->_timeStamp;
        camera_right._size = camera_data->_size;

        camera_cache_left.push_back(camera_left);
        camera_cache_right.push_back(camera_right);

        if(camera_cache_left.size() == 1){
            camera_box_left.insert(group,camera_cache_left);
            camera_box_right.insert(group,camera_cache_right);

            camera_cache_left.clear();
            camera_cache_right.clear();
            ++group;
        }
    }
    camera_temp._type = camera_data->_type;
    camera_temp._timeStamp = camera_data->_timeStamp;
    camera_temp._image = camera_data->_image;
    camera_temp._size = camera_data->_size;
}
void MainWindow::HMDInOutInfo(bool in_out){
    hmd_in_out = in_out;
}
//发送回调的相机信息
void MainWindow::showTimelimit_camera(){
    if(collect_state && m_camera_collect){
        if(group > now_group){
            emit sig_camera_data_post_left(camera_box_left.value(now_group));
            emit sig_camera_imu_post_left(camera_box_left.value(now_group)[0]._timeStamp);
            emit sig_camera_data_post_right(camera_box_right.value(now_group));
            emit sig_camera_imu_post_right(camera_box_right.value(now_group)[0]._timeStamp);
            ++now_group;
        }
    }else{
        if(group == now_group && group >0){
            if(m_imu_collet && m_camera_collect){
                m_hmd_about->setCollectState(state,"");
                m_camera_data->setCollectStateCamera(state,"");
                m_camera_data_right->setCollectStateCamera(state,"");

                if(imu_box.size() > 0)
                    imu_box.clear();
                now_group = 0;
                group = 0;
            }
            if(m_camera_collect){
                m_camera_data->setCollectStateCamera(state,"");
                m_camera_data_right->setCollectStateCamera(state,"");

                now_group = 0;
                group = 0;
            }
        }
    }
}
void MainWindow::slot_save_isok(){
    //处理部分
}
//发送imu数据
void MainWindow::showTimelimit_imu(){
    //--------------------缓存版本---------------------
    if(collect_state && m_imu_collet){
        if(imu_box.size() == 2000)
            emit sig_imu_data_post(imu_box);
        if(imu_box.size() >0)
            imu_box.clear();
    }
}
//连接 确认
bool show_flag_on = true;
bool show_flag_off = true;
void MainWindow::showTimelimit_con_state(){
    if(hmd_in_out){
        if(show_flag_on){
            ui->eq_con_state->setText(QString::fromLocal8Bit("已连接"));
            ui->eq_con_state->setStyleSheet(QString::fromLocal8Bit("QLabel{border:1px solid #FF4D4D4D;border-left:0;color:#39F354;font:13px '微软雅黑'}"));
            show_flag_off = true;
            show_flag_on = false;
            if(ui->Camera_Imu_mark_mask->x() == 0){
                AnimationControl(ui->Camera_Imu_mark_mask,300,0,0,-450,0,450,260,3);
                //重新初始化相机
                CameraInit();
                if(!m_timer_imu->isActive())
                    m_timer_imu->start();
                if(!m_timer_camera->isActive())
                    m_timer_camera->start();
                if(!m_timer_camera_show->isActive())
                    m_timer_camera_show->start();
            }
            ui->test_area->setEnabled(true);
        }
    }else{
        if(show_flag_off){
            if(m_camera_pHandle != NULL)
                destroyWindow("左右目视图");
            //destroyWindow("right_camera");
            AnimationControl(ui->Camera_Imu_mark_mask,300,-450,0,0,0,450,260,3);
            if(ui->hmd_imu_tips->x() == 450)
                AnimationControl(ui->hmd_imu_tips,300,450,0,150,0,300,290,3);
            //未连接部分初始化
            ui->type->setText(QString::fromLocal8Bit("未知"));
            ui->eq_con_state->setText(QString::fromLocal8Bit("未连接"));
            ui->eq_con_state->setStyleSheet(QString::fromLocal8Bit("QLabel{border:1px solid #FF4D4D4D;border-left:0;color:red;font:13px '微软雅黑'}"));
            ui->m_machine_pose->setText(QString::fromLocal8Bit("                            未连接到设备"));
            show_flag_on = true;
            show_flag_off = false;
            m_work_type = -1;
            if(m_work_state->isActive())
                m_work_state->stop();
            if(m_timer_imu->isActive())
                m_timer_imu->stop();
            if(m_timer_camera->isActive())
                m_timer_camera->stop();
            if(m_timer_camera_show->isActive())
                m_timer_camera_show->stop();
        }
    }
}
//动画控件部分
//target: 空间句柄
//ms: 动画时间
//x_s,y_s /x_e,y_e x轴开始位置 y轴开始/x轴结束，y轴结束
//w,h：宽，高
//type：动画类型 QAbstractAnimation
void MainWindow::AnimationControl(QObject *target, int msc, int x_s, int y_s, int x_e, int y_e, int w, int h, int type){
    /*  声明动画类，并将控制对象 target (target)  以及属性名 "geometry" 传入构造函数  */
    QPropertyAnimation* animation = new QPropertyAnimation(target, "geometry");
    /*  设置动画持续时长为 msc 秒钟  */
    animation->setDuration(msc);
    /*  设置动画的起始状态 起始点 (x_s,y_s)  起始大小 (w,h)  */
    animation->setStartValue(QRect(x_s, y_s, w, h));
    /*  设置动画的结束状态 结束点 (x_e,y_e)  结束大小 (w,h)  */
    animation->setEndValue(QRect(x_e, y_e, w, h));
    /*  设置动画效果  */
    animation->setEasingCurve(QEasingCurve(QEasingCurve::Type(type)));
    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
//左右目显示窗
void MainWindow::showTimelimit_camera_show(){
    // && collect_state == false
    if(camera_temp._timeStamp != 0){
        //        QImage *m_image = new QImage(camera_temp._image,2560,1600,QImage::Format_Indexed8);

        //        QImage pic_1 = m_image->copy(0,0,1280,800);
        //        QImage pic_2 = m_image->copy(1280,0,1280,800);

        //        cv::Mat left(800,1280,CV_8UC1,pic_1.bits());
        //        cv::Mat right(800,1280,CV_8UC1,pic_2.bits());

        cv::Mat img(800,2560,CV_8UC1,camera_temp._image);
        cv::Mat left_right = img(cv::Range(0,800),cv::Range(0,2560));

        namedWindow("左右目视图",0);
        //namedWindow("right_camera",0);

        cvResizeWindow("左右目视图", 1280, 400);
        //cvResizeWindow("right_camera", 640, 400);

        imshow("左右目视图", left_right);
        //imshow("right_camera", right);

        img.release();
        left_right.release();
    }
    if(imu_temp._timeStamp != 0){
        QString pose_info_left_acc = "accel(x,y,z): "
                + QString::number(imu_temp._acc[0],'f',6) + ","
                + QString::number(imu_temp._acc[1],'f',6) + ","
                + QString::number(imu_temp._acc[2],'f',6);
        QString pose_info_left_gyr = "gyro(x,y,z): "
                + QString::number(imu_temp._gyr[0],'f',6) + ","
                + QString::number(imu_temp._gyr[1],'f',6) + ","
                + QString::number(imu_temp._gyr[2],'f',6);
        ui->m_machine_pose->setText("  " + pose_info_left_gyr + "\n\n" + "  " +  pose_info_left_acc);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mousePosition = event->pos();
    //只对标题栏范围内的鼠标事件进行处理
    if (mousePosition.x()<=pos_min_x)
        return;
    if ( mousePosition.x()>=pos_max_x)
        return;
    if (mousePosition.y()<=pos_min_y )
        return;
    if (mousePosition.y()>=pos_max_y)
        return;
    isMousePressed = true;
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if ( isMousePressed==true )
    {
        QPoint movePot = event->globalPos() - mousePosition;
        move(movePot);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    isMousePressed=false;
}
//最小化窗口
void MainWindow::on_module_info_min_clicked()
{
    this->showMinimized();
}
//关闭程序并销毁线程 不友好的强制杀死
void MainWindow::on_module_info_close_clicked()
{
    m_timer_camera_show->stop();
    QMutexLocker locker(&m_mutex);
    m_thread->exit();
    m_thread_camera->exit();
    m_thread_camera_right->exit();

    m_thread->terminate();
    m_thread_camera->terminate();
    m_thread_camera_right->terminate();

    delete m_thread;
    delete m_thread_camera;
    delete m_thread_camera_right;

    //imrCloseIMR(m_camera_pHandle);
    destroyWindow("左右目视图");
    //destroyWindow("right_camera");
    this->close();
}
//开始采集 imu_camera 数据
bool newPath = false;//用以判断是否自定文件存储地址
QString open_c = QString::fromLocal8Bit("font:13px '微软雅黑';color:red");    //未选择 存储模式 复选框 变红 警告
QString close_c = QString::fromLocal8Bit("font:13px '微软雅黑';color:white"); //选择后 回复默认
void MainWindow::on_collect_start_clicked()
{
    current_date_time = QDateTime::currentDateTime();
    if(m_camera_collect || m_imu_collet){
        ui->imu_data->setStyleSheet(close_c);
        ui->camera_data->setStyleSheet(close_c);
        if(state){
            collect_state = true;
            m_work_type = 1;
            m_work_state->start(500);
            ui->collect_start->setText(QString::fromLocal8Bit("关闭采集"));

            QString time = QDateTime::currentDateTime().toString(QString::fromLocal8Bit("yyyyMMdd hhmmss.zzz"));
            if(!newPath){
                //获取当前时间  设置文件夹日期
                current_date_time = QDateTime::currentDateTime();
                current_date_collect = current_date_time.toString(QString::fromLocal8Bit("yyyy-MM-dd_hh_mm_")) + QString::fromLocal8Bit("imu_camera");
                //设置文件存放地址
                m_file_save_path = QCoreApplication::applicationDirPath() + "/" + current_date_collect;
                ui->hmd_data_path->setFocusPolicy(Qt::NoFocus);//焦点不可选
                ui->hmd_data_path->setText(m_file_save_path);

                m_hmd_about->setFileSavePath(m_file_save_path);
                m_camera_data->setFileSavePath(m_file_save_path);
                m_camera_data_right->setFileSavePath(m_file_save_path);
            }
            if(m_imu_collet){
                m_hmd_about->setCollectState(state,time);
            }
            if(m_camera_collect){
                m_camera_data->OpenFile();
                m_camera_data_right->OpenFile();
                m_camera_data->setCollectStateCamera(state,time);
                m_camera_data_right->setCollectStateCamera(state,time);
            }
            state = false;
            ui->imu_data->setEnabled(false);
            ui->camera_data->setEnabled(false);
        }else{
            state = true;
            collect_state = false;
            m_work_type = -1;
            ui->collect_start->setStyleSheet(m_common + m_hover + m_pressed);
            ui->collect_start->setText(QString::fromLocal8Bit("开始采集"));

            if(m_camera_collect){
                m_camera_data->getNowDataNum(now_group);
                m_camera_data_right->getNowDataNum(now_group);
            }
            if(m_imu_collet){
                m_hmd_about->setCollectState(state,"");
                if(imu_box.size() > 0)
                    imu_box.clear();
            }
            ui->imu_data->setEnabled(true);
            ui->camera_data->setEnabled(true);
        }
    }else{
        ui->imu_data->setStyleSheet(open_c);
        ui->camera_data->setStyleSheet(open_c);
    }
}
//设置 路径并自动适用
void MainWindow::on_hmd_data_path_set_clicked()
{
    //选择路径
    QString path  = QFileDialog::getExistingDirectory(this);
    if(path == "/")
        path = "C:/Program Files/";

    //设置文件存放地址
    m_file_save_path = path;

    //获取当前时间  设置文件夹日期
    current_date_time = QDateTime::currentDateTime();
    current_date_collect = current_date_time.toString(QString::fromLocal8Bit("yyyy-MM-dd_hh_mm_")) + QString::fromLocal8Bit("imu_camera");
    //再次设置路径
    if(ui->collect_start->text() == QString::fromLocal8Bit("关闭采集")){
        ui->collect_start->click();
        m_hmd_about->setFileSavePath(m_file_save_path + "/" + current_date_collect);
        m_camera_data->setFileSavePath(m_file_save_path + "/" + current_date_collect);
        m_camera_data_right->setFileSavePath(m_file_save_path + "/" + current_date_collect);
        ui->hmd_data_path->setText(m_file_save_path +"/" + current_date_collect);
        return;
    }
    m_hmd_about->setFileSavePath(m_file_save_path + "/" + current_date_collect);
    m_camera_data->setFileSavePath(m_file_save_path + "/" + current_date_collect);
    m_camera_data_right->setFileSavePath(m_file_save_path + "/" + current_date_collect);
    ui->hmd_data_path->setText(m_file_save_path + "/" + current_date_collect);
    newPath = true;
}
MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------------------------------------测试部分 暂时未使用-------------------------------------------------------------------------------------------------------------------
//动态显示任务执行状态
bool work_on_off = false;
int msc = 0;
void MainWindow::showTimelimit_work_show(){
    ui->start_time->setText(QString::fromLocal8Bit("已采集时间：") + QString::number(current_date_time.secsTo(QDateTime::currentDateTime()),10) + "S");
    switch (m_work_type) {
    case 0:
        if(work_on_off){
            ui->imu_collect->setStyleSheet(m_common_go + m_hover + m_pressed);
            work_on_off = false;
        }
        else{
            ui->imu_collect->setStyleSheet(m_common + m_hover + m_pressed);
            work_on_off = true;
        }
        break;
    case 1:
        if(work_on_off){
            ui->collect_start->setStyleSheet(m_common_go + m_hover + m_pressed);
            work_on_off = false;
        }
        else{
            ui->collect_start->setStyleSheet(m_common + m_hover + m_pressed);
            work_on_off = true;
        }
        break;
    default:
        break;
    }
}
//imu 误差采集 Camera 误差值纪录
bool imu_error_state = true;
void MainWindow::on_imu_collect_clicked()
{
    current_date_time = QDateTime::currentDateTime();
    if(imu_error_state){
        m_work_type = 0;
        m_work_state->start(500);
        collect_state = true;
        QString time = QDateTime::currentDateTime().toString(QString::fromLocal8Bit("yyyyMMddhhmmss.zzz"));
        m_hmd_about->setIMUCameraOnOff(true);
        m_hmd_about->setCollectState(false,time);
        ui->imu_collect->setText(QString::fromLocal8Bit("点击关闭采集"));
        imu_error_state = false;
    }else{
        if(m_work_state->isActive())
            m_work_state->stop();
        m_work_type = -1;
        collect_state = false;
        m_hmd_about->setIMUCameraOnOff(false);
        imu_error_state = true;
        write_end = true;
        ui->imu_collect->setText(QString::fromLocal8Bit("IMU | Camera"));
        ui->imu_collect->setStyleSheet(m_common + m_hover + m_pressed);
    }
}
void MainWindow::on_test_area_clicked()
{
    if(ui->hmd_imu_tips->x() == 150){
        AnimationControl(ui->hmd_imu_tips,300,150,0,450,0,300,290,3);

    }else{
        AnimationControl(ui->hmd_imu_tips,300,450,0,150,0,300,290,3);

    }
}
void MainWindow::on_test_area_top_clicked()
{
    if(ui->hmd_imu_tips_box->x() == -290){
        AnimationControl(ui->hmd_imu_tips_box,300,-290,5,5,5,290,250,3);

    }else{
        AnimationControl(ui->hmd_imu_tips_box,300,5,5,-290,5,290,250,3);
    }
}
//IMU采集开关
void MainWindow::on_imu_data_stateChanged(int state)
{
    if(state == 2){
        m_imu_collet = true;
        ui->imu_data->setStyleSheet(close_c);
        ui->camera_data->setStyleSheet(close_c);
    }
    else
        m_imu_collet = false;
}
//相机采集开关
void MainWindow::on_camera_data_stateChanged(int state)
{
    if(state == 2){
        m_camera_collect = true;
        ui->imu_data->setStyleSheet(close_c);
        ui->camera_data->setStyleSheet(close_c);
    }
    else
        m_camera_collect = false;
}
