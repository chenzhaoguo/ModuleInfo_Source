#include "CameraAbout_Right.h"

CameraAbout_Right::CameraAbout_Right()
{
    //默认构造
}
//设置文件存放地址
void CameraAbout_Right::setFileSavePath(QString filePath){
    imu_camera_file_path = filePath;
}
void CameraAbout_Right::OpenFile(){
    cam0_data = imu_camera_file_path + QString::fromLocal8Bit("/cam1/data/");
    new_imu_data_0.setFileName(imu_camera_file_path + QString::fromLocal8Bit("/cam1/data.csv"));
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(cam0_data))
    {
        dir.mkpath(cam0_data);
    }
    imu_data_0 = new QTextStream(&new_imu_data_0);
    new_imu_data_0.open(QIODevice::Append | QIODevice::Text);
}
void CameraAbout_Right::setCollectStateCamera(bool camera_state, QString time){
    m_state_camera = camera_state;
    if(time != NULL)
        m_time = time;
}
void CameraAbout_Right::setFileClose(){
    new_imu_data_0.close();
}
void CameraAbout_Right::getNowDataNum(int num){
    m_imu_camera_num = num;
}
void CameraAbout_Right::slot_setCameraData(QList<imrCameraData> data){
    if(m_state_camera){
        long long pic_d = basetime + data[0]._timeStamp * 1000000;
        QString path_right = cam0_data + QString::number(pic_d) + ".png";
        cv::Mat img(800,2560,CV_8UC1,data[0]._image);
        cv::Mat right = img(cv::Range(0,800),cv::Range(1280,2560));
        cv::imwrite(path_right.toStdString(),right);
        img.release();
        right.release();
        delete[] data[0]._image;
    }
}

void CameraAbout_Right::slot_setCameraImu(double imu){
    long long pic_d = basetime + imu * 1000000;
    QString imu0 = QString::number(pic_d) + " " + QString::number(pic_d) + ".png";
    *imu_data_0<<imu0<<endl;
    now_num++;
    if(m_imu_camera_num == now_num && m_imu_camera_num > 0){
        setFileClose();
        //emit sig_save_ok();
    }
}
CameraAbout_Right::~CameraAbout_Right()
{
    //默认析构
}

