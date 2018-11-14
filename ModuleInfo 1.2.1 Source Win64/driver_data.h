#pragma once
#include <time.h>
/************************************************************************/
/* 以下为设备状态码,按位与                                              */
/************************************************************************/
#define IMR_TIME_SYNC		1		//手柄与头显的时间系统是否同步
#define IMR_HAND_ONLINE		2		//手柄处于在线状态(配对成功)

/************************************************************************/
/* 该文件定义了驱动返回的数据结构                                       */
/************************************************************************/

/*!
* 相机返回的数据格式
*/
struct imrCameraData {
    uint16_t _originalIndex;    //原始帧号
	//时间戳
	double _timeStamp;  //单位:微秒
						//左(值为'L')或右(值为'R')相机
	char _type;
	//图像数据
	unsigned char* _image;
	//数据大小
	int _size;
	//曝光时间
	double _timeExpose; //单位:毫秒
						//SOF
	double _timeSOF;    //单位:毫秒
};

/*!
* 返回的IMU数据格式
*/
struct imrIMUData {
	//时间戳
	double _timeStamp;
	//左(值为'L')或右(值为'R')手柄,'H'为头显
	char _type;
	//[x,y,z]方向的加速度值,单位m/ss
	float _acc[3];
	//[]姿态
	float _gyr[3];
	unsigned char* _data;//驱动原始数据,用于调试
};


#define imrTouch_A 0x01
typedef enum HAND_CONTROLLER_INPUT {
	LEFT_HAND = 'L',
	RIGHT_HAND = 'R',
	HAND_COUNT=2,
}EHandController_Input;

#define TOUCH_UP        0x01
#define TOUCH_DOWN      0x02
#define TOUCH_LEFT      0x04
#define TOUCH_RIGHT     0x08
#define TOUCH_CENTER    0x10

#define USB_GRIP        0x04
#define USB_MENU        0x02
#define USB_SYS         0x01
//按键数据 触发器 触摸板
struct imrInputData {

	char _type;			//左手为'L',右手为'R'
	//EHandController_Input _type;

	bool _bGrip;		//Grip 侧按键
	bool _bMenu;		//Menu 菜单键
	bool _bSystem;		//System 系统键
	bool _bTrigger;	//Tigger 扳机键
	bool _bUp;			//触摸板 按键 上
	bool _bDown;		//触摸板 按键 下
	bool _bLeft;		//触摸板 按键 左
	bool _bRight;		//触摸板 按键 右
	bool _bCenter;		//触摸板 按键 中间

	float _x_Trigger;	//Trigger 键 X轴数据
	float _y_Trigger;	//Trigger 键 Y轴数据  Y=0

	float _x_TouchPad;	//触摸板 x轴
	float _y_TouchPad;	//触摸板 y轴

};

//电源
struct imrPowerData {
	//左(值为'L')或右(值为'R')手柄,'H'为头显
	char _type;
	//电量0~100
	int _power;
};