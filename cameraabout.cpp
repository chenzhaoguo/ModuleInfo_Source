#include "CameraAbout.h"

CameraAbout::CameraAbout()
{
    //默认构造
}
//设置文件存放地址
void CameraAbout::setFileSavePath(QString filePath){
    imu_camera_file_path = filePath;
}
void CameraAbout::setCollectStateCamera(bool camera_state, QString time){
    m_state_camera = camera_state;
    if(time != NULL)
        m_time = time;
}
//临时误差值存储
double camera_time_temp_c = 0;
void CameraAbout::slot_setCameraData(imrCameraData data){
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
        long long pic_d = basetime + data._timeStamp * 1000000;
        //QString pic_d = QString("%1").arg(pic_n,0,'g',20);
        pic_1.save(cam0_data + QString::number(pic_d) + ".png","PNG");
        pic_2.save(cam1_data + QString::number(pic_d) + ".png","PNG");

        QTextStream imu_data_0(&new_imu_data_0);
        QTextStream imu_data_1(&new_imu_data_1);
        //左右目数据是一致的
        QString imu0 = QString::number(pic_d) + " " + QString::number(pic_d) + ".png";
        imu_data_0<<imu0<<endl;
        imu_data_1<<imu0<<endl;
        new_imu_data_0.close();
        new_imu_data_1.close();

        if(m_image != NULL){
            delete m_image;
            m_image = NULL;
        }
    }
}
CameraAbout::~CameraAbout()
{
    //默认析构
}

