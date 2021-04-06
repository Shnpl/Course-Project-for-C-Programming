#ifndef __CHK_APMT_H__
#define __CHK_APMT_H__
/*
预约年检界面函数
参数：char* user_ID 用户名为值的用户ID
返回：int page 跳转页面值 
*/
int CHK_APMT(char* user_ID);
typedef struct check_appointment_struct
{
    char user_id[50];
    int car_province;
    char car_licence[7];
    char liason[50];
    char tel[20];
    int year;
    int month;
    int day;
}check_appointment;

#endif