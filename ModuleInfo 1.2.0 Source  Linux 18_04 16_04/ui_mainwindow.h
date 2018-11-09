/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *module_title_area;
    QLabel *module_title;
    QPushButton *test_area;
    QPushButton *module_info_min;
    QPushButton *module_info_close;
    QWidget *main_area;
    QLabel *eq_con_state;
    QLabel *type;
    QGroupBox *data_camera_box;
    QLabel *IMU_CAMERA_INFO;
    QGroupBox *data_camera_box_bottom;
    QWidget *camera_box;
    QPushButton *hmd_data_path_set;
    QLineEdit *hmd_data_path;
    QLabel *hmd_data_path_title;
    QWidget *hmd_exec_area;
    QLabel *m_machine_pose;
    QPushButton *collect_start;
    QWidget *Camera_mask;
    QLabel *waring_Info_camera_c;
    QLabel *warning_info;
    QLabel *warning_image;
    QWidget *Camera_Imu_mark_mask;
    QLabel *waring_Info_camera_c_4;
    QLabel *image;
    QGroupBox *hmd_imu_tips;
    QLabel *hmd_imu_guide;
    QGroupBox *hmd_imu_tips_bottom;
    QWidget *hmd_umu_tips_box;
    QLabel *err_tips;
    QLabel *start_time;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *mask_all_box;
    QPushButton *imu_collect;
    QLabel *label_5;
    QPushButton *collect_start_camera;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 874);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        module_title_area = new QWidget(centralWidget);
        module_title_area->setObjectName(QStringLiteral("module_title_area"));
        module_title_area->setGeometry(QRect(0, 0, 450, 30));
        module_title_area->setStyleSheet(QLatin1String("#module_title_area{\n"
"	\n"
"	background-color: #4D4D4D;\n"
"}"));
        module_title = new QLabel(module_title_area);
        module_title->setObjectName(QStringLiteral("module_title"));
        module_title->setGeometry(QRect(10, 5, 261, 20));
        module_title->setStyleSheet(QLatin1String("font:13px;\n"
"color:#39F354;\n"
""));
        test_area = new QPushButton(module_title_area);
        test_area->setObjectName(QStringLiteral("test_area"));
        test_area->setGeometry(QRect(300, 0, 50, 30));
        test_area->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color: #FF4D4D4D;\n"
"border:0;\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"border:0 white;\n"
"background-color:rgba(255,255,255,0.1);\n"
"color:white;\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}\n"
"QPushButton::pressed{\n"
"border:1px solid rgba(255,255,255,0.2);\n"
"background-color:rgba(255,255,255,0.2);\n"
"color:white;\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}"));
        module_info_min = new QPushButton(module_title_area);
        module_info_min->setObjectName(QStringLiteral("module_info_min"));
        module_info_min->setGeometry(QRect(350, 0, 50, 30));
        module_info_min->setStyleSheet(QLatin1String("\n"
"QPushButton{border:0;image: url(:/images/min.png)}\n"
"QPushButton::hover{border:0;image: url(:/images/min.png);background-color:white}\n"
"QPushButton::pressed{border:0;image: url(:/images/min.png);background-color:#DDDDDD}\n"
""));
        module_info_close = new QPushButton(module_title_area);
        module_info_close->setObjectName(QStringLiteral("module_info_close"));
        module_info_close->setGeometry(QRect(400, 0, 50, 30));
        module_info_close->setStyleSheet(QLatin1String("\n"
"QPushButton{border:0;image: url(:/images/close.png)}\n"
"QPushButton::hover{border:0;image: url(:/images/close.png);background-color:#CC0033}\n"
"QPushButton::pressed{border:0;image: url(:/images/close.png);background-color:#FF9999}\n"
""));
        main_area = new QWidget(centralWidget);
        main_area->setObjectName(QStringLiteral("main_area"));
        main_area->setGeometry(QRect(0, 30, 450, 260));
        main_area->setStyleSheet(QLatin1String("#main_area{\n"
"	background-color:#333333;\n"
"}"));
        eq_con_state = new QLabel(main_area);
        eq_con_state->setObjectName(QStringLiteral("eq_con_state"));
        eq_con_state->setGeometry(QRect(355, 10, 90, 30));
        eq_con_state->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:1px solid #FF4D4D4D;\n"
"border-left:0;\n"
"color:red;\n"
"font:bold 13px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"}"));
        eq_con_state->setAlignment(Qt::AlignCenter);
        type = new QLabel(main_area);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(275, 10, 80, 30));
        type->setStyleSheet(QString::fromUtf8("font:13px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:white;\n"
"background-color: #FF4D4D4D;"));
        type->setAlignment(Qt::AlignCenter);
        data_camera_box = new QGroupBox(main_area);
        data_camera_box->setObjectName(QStringLiteral("data_camera_box"));
        data_camera_box->setGeometry(QRect(5, 50, 440, 205));
        data_camera_box->setStyleSheet(QLatin1String("#data_camera_box{\n"
"	border:0;\n"
"	background-color: #FF1A1A1A;\n"
"}"));
        IMU_CAMERA_INFO = new QLabel(data_camera_box);
        IMU_CAMERA_INFO->setObjectName(QStringLiteral("IMU_CAMERA_INFO"));
        IMU_CAMERA_INFO->setGeometry(QRect(6, 0, 220, 25));
        IMU_CAMERA_INFO->setStyleSheet(QString::fromUtf8("background-color: #FF1A1A1A;\n"
"font:13px '\345\276\256\350\275\257\351\233\205\351\273\221'"));
        data_camera_box_bottom = new QGroupBox(data_camera_box);
        data_camera_box_bottom->setObjectName(QStringLiteral("data_camera_box_bottom"));
        data_camera_box_bottom->setGeometry(QRect(0, 25, 441, 181));
        data_camera_box_bottom->setStyleSheet(QLatin1String("#data_camera_box_bottom{\n"
"	background-color: #FF232323;\n"
"	border:0;\n"
"}\n"
"\n"
""));
        camera_box = new QWidget(data_camera_box_bottom);
        camera_box->setObjectName(QStringLiteral("camera_box"));
        camera_box->setGeometry(QRect(5, 5, 430, 71));
        camera_box->setStyleSheet(QLatin1String("#camera_box{\n"
"	background-color: #FF232323;\n"
"	border:1 solid #FF333333;\n"
"	selection-background-color: #FF999999;\n"
"	color:#FFB3B3B3;\n"
"}"));
        hmd_data_path_set = new QPushButton(camera_box);
        hmd_data_path_set->setObjectName(QStringLiteral("hmd_data_path_set"));
        hmd_data_path_set->setGeometry(QRect(355, 30, 70, 30));
        hmd_data_path_set->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color: #FF4D4D4D;\n"
"border:0;\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"border:0 white;\n"
"background-color:rgba(255,255,255,0.1);\n"
"color:white;\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}\n"
"QPushButton::pressed{\n"
"border:1px solid rgba(255,255,255,0.2);\n"
"background-color:rgba(255,255,255,0.2);\n"
"color:white;\n"
"font:14px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}"));
        hmd_data_path = new QLineEdit(camera_box);
        hmd_data_path->setObjectName(QStringLiteral("hmd_data_path"));
        hmd_data_path->setGeometry(QRect(10, 30, 341, 30));
        hmd_data_path->setStyleSheet(QString::fromUtf8("border: 1px solid #666666;\n"
"font:13px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:#E6E6E6;\n"
"background-color:#4D4D4D;"));
        hmd_data_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hmd_data_path->setDragEnabled(false);
        hmd_data_path->setReadOnly(false);
        hmd_data_path_title = new QLabel(camera_box);
        hmd_data_path_title->setObjectName(QStringLiteral("hmd_data_path_title"));
        hmd_data_path_title->setGeometry(QRect(10, 0, 270, 30));
        hmd_data_path_title->setStyleSheet(QString::fromUtf8("font:13px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:#E6E6E6;\n"
""));
        hmd_exec_area = new QWidget(data_camera_box_bottom);
        hmd_exec_area->setObjectName(QStringLiteral("hmd_exec_area"));
        hmd_exec_area->setGeometry(QRect(5, 80, 430, 95));
        hmd_exec_area->setStyleSheet(QLatin1String("#hmd_exec_area{\n"
"	background-color: #FF232323;\n"
"	border:1 solid #FF333333;\n"
"	selection-background-color: #FF999999;\n"
"	color:#FFB3B3B3;\n"
"}"));
        m_machine_pose = new QLabel(hmd_exec_area);
        m_machine_pose->setObjectName(QStringLiteral("m_machine_pose"));
        m_machine_pose->setGeometry(QRect(5, 5, 300, 85));
        m_machine_pose->setStyleSheet(QString::fromUtf8("border:1 solid #FF333333;\n"
"font:13px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:white"));
        collect_start = new QPushButton(hmd_exec_area);
        collect_start->setObjectName(QStringLiteral("collect_start"));
        collect_start->setGeometry(QRect(310, 5, 115, 80));
        collect_start->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color: #FF4D4D4D;\n"
"border:0;\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"border:0 white;\n"
"background-color:rgba(255,255,255,0.1);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}\n"
"QPushButton::pressed{\n"
"border:1px solid rgba(255,255,255,0.2);\n"
"background-color:rgba(255,255,255,0.2);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}"));
        Camera_mask = new QWidget(data_camera_box);
        Camera_mask->setObjectName(QStringLiteral("Camera_mask"));
        Camera_mask->setGeometry(QRect(-440, 25, 440, 140));
        Camera_mask->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0.5);"));
        waring_Info_camera_c = new QLabel(Camera_mask);
        waring_Info_camera_c->setObjectName(QStringLiteral("waring_Info_camera_c"));
        waring_Info_camera_c->setGeometry(QRect(20, 20, 330, 101));
        waring_Info_camera_c->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font:bold 18px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color:transparent;\n"
"border:0;\n"
"color:white;\n"
"}"));
        waring_Info_camera_c->setAlignment(Qt::AlignCenter);
        warning_info = new QLabel(main_area);
        warning_info->setObjectName(QStringLiteral("warning_info"));
        warning_info->setGeometry(QRect(40, 12, 220, 30));
        warning_info->setStyleSheet(QString::fromUtf8("\n"
"color:#39F354;\n"
"font: bold 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
""));
        warning_image = new QLabel(main_area);
        warning_image->setObjectName(QStringLiteral("warning_image"));
        warning_image->setGeometry(QRect(10, 10, 25, 30));
        warning_image->setStyleSheet(QStringLiteral("image: url(:/images/warning_green.png)"));
        Camera_Imu_mark_mask = new QWidget(main_area);
        Camera_Imu_mark_mask->setObjectName(QStringLiteral("Camera_Imu_mark_mask"));
        Camera_Imu_mark_mask->setGeometry(QRect(-450, 0, 450, 260));
        Camera_Imu_mark_mask->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0.5);"));
        waring_Info_camera_c_4 = new QLabel(Camera_Imu_mark_mask);
        waring_Info_camera_c_4->setObjectName(QStringLiteral("waring_Info_camera_c_4"));
        waring_Info_camera_c_4->setGeometry(QRect(100, 60, 300, 101));
        waring_Info_camera_c_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font:bold 18px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color:transparent;\n"
"border:0;\n"
"color:white;\n"
"}"));
        waring_Info_camera_c_4->setAlignment(Qt::AlignCenter);
        image = new QLabel(Camera_Imu_mark_mask);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(110, 60, 50, 100));
        image->setStyleSheet(QLatin1String("image: url(:/images/disconnect.png);\n"
"background-color:transparent"));
        hmd_imu_tips = new QGroupBox(centralWidget);
        hmd_imu_tips->setObjectName(QStringLiteral("hmd_imu_tips"));
        hmd_imu_tips->setGeometry(QRect(150, 0, 300, 290));
        hmd_imu_tips->setStyleSheet(QLatin1String("#hmd_imu_tips{\n"
"	background-color: #4D4D4D;\n"
"	border:1 solid #FF333333;\n"
"}"));
        hmd_imu_guide = new QLabel(hmd_imu_tips);
        hmd_imu_guide->setObjectName(QStringLiteral("hmd_imu_guide"));
        hmd_imu_guide->setGeometry(QRect(10, 1, 289, 29));
        hmd_imu_guide->setStyleSheet(QString::fromUtf8("background-color: #4D4D4D;\n"
"font:13px '\345\276\256\350\275\257\351\233\205\351\273\221'"));
        hmd_imu_tips_bottom = new QGroupBox(hmd_imu_tips);
        hmd_imu_tips_bottom->setObjectName(QStringLiteral("hmd_imu_tips_bottom"));
        hmd_imu_tips_bottom->setGeometry(QRect(0, 30, 300, 260));
        hmd_imu_tips_bottom->setStyleSheet(QLatin1String("#hmd_imu_tips_bottom{\n"
"	background-color: #FF232323;\n"
"	border:0;\n"
"}\n"
"\n"
""));
        hmd_umu_tips_box = new QWidget(hmd_imu_tips_bottom);
        hmd_umu_tips_box->setObjectName(QStringLiteral("hmd_umu_tips_box"));
        hmd_umu_tips_box->setGeometry(QRect(5, 5, 290, 251));
        hmd_umu_tips_box->setStyleSheet(QLatin1String("#hmd_umu_tips_box{\n"
"	background-color: #FF232323;\n"
"	border:1 solid #FF333333;\n"
"	selection-background-color: #FF999999;\n"
"	color:#FFB3B3B3;\n"
"}"));
        err_tips = new QLabel(hmd_umu_tips_box);
        err_tips->setObjectName(QStringLiteral("err_tips"));
        err_tips->setGeometry(QRect(5, 35, 280, 41));
        err_tips->setStyleSheet(QString::fromUtf8("	border:1 solid #FF333333;\n"
"color:#39F354;\n"
"font: bold 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
""));
        err_tips->setAlignment(Qt::AlignCenter);
        start_time = new QLabel(hmd_umu_tips_box);
        start_time->setObjectName(QStringLiteral("start_time"));
        start_time->setGeometry(QRect(5, 165, 280, 80));
        start_time->setStyleSheet(QString::fromUtf8("border:1 solid #FF333333;\n"
"color:#39F354;\n"
"font: bold 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
""));
        start_time->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(hmd_umu_tips_box);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(5, 5, 280, 30));
        label_3->setStyleSheet(QString::fromUtf8("font:14px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:#E6E6E6;\n"
"background-color: #FF4D4D4D;\n"
""));
        label_4 = new QLabel(hmd_umu_tips_box);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(5, 135, 280, 30));
        label_4->setStyleSheet(QString::fromUtf8("font:14px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:#E6E6E6;\n"
"background-color: #FF4D4D4D;\n"
""));
        mask_all_box = new QWidget(hmd_umu_tips_box);
        mask_all_box->setObjectName(QStringLiteral("mask_all_box"));
        mask_all_box->setGeometry(QRect(85, 80, 200, 50));
        mask_all_box->setStyleSheet(QLatin1String("#mask_all_box{\n"
"		background-color: #FF232323;\n"
"	border:1 solid #FF333333;\n"
"	selection-background-color: #FF999999;\n"
"	color:#FFB3B3B3;\n"
"}"));
        imu_collect = new QPushButton(mask_all_box);
        imu_collect->setObjectName(QStringLiteral("imu_collect"));
        imu_collect->setGeometry(QRect(10, 10, 180, 30));
        imu_collect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color: #FF4D4D4D;\n"
"border:0;\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"border:0 white;\n"
"background-color:rgba(255,255,255,0.1);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}\n"
"QPushButton::pressed{\n"
"border:1px solid rgba(255,255,255,0.2);\n"
"background-color:rgba(255,255,255,0.2);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}"));
        label_5 = new QLabel(hmd_umu_tips_box);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(5, 80, 81, 50));
        label_5->setStyleSheet(QString::fromUtf8("font:15px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color:#E6E6E6;\n"
"background-color: #FF4D4D4D;\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        collect_start_camera = new QPushButton(centralWidget);
        collect_start_camera->setObjectName(QStringLiteral("collect_start_camera"));
        collect_start_camera->setGeometry(QRect(370, 360, 115, 41));
        collect_start_camera->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"background-color: #FF4D4D4D;\n"
"border:0;\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"border:0 white;\n"
"background-color:rgba(255,255,255,0.1);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}\n"
"QPushButton::pressed{\n"
"border:1px solid rgba(255,255,255,0.2);\n"
"background-color:rgba(255,255,255,0.2);\n"
"color:white;\n"
"font:15px '\345\276\256\350\275\257\351\233\205\351\273\221'\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        hmd_imu_tips->raise();
        module_title_area->raise();
        main_area->raise();
        collect_start_camera->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\244\264\346\230\276\344\277\241\346\201\257\351\207\207\351\233\206 1.0.0", nullptr));
        module_title->setText(QApplication::translate("MainWindow", "INDEMIDE  HMD-INFO COLLECT 1.0.0", nullptr));
        test_area->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", nullptr));
        module_info_min->setText(QString());
        module_info_close->setText(QString());
        eq_con_state->setText(QApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245", nullptr));
        type->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207", nullptr));
        data_camera_box->setTitle(QString());
        IMU_CAMERA_INFO->setText(QApplication::translate("MainWindow", "<html><head/><body><span style=\" color:#ffffff;\"><p>\345\244\264\346\230\276\350\256\276\345\244\207 <b style=\" color:#39F354;\">IMU | \347\233\270\346\234\272\346\226\207\344\273\266</b> </p></body></html>", nullptr));
        data_camera_box_bottom->setTitle(QString());
        hmd_data_path_set->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        hmd_data_path_title->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256 IMU | \347\233\270\346\234\272\346\226\207\344\273\266 \345\255\230\346\224\276\345\234\260\345\235\200", nullptr));
        m_machine_pose->setText(QApplication::translate("MainWindow", "                            \346\234\252\350\277\236\346\216\245\345\210\260\350\256\276\345\244\207", nullptr));
        collect_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        waring_Info_camera_c->setText(QApplication::translate("MainWindow", "\345\205\266\344\273\226\346\225\260\346\215\256\351\207\207\351\233\206\346\234\237\351\227\264\346\255\244\345\212\237\350\203\275 \347\246\201\347\224\250", nullptr));
        warning_info->setText(QApplication::translate("MainWindow", " \346\263\250\357\274\232\345\233\276\347\211\207\351\207\207\351\233\206\350\257\267\346\263\250\346\204\217\347\243\201\347\233\230\345\256\271\351\207\217", nullptr));
        warning_image->setText(QString());
        waring_Info_camera_c_4->setText(QApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245\345\210\260\350\256\276\345\244\207\343\200\202", nullptr));
        image->setText(QString());
        hmd_imu_tips->setTitle(QString());
        hmd_imu_guide->setText(QApplication::translate("MainWindow", "<html><head/><body><span style=\" color:#ffffff;\"><p>Bate 1.0.0</p></body></html>", nullptr));
        hmd_imu_tips_bottom->setTitle(QString());
        err_tips->setText(QApplication::translate("MainWindow", "IMU >2MS   Camera > 25ms", nullptr));
        start_time->setText(QApplication::translate("MainWindow", "\345\267\262\351\207\207\351\233\206\346\227\266\351\227\264\357\274\2320S", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "   \350\257\257\345\267\256\346\240\207\345\207\206", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "   \351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        imu_collect->setText(QApplication::translate("MainWindow", "IMU | Camera", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\257\257\345\267\256\351\207\207\351\233\206", nullptr));
        collect_start_camera->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272 \351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
