/***************************************************************************************************************************
 * writing.cpp
 *
 * Author: jiao
 *
 * Update Time: 2020.8.11
 *
 * 说明: mavros写字 写“王”
 *      1.
 *      2.
 *      3.
***************************************************************************************************************************/

#include <ros/ros.h>
#include <fstream>
#include <math.h>
#include <string>
#include <time.h>
#include <queue>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <std_msgs/Bool.h>
#include <px4_command/command.h>


using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>全 局 变 量<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
enum Command
{
    Idle,
    Takeoff,
    Move_ENU,
    Move_Body,
    Hold,
    Land,
    Disarm,
    Failsafe_land,
};
px4_command::command Command_now;
//---------------------------------------飞行参数---------------------------------------------
float height;                //飞行高度
float height_d;                            //高度差
float sleep_time;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "writing");
    ros::NodeHandle nh("~");

    // 频率 [1hz]
    ros::Rate rate(1.0);

    // 【发布】发送给position_control.cpp的命令
    ros::Publisher move_pub = nh.advertise<px4_command::command>("/px4/command", 10);

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>参数读取<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    nh.param<float>("height", height, 1.0);
    nh.param<float>("height_d", height_d, 0.5);
    nh.param<float>("sleep_time", sleep_time, 3.0);



    int check_flag;
    // 这一步是为了程序运行前检查一下参数是否正确
    // 输入1,继续，其他，退出程序
    cout << "height: "<<height<<"[m]"<<endl;
    cout << "height_d: "<<height_d<<"[m]"<<endl;
    cout << "Please check the parameter and setting，1 for go on， else for quit: "<<endl;
    cin >> check_flag;

    if(check_flag != 1)
    {
        return -1;
    }


    int i = 0;
    int comid = 0;
    int point_id = 0;

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>主程序<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //takeoff
    i = 0;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;       //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 0;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        i++;

    }

    //依次发送汉字目标点给position_control.cpp
    //第一个目标点，左上角
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -3*0.1;
        Command_now.pos_sp[1] = 7*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }



    //第二个目标点，右上角
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -3*0.1;
        Command_now.pos_sp[1] = 5*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }


    //第三个目标点，右上角升高度
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -5*0.1;
        Command_now.pos_sp[1] = 4*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第四个目标点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -1*0.1;
        Command_now.pos_sp[1] = 4*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }


    //第五个目标点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -5*0.1;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第六个目标点，右下角
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -3*0.1;
        Command_now.pos_sp[1] = 2*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第七个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -3*0.1;
        Command_now.pos_sp[1] = -6*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第8个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -3*0.1;
        Command_now.pos_sp[1] = 2*0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第9个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -1*0.1;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }


    //第10个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = -1*0.1;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height+height_d;   //左半部分完成升高
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第11个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 1*0.1;
        Command_now.pos_sp[1] = 0.7;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第12个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 5*0.1;
        Command_now.pos_sp[1] = 0.7;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第13个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 5*0.1;
        Command_now.pos_sp[1] = 0.7;
        Command_now.pos_sp[2] = height+height_d;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第14个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 1*0.1;
        Command_now.pos_sp[1] = 0.5;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }


    //第15个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 1*0.1;
        Command_now.pos_sp[1] = 0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }
    //第16个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 5*0.1;
        Command_now.pos_sp[1] = 0.1;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第17个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 5*0.1;
        Command_now.pos_sp[1] = 0.5;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第18个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 1*0.1;
        Command_now.pos_sp[1] = 0.5;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第19个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 1*0.1;
        Command_now.pos_sp[1] = 0.5;
        Command_now.pos_sp[2] = height+height_d;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第20个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 0;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第21个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 0;
        Command_now.pos_sp[1] = -0.6;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第22个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 6*0.1;
        Command_now.pos_sp[1] = -0.6;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第23个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 6*0.1;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第24个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 0;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第25个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 0;
        Command_now.pos_sp[1] = -0.3;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第26个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 6*0.1;
        Command_now.pos_sp[1] = -0.3;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第27个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 6*0.1;
        Command_now.pos_sp[1] = -0.3;
        Command_now.pos_sp[2] = height+height_d;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第28个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 3*0.1;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第29个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 3*0.1;
        Command_now.pos_sp[1] = -0.6;
        Command_now.pos_sp[2] = height;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第30个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 3*0.1;
        Command_now.pos_sp[1] = -0.6;
        Command_now.pos_sp[2] = height+height_d;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }

    //第30个目标点，回到起点
    i = 0;
    point_id++;
    while (i < sleep_time)
    {

        Command_now.command = Move_ENU;  //Move模式
        Command_now.sub_mode = 0;             //子模式：位置控制模式
        Command_now.pos_sp[0] = 3*0;
        Command_now.pos_sp[1] = 0;
        Command_now.pos_sp[2] = height+height_d;
        Command_now.yaw_sp = 0;
        Command_now.comid = comid;
        comid++;

        move_pub.publish(Command_now);

        rate.sleep();

        cout << "Point "<< point_id << endl;

        i++;

    }


    //降落



    Command_now.command = Land;
    move_pub.publish(Command_now);

    rate.sleep();

    cout << "Land"<<endl;





    return 0;
}
