#include "hmdabout.h"

HMDAbout::HMDAbout()
{
    //默认构造
}
//设置文件存放地址
void HMDAbout::setFileSavePath(QString filePath){
    imu_camera_file_path = filePath;
}
//设置采集状态 采集开始时间
void HMDAbout::setCollectState(bool imu_state, QString time){
    m_state_imu = imu_state;
    if(time != NULL)
        m_time = time;
}
void HMDAbout::setCollectStateCamera(bool camera_state, QString time){
    m_state_camera = camera_state;
    if(time != NULL)
        m_time = time;
}
void HMDAbout::setIMUCameraOnOff(bool IMU_state){
    m_imu_on_off = IMU_state;
}
//临时误差值存储
double camera_time_temp = 0;
void HMDAbout::slot_setCameraData(imrCameraData data){
    if(m_state_camera){
        QString cam0_data = imu_camera_file_path + QString::fromLocal8Bit("/cam0/data/");
        QString cam1_data = imu_camera_file_path + QString::fromLocal8Bit("/cam1/data/");

        QFile new_imu_data_0(imu_camera_file_path + QString::fromLocal8Bit("/cam0/data.csv"));
        QFile new_imu_data_1(imu_camera_file_path + QString::fromLocal8Bit("/cam1/data.csv"));

        // 检查目录是否存在，若不存在则新建
        QDir dir;
        if (!dir.exists(cam0_data))
        {
            dir.mkpath(cam0_data);
        }
        if (!dir.exists(cam1_data))
        {
            dir.mkpath(cam1_data);
        }

        if(!new_imu_data_0.open(QIODevice::Append | QIODevice::Text))
        {
            return;
        }
        if(!new_imu_data_1.open(QIODevice::Append | QIODevice::Text))
        {
            return;
        }
        //获取图像
        m_image = new QImage(data._image,2560,800,QImage::Format_Indexed8);
        //图片切割 左|右
        QImage pic_1 = m_image->copy(0,0,1280,800);
        QImage pic_2 = m_image->copy(1280,0,1280,800);
        //保存图片
        long long time_stamp = basetime + data._timeStamp * 1000000;
        qDebug()<<time_stamp;
        pic_1.save(cam0_data + QString::number(time_stamp) + ".png","PNG");
        pic_2.save(cam1_data + QString::number(time_stamp) + ".png","PNG");

        QTextStream imu_data_0(&new_imu_data_0);
        QTextStream imu_data_1(&new_imu_data_1);
        //左右目数据是一致的
        QString imu0 = QString::number(time_stamp) + " " + QString::number(time_stamp) + ".png";
        imu_data_0<<imu0<<endl;
        imu_data_1<<imu0<<endl;
        new_imu_data_0.close();
        new_imu_data_1.close();

        if(m_image != NULL){
            delete m_image;
            m_image = NULL;
        }
    }
    //    if(m_imu_on_off){
    //        if(camera_time_temp != 0){
    //            double error = data._timeStamp - camera_time_temp;
    //            if(error > 25){
    //                // 检查目录是否存在，若不存在则新建
    //                QString path = imu_camera_file_path + QString::fromLocal8Bit("/Camera 误差/");
    //                QDir dir;
    //                if (!dir.exists(path))
    //                {
    //                    dir.mkpath(path);
    //                }
    //                QFile new_imu_data(path + QString::fromLocal8Bit("/") + m_time + ".csv");
    //                if(!new_imu_data.open(QIODevice::Append | QIODevice::Text))
    //                {
    //                    return;
    //                }
    //                QTextStream imu_data(&new_imu_data);
    //                QString imu = QString::number(data._timeStamp,'f',6) + " "
    //                        + QString::number(error,'f',6);
    //                imu_data<<imu<<endl;
    //                new_imu_data.close();
    //            }
    //        }
    //        camera_time_temp = data._timeStamp;
    //    }
}
//临时误差值存储
double imu_time_temp = 0;
bool helpInfo = false;
void HMDAbout::slot_setIMUData(QList<string> data){
    //    if(m_state_imu){
    //        QString path = imu_camera_file_path + "/imu0/";
    //        QDir dir;
    //        if (!dir.exists(path))
    //        {
    //            dir.mkpath(path);
    //        }
    //        QFile new_imu_data(path + QString::fromLocal8Bit("/") + "data.csv");
    //        if(!new_imu_data.open(QIODevice::ReadWrite | QIODevice::Text))
    //        {
    //            return;
    //        }
    //        QTextStream imu_data(&new_imu_data);
    //        QString temp = "";

    //        if(!helpInfo){
    //            imu_data<<"imu #timestamp [ns],w_RS_S_x [rad s^-1],w_RS_S_y [rad s^-1],w_RS_S_z [rad s^-1],a_RS_S_x [m s^-2],a_RS_S_y [m s^-2],a_RS_S_z [m s^-2]"<<endl;
    //            helpInfo = true;
    //        }
    //        for(int i = 0;i<data.size();++i){
    //            temp += QString::fromStdString(data[i]) + "\n";
    //        }
    //        imu_data<<temp<<endl;
    //        new_imu_data.close();
    //        m_imu_data_box.clear();
    //    }
    //-------------------------------缓存版本---------------------------------------------------
    if(m_state_imu){
        QString path = imu_camera_file_path + "/imu0/";
        QDir dir;
        if (!dir.exists(path))
        {
            dir.mkpath(path);
        }
        QFile new_imu_data(path + QString::fromLocal8Bit("/") + "data.csv");
        if(!new_imu_data.open(QIODevice::Append | QIODevice::Text))
        {
            return;
        }
        QTextStream imu_data(&new_imu_data);
        QString temp = "";

        if(!helpInfo){
            imu_data<<"imu #timestamp [ns],w_RS_S_x [rad s^-1],w_RS_S_y [rad s^-1],w_RS_S_z [rad s^-1],a_RS_S_x [m s^-2],a_RS_S_y [m s^-2],a_RS_S_z [m s^-2]"<<endl;
            helpInfo = true;
        }
        for(int i = 0;i<data.size();++i){
            if(i < 1999)
                temp += QString::fromStdString(data[i]) + "\n";
            else
                temp += QString::fromStdString(data[i]);

        }
        imu_data<<temp<<endl;
        new_imu_data.close();
        m_imu_data_box.clear();
    }
    //-----------------------------------------------------------------------------------------
    //误差采集
    if(m_imu_on_off){
        for(int i = 0;i<data.size();++i){
            QString time = QString::fromStdString(data[i]).split(' ')[0];
            double error =  time.toDouble()- imu_time_temp;
            qDebug()<<error;
            if(error > 2){
                QString path = imu_camera_file_path + QString::fromLocal8Bit("/IMU 误差/");
                QDir dir;
                if (!dir.exists(path))
                {
                    dir.mkpath(path);
                }
                QFile new_imu_data(path + QString::fromLocal8Bit("/") + m_time + ".csv");
                if(!new_imu_data.open(QIODevice::Append | QIODevice::Text))
                {
                    return;
                }
                QTextStream imu_data(&new_imu_data);
                imu_data<<time<<endl;
                new_imu_data.close();
            }
            imu_time_temp = time.toDouble();
        }
    }
}
HMDAbout::~HMDAbout()
{
    //默认析构
}

