#include "CameraAbout.h"

CameraAbout::CameraAbout()
{
    //默认构造
}
//设置文件存放地址
void CameraAbout::setFileSavePath(QString filePath){
    imu_camera_file_path = filePath;
}
//打开文件存储
void CameraAbout::OpenFile(){
    cam0_data = imu_camera_file_path + QString::fromLocal8Bit("/cam0/data/");
    new_imu_data_0.setFileName(imu_camera_file_path + QString::fromLocal8Bit("/cam0/data.csv"));
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(cam0_data))
    {
        dir.mkpath(cam0_data);
    }
    imu_data_0 = new QTextStream(&new_imu_data_0);
    new_imu_data_0.open(QIODevice::Append | QIODevice::Text);
}
void CameraAbout::setFileClose(){
    new_imu_data_0.close();
}
void CameraAbout::getNowDataNum(int num){
    m_imu_camera_num = num;
}
void CameraAbout::setCollectStateCamera(bool camera_state, QString time){
    m_state_camera = camera_state;
    if(time != NULL)
        m_time = time;
}
void CameraAbout::slot_setCameraData(QList<imrCameraData> data){
    if(m_state_camera){
        long long pic_d = basetime + data[0]._timeStamp * 1000000;
        QString path_left = cam0_data + QString::number(pic_d) + ".png";
        cv::Mat img(800,2560,CV_8UC1,data[0]._image);
        cv::Mat left = img(cv::Range(0,800),cv::Range(0,1280));
        cv::imwrite(path_left.toStdString(),left);
        img.release();
        left.release();
        delete[] data[0]._image;
    }
}
void CameraAbout::slot_setCameraImu(double imu){
    long long pic_d = basetime + imu * 1000000;
    QString imu0 = QString::number(pic_d) + " " + QString::number(pic_d) + ".png";
    *imu_data_0<<imu0<<endl;
    now_num++;
    if(m_imu_camera_num == now_num && m_imu_camera_num > 0){
        setFileClose();
        //emit sig_save_ok();
    }
}
CameraAbout::~CameraAbout()
{
    //默认析构
}

