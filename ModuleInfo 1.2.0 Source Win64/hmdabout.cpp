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
void HMDAbout::setIMUCameraOnOff(bool IMU_state){
    m_imu_on_off = IMU_state;
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
//        if(!helpInfo){
//            imu_data<<"imu #timestamp [ns],w_RS_S_x [rad s^-1],w_RS_S_y [rad s^-1],w_RS_S_z [rad s^-1],a_RS_S_x [m s^-2],a_RS_S_y [m s^-2],a_RS_S_z [m s^-2]"<<endl;
//            helpInfo = true;
//        }
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

