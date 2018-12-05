#pragma once
#include <stdint.h>
#include "driver_data.h"

#ifdef usbdriver_EXPORTS
#ifdef WIN32
#define _IMR_DRIVER_DLL_  __declspec( dllexport )
#else
#define _IMR_DRIVER_DLL_
#endif
#else
#ifdef WIN32
#define _IMR_DRIVER_DLL_ __declspec( dllimport )
#else
#define _IMR_DRIVER_DLL_
#endif
#endif
typedef void* IMRDEVICE_HANDLE;

#define IMR_ID_LENGTH 40

//#ifdef __cplusplus
//extern "C" {
//#endif

    /* 图像分辨率 */
    typedef enum {
        P752,
        P640,
    }Resolution;
    /* 相机数据格式 */
    typedef enum {
        Mono8,
        Mono10,
    }CameraDataFormat;

    typedef enum {
        IMR_HMD,
        IMR_CAMERA_LEFT,
        IMR_CAMERA_RIGHT,
        IMR_HAND_LEFT,
        IMR_HAND_RIGHT,
    }DeviceType;

    //相机数据回调函数
    typedef void(*CameraDataCallback)(imrCameraData* data);
    /* 相机配置信息 */
    typedef struct {
        int _freq;
        Resolution _res;
        CameraDataFormat _format;
        CameraDataCallback _cb;		//数据回调
        void* _reserve;				//保留参数,可能定为相机补偿参数
    }CameraConfig;

    typedef struct {
        char _id[IMR_ID_LENGTH];
        DeviceType _type;   //设备的类型
        bool _status;       //连接状态
        void* _reserve;		//保留参数
    }DeviceInfo;

    typedef struct {
        short devNum;           //当前的设备数量
        DeviceInfo* _devInfo;   //每个设备的信息
    }DevicesInfo;

    typedef struct {
        //手柄可视距离
        //手柄可视角信息
    }HandConfig;


    /* 打开MR设备,请求所有设备信息和状态 */
    _IMR_DRIVER_DLL_ IMRDEVICE_HANDLE imrOpenIMR();

    /* 初始化相机 */
    _IMR_DRIVER_DLL_ bool imrInitCamera(IMRDEVICE_HANDLE pHandle, CameraConfig& cfg);

    /* 启用相机数据回调 */
    _IMR_DRIVER_DLL_ bool imrStartCamera(IMRDEVICE_HANDLE pHandle);
    /* 停止相机数据回调 */
    _IMR_DRIVER_DLL_ void imrStopCamera(IMRDEVICE_HANDLE pHandle);

    /* 检索有效的设备，返回设备信息 */
    _IMR_DRIVER_DLL_ DevicesInfo imrSearchDevices(IMRDEVICE_HANDLE pHandle);

    /* IMU数据回调函数 */
    typedef void(*IMUDataCallback)(imrIMUData* data);
    /* 连接设备,并设置IMU回调函数,对于没有IMU数据的设备,回调函数设置为NULL,该函数为同步函数,最多等待timeout
     * 1. 手柄配对：判断对应ID的手柄是否处在长按状态,长按表示连接成功,返回true
    */
    _IMR_DRIVER_DLL_ bool imrConnectDevice(IMRDEVICE_HANDLE pHandle, const char* deviceID, int timeout, IMUDataCallback callback);

    /* 查询设备当前状态，返回状态码,将状态码按位与得到具体状态 */
    _IMR_DRIVER_DLL_ unsigned int imrGetDeviceStatus(IMRDEVICE_HANDLE pHandle, const char* deviceID);

    /* 读取头显设备的标定等参数信息 */
    _IMR_DRIVER_DLL_ bool imrReadHMDCalibration(IMRDEVICE_HANDLE pHandle, char** bin,size_t* len);

    /* 写入头显设备的标定信息 */
    _IMR_DRIVER_DLL_ int imrWriteHMDCalibration(IMRDEVICE_HANDLE pHandle, const char* bin, size_t len);

    /* 读取手柄设备的标定等参数信息 */
    _IMR_DRIVER_DLL_ bool imrReadHandCalibration(IMRDEVICE_HANDLE pHandle, char** bin, size_t* len, DeviceType);

    /* 写入手柄设备的标定信息 */
    _IMR_DRIVER_DLL_ bool imrWriteHandCalibration(IMRDEVICE_HANDLE pHandle, const char* bin, size_t len, DeviceType);

    /* 查询设备电量 */
    _IMR_DRIVER_DLL_ int imrGetDevicePower(IMRDEVICE_HANDLE pHandle, const char* deviceID);

    /* 查询手柄电量 */
    _IMR_DRIVER_DLL_ int imrGetControllerPower(IMRDEVICE_HANDLE pHandle, const char* deviceID);

    /* 设置LED灯亮度, [0~7]盏灯,亮度0~255 */
    _IMR_DRIVER_DLL_ int imrLightenLED(IMRDEVICE_HANDLE pHandle, char light[8]);

    /* 低电量回调函数 */
    typedef void(*LowPowerCallback)(imrPowerData* data);
    /* 设置低电量回调函数 */
    _IMR_DRIVER_DLL_ void imrSetLowPowerCallback(LowPowerCallback callback);

    /* 设置手柄为省电模式 */
    _IMR_DRIVER_DLL_ void imrPowerSavingMode(IMRDEVICE_HANDLE pHandle, DeviceType devType);

    /* 头显插入拔出回调函数 */
    typedef void(*HMDHotplugCallback)(bool bArrive);
    /* 设置头显插入拔出回调函数 */
    _IMR_DRIVER_DLL_ void imrSetHMDHotplugCallback(HMDHotplugCallback callback);

    /* 手柄按键回调函数 */
    typedef void(*KeyCallback)(imrInputData* data);
    _IMR_DRIVER_DLL_ void imrSetInputCallback(IMRDEVICE_HANDLE pHandle, KeyCallback callback);

    /* 关闭MR设备 */
    _IMR_DRIVER_DLL_ void imrCloseIMR(IMRDEVICE_HANDLE pHandle);

//#ifdef __cplusplus
//}
//#endif
