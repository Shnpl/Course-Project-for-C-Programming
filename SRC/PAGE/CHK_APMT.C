/* SYSTEM INCLUDES START */
#include <STDIO.H>
#include <GRAPHICS.H>
#include <STDLIB.H>
#include <DOS.H>
#include <STRING.H>
#include <BIOS.H>
/* SYSTEM INCLUDE END */

/* BFL INCLUDES START */
#include "INCLUDE/GENERAL.H"
#include "INCLUDE/MOUSE.H"
#include "INCLUDE/BUTTON.H"
#include "INCLUDE/TEXTBOX.H"
#include "INCLUDE/CHN.H"
#include "INCLUDE/LABEL.H"
/*BFL INCLUDES END*/

/*OTHER INCLUDES START*/
#include "INCLUDE/CHK_APMT.H"
/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */

void chk_apmt_button_exit_init(BFL_button*);
void chk_apmt_button_confirm_init(BFL_button*);
void chk_apmt_textbox_tel_init(BFL_textbox*);
void chk_apmt_textbox_liaison_init(BFL_textbox*);
void chk_apmt_textbox_licence_init(BFL_textbox*);

void chk_apmt_label_province_init(BFL_label*);
void chk_apmt_label_messagebox_init(BFL_label*);
void chk_apmt_label_year_init(BFL_label*);
void chk_apmt_label_month_init(BFL_label*);
void chk_apmt_label_day_init(BFL_label*);

void chk_apmt_button_year_plus_init(BFL_button*);
void chk_apmt_button_year_minus_init(BFL_button*);

void chk_apmt_button_month_plus_init(BFL_button*);
void chk_apmt_button_month_minus_init(BFL_button*);

void chk_apmt_button_day_plus_init(BFL_button*);
void chk_apmt_button_day_minus_init(BFL_button*);

void chk_apmt_button_province_01_init(BFL_button*); //京
void chk_apmt_button_province_02_init(BFL_button*); //沪
void chk_apmt_button_province_03_init(BFL_button*); //津
void chk_apmt_button_province_04_init(BFL_button*); //渝
void chk_apmt_button_province_05_init(BFL_button*); //蒙

void chk_apmt_button_province_06_init(BFL_button*); //宁
void chk_apmt_button_province_07_init(BFL_button*); //新
void chk_apmt_button_province_08_init(BFL_button*); //藏
void chk_apmt_button_province_09_init(BFL_button*); //桂
void chk_apmt_button_province_10_init(BFL_button*); //黑

void chk_apmt_button_province_11_init(BFL_button*); //辽
void chk_apmt_button_province_12_init(BFL_button*); //吉
void chk_apmt_button_province_13_init(BFL_button*); //冀
void chk_apmt_button_province_14_init(BFL_button*); //鲁
void chk_apmt_button_province_15_init(BFL_button*); //晋

void chk_apmt_button_province_16_init(BFL_button*); //陕
void chk_apmt_button_province_17_init(BFL_button*); //甘
void chk_apmt_button_province_18_init(BFL_button*); //青
void chk_apmt_button_province_19_init(BFL_button*); //豫
void chk_apmt_button_province_20_init(BFL_button*); //皖

void chk_apmt_button_province_21_init(BFL_button*); //鄂
void chk_apmt_button_province_22_init(BFL_button*); //湘
void chk_apmt_button_province_23_init(BFL_button*); //苏
void chk_apmt_button_province_24_init(BFL_button*); //浙
void chk_apmt_button_province_25_init(BFL_button*); //赣

void chk_apmt_button_province_26_init(BFL_button*); //闽
void chk_apmt_button_province_27_init(BFL_button*); //粤
void chk_apmt_button_province_28_init(BFL_button*); //琼
void chk_apmt_button_province_29_init(BFL_button*); //川
void chk_apmt_button_province_30_init(BFL_button*); //滇

void chk_apmt_button_province_31_init(BFL_button*); //贵

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int CHK_APMT(char *user_ID)
{
    /* DEFINITION START */

    int page = _CHK_APMT;
    int i=0;
    int year = 2021;
    int month = 4;
    int day = 25;
    FILE* chk_apmt_file = NULL;
    FILE* ID_file =NULL;
    
    char temp_ID[20]={'\0'};
    char rand_ID[20]={'\0'};
    int ID_OK = SET;
 

    int file_write_OK = RESET;
    //int j=0;
    int tel_OK = SET;
    int appointment_OK = SET; 
    check_appointment check_appointment_handle;
    BFL_button button_exit;
    BFL_button button_confirm;
    BFL_textbox textbox_tel;
    BFL_textbox textbox_liaison;
    BFL_textbox textbox_licence;
    BFL_label label_province;
    BFL_label label_messagebox;
    BFL_label label_year;
    BFL_label label_month;
    BFL_label label_day;

    BFL_button button_year_plus;
    BFL_button button_year_minus;

    BFL_button button_month_plus;
    BFL_button button_month_minus;

    BFL_button button_day_plus;
    BFL_button button_day_minus;

    BFL_button button_province_01;
    BFL_button button_province_02;
    BFL_button button_province_03;
    BFL_button button_province_04;
    BFL_button button_province_05;

    BFL_button button_province_06;
    BFL_button button_province_07;
    BFL_button button_province_08;
    BFL_button button_province_09;
    BFL_button button_province_10;

    BFL_button button_province_11;
    BFL_button button_province_12;
    BFL_button button_province_13;
    BFL_button button_province_14;
    BFL_button button_province_15;

    BFL_button button_province_16;
    BFL_button button_province_17;
    BFL_button button_province_18;
    BFL_button button_province_19;
    BFL_button button_province_20;

    BFL_button button_province_21;
    BFL_button button_province_22;
    BFL_button button_province_23;
    BFL_button button_province_24;
    BFL_button button_province_25;

    BFL_button button_province_26;
    BFL_button button_province_27;
    BFL_button button_province_28;
    BFL_button button_province_29;
    BFL_button button_province_30;
    BFL_button button_province_31;

    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    memset(check_appointment_handle.user_id, 0, 50);
    strcpy(check_appointment_handle.user_id, user_ID);
    check_appointment_handle.car_province = -1;
    memset(check_appointment_handle.car_licence,0,7);
    memset(check_appointment_handle.liason,0,50);
    memset(check_appointment_handle.tel,0,20);
    check_appointment_handle.year = 2021;
    check_appointment_handle.month = 4;
    check_appointment_handle.day = 25;
 

    chk_apmt_button_exit_init(&button_exit);
    chk_apmt_button_confirm_init(&button_confirm);
    chk_apmt_textbox_tel_init(&textbox_tel);
    chk_apmt_textbox_liaison_init(&textbox_liaison);
    chk_apmt_textbox_licence_init(&textbox_licence);
    

    chk_apmt_label_province_init(&label_province);
    chk_apmt_label_messagebox_init(&label_messagebox);
    
    chk_apmt_label_year_init(&label_year);
    chk_apmt_button_year_plus_init(&button_year_plus);
    chk_apmt_button_year_minus_init(&button_year_minus);
    
    chk_apmt_label_month_init(&label_month);
    chk_apmt_button_month_plus_init(&button_month_plus);
    chk_apmt_button_month_minus_init(&button_month_minus);

    chk_apmt_label_day_init(&label_day);
    chk_apmt_button_day_plus_init(&button_day_plus);
    chk_apmt_button_day_minus_init(&button_day_minus);

    chk_apmt_button_province_01_init(&button_province_01);
    chk_apmt_button_province_02_init(&button_province_02);
    chk_apmt_button_province_03_init(&button_province_03);
    chk_apmt_button_province_04_init(&button_province_04);
    chk_apmt_button_province_05_init(&button_province_05);

    chk_apmt_button_province_06_init(&button_province_06);
    chk_apmt_button_province_07_init(&button_province_07);
    chk_apmt_button_province_08_init(&button_province_08);
    chk_apmt_button_province_09_init(&button_province_09);
    chk_apmt_button_province_10_init(&button_province_10);

    chk_apmt_button_province_11_init(&button_province_11);
    chk_apmt_button_province_12_init(&button_province_12);
    chk_apmt_button_province_13_init(&button_province_13);
    chk_apmt_button_province_14_init(&button_province_14);
    chk_apmt_button_province_15_init(&button_province_15);

    chk_apmt_button_province_16_init(&button_province_16);
    chk_apmt_button_province_17_init(&button_province_17);
    chk_apmt_button_province_18_init(&button_province_18);
    chk_apmt_button_province_19_init(&button_province_19);
    chk_apmt_button_province_20_init(&button_province_20);

    chk_apmt_button_province_21_init(&button_province_21);
    chk_apmt_button_province_22_init(&button_province_22);
    chk_apmt_button_province_23_init(&button_province_23);
    chk_apmt_button_province_24_init(&button_province_24);
    chk_apmt_button_province_25_init(&button_province_25);

    chk_apmt_button_province_26_init(&button_province_26);
    chk_apmt_button_province_27_init(&button_province_27);
    chk_apmt_button_province_28_init(&button_province_28);
    chk_apmt_button_province_29_init(&button_province_29);
    chk_apmt_button_province_30_init(&button_province_30);
    chk_apmt_button_province_31_init(&button_province_31);

    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1, LIGHTGRAY);
    bar(0, 420, 640, 480);

    CHN_print(22, 21, "预约", 48, 48, DARKGRAY, 2);
    CHN_print(22, 71, "年检", 48, 48, DARKGRAY, 2);

    CHN_print(20, 20, "预约", 48, 48, RED, 2);
    CHN_print(20, 70, "年检", 48, 48, RED, 2);

    CHN_print(140, 40, "请输入预约车辆号牌：", 16, 16, RED, 10);
    CHN_print(124, 60, "（暂时仅支持大陆地区）", 16, 16, RED, 11);

    CHN_print(188, 160, "请输入联系人：", 16, 16, RED, 7);
    CHN_print(172, 220, "请输入联系电话：", 16, 16, RED, 8);
    CHN_print(220, 260, "预约时间：", 16, 16, RED, 5);
    CHN_print(220, 300, "预约地点：", 16, 16, RED, 5);
    setfillstyle(1, DARKGRAY);
    bar(330, 295, 470, 320);
    CHN_print(380, 300, "自动", 16, 16, YELLOW, 2);

    CHN_print(20, 350, "费用（代办费）：", 16, 16, RED, 8);
    CHN_print(20, 380, "（不含年检费用）", 16, 16, RED, 8);
    setfillstyle(1, DARKGRAY);
    bar(144, 345, 200, 370);
    setcolor(YELLOW);
    settextstyle(0, 0, 1);
    outtextxy(150, 355, "100");
    CHN_print(180, 350, "元", 16, 16, YELLOW, 1);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(325,35,350,60);

    /* DRAW END */

    /*WHILE*/
    while (page == _CHK_APMT)
    {
        /* ACTION START */
        BFL_mouse_action();
        BFL_button_action(&button_exit);
        BFL_button_action(&button_confirm);

        BFL_textbox_action(&textbox_tel);
        BFL_textbox_action(&textbox_liaison);
        BFL_textbox_action(&textbox_licence);

        BFL_label_action(&label_province);
        BFL_label_action(&label_messagebox);
        BFL_label_action(&label_year);
        BFL_label_action(&label_month);
        BFL_label_action(&label_day);

        BFL_button_action(&button_year_plus);
        BFL_button_action(&button_year_minus);

        BFL_button_action(&button_month_plus);
        BFL_button_action(&button_month_minus);

        BFL_button_action(&button_day_plus);
        BFL_button_action(&button_day_minus);
        {
            BFL_button_action(&button_province_01);
            BFL_button_action(&button_province_02);
            BFL_button_action(&button_province_03);
            BFL_button_action(&button_province_04);
            BFL_button_action(&button_province_05);

            BFL_button_action(&button_province_06);
            BFL_button_action(&button_province_07);
            BFL_button_action(&button_province_08);
            BFL_button_action(&button_province_09);
            BFL_button_action(&button_province_10);

            BFL_button_action(&button_province_11);
            BFL_button_action(&button_province_12);
            BFL_button_action(&button_province_13);
            BFL_button_action(&button_province_14);
            BFL_button_action(&button_province_15);

            BFL_button_action(&button_province_16);
            BFL_button_action(&button_province_17);
            BFL_button_action(&button_province_18);
            BFL_button_action(&button_province_19);
            BFL_button_action(&button_province_20);

            BFL_button_action(&button_province_21);
            BFL_button_action(&button_province_22);
            BFL_button_action(&button_province_23);
            BFL_button_action(&button_province_24);
            BFL_button_action(&button_province_25);

            BFL_button_action(&button_province_26);
            BFL_button_action(&button_province_27);
            BFL_button_action(&button_province_28);
            BFL_button_action(&button_province_29);
            BFL_button_action(&button_province_30);

            BFL_button_action(&button_province_31);
        }

        /* ACTION END */

        /*CODE START*/

        {if (button_province_01.status == PRESS)
        {
            strcpy(label_province.display_text, "京");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 1;
        }
        if (button_province_02.status == PRESS)
        {
            strcpy(label_province.display_text, "沪");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 2;
        }
        if (button_province_03.status == PRESS)
        {
            strcpy(label_province.display_text, "津");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 3;
        }
        if (button_province_04.status == PRESS)
        {
            strcpy(label_province.display_text, "渝");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 4;
        }
        if (button_province_05.status == PRESS)
        {
            strcpy(label_province.display_text, "蒙");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 5;
        }

        if (button_province_06.status == PRESS)
        {
            strcpy(label_province.display_text, "宁");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 6;
        }
        if (button_province_07.status == PRESS)
        {
            strcpy(label_province.display_text, "新");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 7;
        }
        if (button_province_08.status == PRESS)
        {
            strcpy(label_province.display_text, "藏");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 8;
        }
        if (button_province_09.status == PRESS)
        {
            strcpy(label_province.display_text, "桂");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 9;
        }
        if (button_province_10.status == PRESS)
        {
            strcpy(label_province.display_text, "黑");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 10;
        }

        if (button_province_11.status == PRESS)
        {
            strcpy(label_province.display_text, "辽");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 11;
        }
        if (button_province_12.status == PRESS)
        {
            strcpy(label_province.display_text, "吉");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 12;
        }
        if (button_province_13.status == PRESS)
        {
            strcpy(label_province.display_text, "冀");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 13;
        }
        if (button_province_14.status == PRESS)
        {
            strcpy(label_province.display_text, "鲁");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 14;
        }
        if (button_province_15.status == PRESS)
        {
            strcpy(label_province.display_text, "晋");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 15;
            
        }

        if (button_province_16.status == PRESS)
        {
            strcpy(label_province.display_text, "陕");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 16;
        }
        if (button_province_17.status == PRESS)
        {
            strcpy(label_province.display_text, "甘");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 17;
        }
        if (button_province_18.status == PRESS)
        {
            strcpy(label_province.display_text, "青");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 18;
        }
        if (button_province_19.status == PRESS)
        {
            strcpy(label_province.display_text, "豫");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 19;
        }
        if (button_province_20.status == PRESS)
        {
            strcpy(label_province.display_text, "皖");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 20;
        }

        if (button_province_21.status == PRESS)
        {
            strcpy(label_province.display_text, "鄂");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 21;
        }
        if (button_province_22.status == PRESS)
        {
            strcpy(label_province.display_text, "湘");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 22;
        }
        if (button_province_23.status == PRESS)
        {
            strcpy(label_province.display_text, "苏");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 23;
        }
        if (button_province_24.status == PRESS)
        {
            strcpy(label_province.display_text, "浙");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 24;
        }
        if (button_province_25.status == PRESS)
        {
            strcpy(label_province.display_text, "赣");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 25;
        }

        if (button_province_26.status == PRESS)
        {
            strcpy(label_province.display_text, "闽");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 26;
        }
        if (button_province_27.status == PRESS)
        {
            strcpy(label_province.display_text, "粤");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 27;
        }
        if (button_province_28.status == PRESS)
        {
            strcpy(label_province.display_text, "琼");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 28;
        }
        if (button_province_29.status == PRESS)
        {
            strcpy(label_province.display_text, "川");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 29;
        }
        if (button_province_30.status == PRESS)
        {
            strcpy(label_province.display_text, "滇");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 30;
        }
        if (button_province_31.status == PRESS)
        {
            strcpy(label_province.display_text, "贵");
            label_province.word_length = 1;
            label_province.reDraw = SET;
            check_appointment_handle.car_province = 31;
        }
        }
        
        if (button_exit.status == PRESS)
        {
            page = _VEH_ADMI;
            break;
        }
        if(button_year_plus.status == PRESS)
        {
            if(year < 2023)
            {
                year++;
                 itoa(year,label_year.display_text,10);
                delay(150);
                label_year.reDraw = SET;
            }
            
        }
        if(button_year_minus.status == PRESS)
        {
            if(year > 2021)
            {
                year--;
                itoa(year,label_year.display_text,10);
                delay(150);
                label_year.reDraw = SET;
            }
        }

        if(button_month_plus.status == PRESS)
        {
            if(month < 12)
            {
                month++;
                itoa(month,label_month.display_text,10);
                delay(150);
                label_month.reDraw = SET;
            }
            
            if(month == 2 && day > 28)
            {
                day = 28;
                itoa(day,label_day.display_text,10);
                label_day.reDraw = SET;
            }
            if((month == 4||month == 6||month == 9||month == 11) && day > 30 )
            {
                day = 30;
                itoa(day,label_day.display_text,10);
                label_day.reDraw = SET;
            }
        }
        if(button_month_minus.status == PRESS)
        {
            if(month > 1)
            {
                itoa(day,label_day.display_text,10);
                delay(150);
                label_day.reDraw = SET;

                month--;
                itoa(month,label_month.display_text,10);
                delay(150);
                label_month.reDraw = SET;
            }

            if(month == 2 && day > 28)
            {
                day = 28;
                itoa(day,label_day.display_text,10);
                label_day.reDraw = SET;
            }
            if((month == 4||month == 6||month == 9||month == 11) && day > 30 )
            {
                day = 30;
                itoa(day,label_day.display_text,10);
                label_day.reDraw = SET;
            }
        }

        if(button_day_plus.status == PRESS)
        {
            if(month == 2)
            {
                if(day < 28)
                {
                    day++;
                    itoa(day,label_day.display_text,10);
                    delay(150);
                    label_day.reDraw = SET;
                }
            }
            if(month == 1||month == 3||month ==5||month == 7||month == 8||month == 10||month == 12)
            {
                if(day < 31)
                {
                    day++;
                    itoa(day,label_day.display_text,10);
                    delay(150);
                    label_day.reDraw = SET;
                }
            }
            if(month == 4||month == 6||month == 9||month == 11)
            {
                if(day < 30)
                {
                    day++;
                    itoa(day,label_day.display_text,10);
                    delay(150);
                    label_day.reDraw = SET;
                }
            }       
            
        }
        if(button_day_minus.status == PRESS)
        {
            if(day > 1)
            {
                day--;
                itoa(day,label_day.display_text,10);
                delay(150);
                label_day.reDraw = SET;
            }
        }

        strcpy(check_appointment_handle.car_licence,textbox_licence.true_text);
        strcpy(check_appointment_handle.liason,textbox_liaison.true_text);
        strcpy(check_appointment_handle.tel,textbox_tel.true_text);
        check_appointment_handle.year = year;
        check_appointment_handle.month = month;
        check_appointment_handle.day = day;

        
        if(button_confirm.status == PRESS)
        {
            
            
            //下面的几行是debug时候用到的
            //setcolor(BROWN);
            //outtextxy(0,200,check_appointment_handle.car_licence);
	        //outtextxy(0,240,check_appointment_handle.liason);
	        //outtextxy(0,280,check_appointment_handle.tel);

            tel_OK = SET;
            appointment_OK = SET;
            if(strlen(check_appointment_handle.tel) != 11)
            {
                tel_OK = RESET;
            }
            else
            {
                for(i = 0;i < 11;i++)
                {
                    if(*((check_appointment_handle.tel)+i)< '0' ||*((check_appointment_handle.tel)+i) > '9')
                    {
                        tel_OK =RESET;
                        break;//?
                    }
                }
            }

            if(strlen(check_appointment_handle.liason) == 0)
            {
                strcpy(label_messagebox.display_text,"联系人不能为空！");
                label_messagebox.word_length = 8;
                label_messagebox.reDraw = SET;
                appointment_OK = RESET;
            }
            if(check_appointment_handle.car_province == -1)
            {
                strcpy(label_messagebox.display_text,"未输入省份！");
                label_messagebox.word_length = 6;
                label_messagebox.reDraw = SET;
                appointment_OK = RESET;
            }
            if(strlen(check_appointment_handle.car_licence) != 6)
            {
                strcpy(label_messagebox.display_text,"车牌输入错误！");
                label_messagebox.word_length = 7;
                label_messagebox.reDraw = SET;
                appointment_OK = RESET;
            }
	        if(tel_OK == RESET)
            {
                strcpy(label_messagebox.display_text,"联系电话输入错误！");
                label_messagebox.word_length = 9;
                label_messagebox.reDraw = SET;
                appointment_OK = RESET;
            }
            
            if(appointment_OK == SET && file_write_OK == RESET)
            {
                if((ID_file=fopen("./FILE/ID.TXT","at+")) == NULL)
                {
                    outtextxy(0,0,"ID.TXT FILE ERROR");
                }
                
                do
                {
                    ID_OK = SET;
                    itoa(rand(),rand_ID,10);
                    
                    while(!feof(ID_file))
                        {
                            if((fread(temp_ID,sizeof(temp_ID),1,ID_file)) == 0)
                            {
                                break;
                            }
                            if(strcmp(temp_ID,rand_ID) == 0)
                            {
                                ID_OK = RESET;
                                rewind(ID_file);
                                break;
                            }
                        }
                } while (ID_OK == RESET);
                fwrite(rand_ID,sizeof(rand_ID),1,ID_file);
                fclose(ID_file);
                strcpy(check_appointment_handle.ID,rand_ID);
                setcolor(BROWN);
                outtextxy(0,0,rand_ID);
                if((chk_apmt_file =fopen("./FILE/CHK_APMT.TXT","at+")) == NULL)
                {
                    outtextxy(0,0,"CHK_APMT.TXT FILE ERROR");
                }
                else
                {

                    fwrite(&check_appointment_handle,sizeof(check_appointment_handle),1,chk_apmt_file);
                    fclose(chk_apmt_file);
                    strcpy(label_messagebox.display_text,"预约成功！");
                    label_messagebox.word_length = 5;
                    label_messagebox.reDraw = SET;
                    file_write_OK = SET;
                   
                    page = _VEH_ADMI;
                }
                
            }
        }

        /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_confirm);
        BFL_textbox_draw(&textbox_tel);
        BFL_textbox_draw(&textbox_liaison);
        BFL_textbox_draw(&textbox_licence);

        BFL_label_draw(&label_province);
        BFL_label_draw(&label_messagebox);
        BFL_label_draw(&label_year);
        BFL_label_draw(&label_month);
        BFL_label_draw(&label_day);

        BFL_button_draw(&button_year_plus);
        BFL_button_draw(&button_year_minus);

        BFL_button_draw(&button_month_plus);
        BFL_button_draw(&button_month_minus);

        BFL_button_draw(&button_day_plus);
        BFL_button_draw(&button_day_minus);

        {
            BFL_button_draw(&button_province_01);
            BFL_button_draw(&button_province_02);
            BFL_button_draw(&button_province_03);
            BFL_button_draw(&button_province_04);
            BFL_button_draw(&button_province_05);

            BFL_button_draw(&button_province_06);
            BFL_button_draw(&button_province_07);
            BFL_button_draw(&button_province_08);
            BFL_button_draw(&button_province_09);
            BFL_button_draw(&button_province_10);

            BFL_button_draw(&button_province_11);
            BFL_button_draw(&button_province_12);
            BFL_button_draw(&button_province_13);
            BFL_button_draw(&button_province_14);
            BFL_button_draw(&button_province_15);

            BFL_button_draw(&button_province_16);
            BFL_button_draw(&button_province_17);
            BFL_button_draw(&button_province_18);
            BFL_button_draw(&button_province_19);
            BFL_button_draw(&button_province_20);

            BFL_button_draw(&button_province_21);
            BFL_button_draw(&button_province_22);
            BFL_button_draw(&button_province_23);
            BFL_button_draw(&button_province_24);
            BFL_button_draw(&button_province_25);

            BFL_button_draw(&button_province_26);
            BFL_button_draw(&button_province_27);
            BFL_button_draw(&button_province_28);
            BFL_button_draw(&button_province_29);
            BFL_button_draw(&button_province_30);

            BFL_button_draw(&button_province_31);
        }

        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200); //防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}

void chk_apmt_button_exit_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 520;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 610;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "退出");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}

void chk_apmt_button_confirm_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 410;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 500;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "确认");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}



void chk_apmt_textbox_tel_init(BFL_textbox *textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 3;

    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

    textboxPtr->position_left = 330;  //可修改
    textboxPtr->position_top = 210;   //可修改
    textboxPtr->position_right = 515; //可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 30;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left + 5;
    textboxPtr->position_shadow_top = textboxPtr->position_top + 5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom + 5;

    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 11;
    textboxPtr->is_secret = RESET;
    textboxPtr->mode = 0;
    BFL_textbox_draw(textboxPtr);

    textboxPtr->reDraw = RESET;
}

void chk_apmt_textbox_liaison_init(BFL_textbox *textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 3;

    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

    textboxPtr->position_left = 330;  //可修改
    textboxPtr->position_top = 155;   //可修改
    textboxPtr->position_right = 515; //可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 30;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left + 5;
    textboxPtr->position_shadow_top = textboxPtr->position_top + 5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom + 5;

    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 11;
    textboxPtr->is_secret = RESET;
    textboxPtr->mode = 0;
    BFL_textbox_draw(textboxPtr);

    textboxPtr->reDraw = RESET;
}

void chk_apmt_textbox_licence_init(BFL_textbox *textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 2;

    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

    textboxPtr->position_left = 360;  //可修改
    textboxPtr->position_top = 35;   //可修改
    textboxPtr->position_right = 455; //可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 25;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left + 5;
    textboxPtr->position_shadow_top = textboxPtr->position_top + 5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom + 5;

    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 6;
    textboxPtr->is_secret = RESET;
    textboxPtr->mode = 2;
    BFL_textbox_draw(textboxPtr);

    textboxPtr->reDraw = RESET;
}

void chk_apmt_label_province_init(BFL_label *labelPtr)
{
    labelPtr->color_box = LIGHTGRAY;
    labelPtr->color_text = RED;

    labelPtr->position_left = 330;
    labelPtr->position_top = 40;
    labelPtr->position_right = 350;
    labelPtr->position_bottom = 60;

    labelPtr->position_text_left = labelPtr->position_left;
    labelPtr->position_text_top = labelPtr->position_top;

    labelPtr->size = 16;
    memset(labelPtr->display_text, 0, 51);
    labelPtr->display_type = 0;
    labelPtr->reDraw = RESET;
}

void chk_apmt_label_messagebox_init(BFL_label *labelPtr)
{
    labelPtr->color_box = YELLOW;
    labelPtr->color_text = RED;

    labelPtr->position_left = 230;
    labelPtr->position_top = 340;
    labelPtr->position_right = 500;
    labelPtr->position_bottom = 390;

    labelPtr->position_text_left = labelPtr->position_left;
    labelPtr->position_text_top = labelPtr->position_top;
    labelPtr->size = 32;
    memset(labelPtr->display_text, 0, 51);
    labelPtr->display_type = 0;
    labelPtr->reDraw = RESET;
}

void chk_apmt_label_year_init(BFL_label* labelPtr)
{
    labelPtr->color_box = LIGHTGRAY;
    labelPtr->color_text = YELLOW;

    labelPtr->position_left = 330;
    labelPtr->position_top = 260;
    labelPtr->position_right = 405;
    labelPtr->position_bottom = 285;

    labelPtr->position_text_left = labelPtr->position_left + 5;
    labelPtr->position_text_top = labelPtr->position_top +5;
    
    labelPtr->size = 16;
    labelPtr->word_length=4;
    memset(labelPtr->display_text, 0, 51);
    strcpy(labelPtr->display_text,"2021");
    labelPtr->display_type = 1;
    labelPtr->en_size =2;
    labelPtr->reDraw = SET;
}
void chk_apmt_button_year_plus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 410;
    buttonPtr->position_top = 252;
    buttonPtr->position_right = 426;
    buttonPtr->position_bottom = 268;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "＋");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}
void chk_apmt_button_year_minus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 410;
    buttonPtr->position_top = 272;
    buttonPtr->position_right = 426;
    buttonPtr->position_bottom = 288;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "－");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_label_month_init(BFL_label* labelPtr)
{
    labelPtr->color_box = LIGHTGRAY;
    labelPtr->color_text = YELLOW;

    labelPtr->position_left = 430;
    labelPtr->position_top = 260;
    labelPtr->position_right = 470;
    labelPtr->position_bottom = 285;

    labelPtr->position_text_left = labelPtr->position_left + 5;
    labelPtr->position_text_top = labelPtr->position_top +5;
    
    labelPtr->size = 16;
    labelPtr->word_length=4;
    memset(labelPtr->display_text, 0, 51);
    strcpy(labelPtr->display_text,"4");
    labelPtr->display_type = 1;
    labelPtr->en_size =2;
    labelPtr->reDraw = SET;
}
void chk_apmt_button_month_plus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 475;
    buttonPtr->position_top = 252;
    buttonPtr->position_right = 491;
    buttonPtr->position_bottom = 268;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "＋");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}
void chk_apmt_button_month_minus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 475;
    buttonPtr->position_top = 272;
    buttonPtr->position_right = 491;
    buttonPtr->position_bottom = 288;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "－");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_label_day_init(BFL_label* labelPtr)
{
    labelPtr->color_box = LIGHTGRAY;
    labelPtr->color_text = YELLOW;

    labelPtr->position_left = 495;
    labelPtr->position_top = 260;
    labelPtr->position_right = 535;
    labelPtr->position_bottom = 285;

    labelPtr->position_text_left = labelPtr->position_left + 5;
    labelPtr->position_text_top = labelPtr->position_top +5;
    
    labelPtr->size = 16;
    labelPtr->word_length=4;
    memset(labelPtr->display_text, 0, 51);
    strcpy(labelPtr->display_text,"25");
    labelPtr->display_type = 1;
    labelPtr->en_size =2;
    labelPtr->reDraw = SET;
}
void chk_apmt_button_day_plus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 540;
    buttonPtr->position_top = 252;
    buttonPtr->position_right = 556;
    buttonPtr->position_bottom = 268;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "＋");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}
void chk_apmt_button_day_minus_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 540;
    buttonPtr->position_top = 272;
    buttonPtr->position_right = 556;
    buttonPtr->position_bottom = 288;

    buttonPtr->is_shadow_enable = RESET;
   
    buttonPtr->position_text_left = buttonPtr->position_left ;
    buttonPtr->position_text_top = buttonPtr->position_top ;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "－");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_01_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 330;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 350;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "京");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_02_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 355;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 375;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "沪");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_03_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 380;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 400;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "津");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_04_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 405;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 425;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "渝");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_05_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 430;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 450;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "蒙");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_06_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 455;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 475;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "宁");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_07_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 480;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 500;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "新");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_08_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 505;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 525;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "藏");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_09_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 530;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 550;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "桂");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_10_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 555;
    buttonPtr->position_top = 70;
    buttonPtr->position_right = 575;
    buttonPtr->position_bottom = 90;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "黑");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_11_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 330;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 350;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "辽");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_12_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 355;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 375;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "吉");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_13_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 380;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 400;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "冀");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_14_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 405;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 425;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "鲁");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_15_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 430;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 450;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "晋");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_16_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 455;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 475;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "陕");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_17_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 480;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 500;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "甘");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_18_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 505;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 525;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "青");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_19_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 530;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 550;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "豫");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_20_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 555;
    buttonPtr->position_top = 95;
    buttonPtr->position_right = 575;
    buttonPtr->position_bottom = 115;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "皖");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_21_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 330;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 350;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "鄂");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_22_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 355;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 375;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "湘");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_23_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 380;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 400;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "苏");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_24_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 405;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 425;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "浙");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_25_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 430;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 450;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "赣");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_26_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 455;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 475;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "闽");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_27_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 480;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 500;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "粤");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_28_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 505;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 525;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "琼");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_29_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 530;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 550;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "川");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_30_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 555;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 575;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "滇");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}

void chk_apmt_button_province_31_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = LIGHTGRAY;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = RED;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 580;
    buttonPtr->position_top = 120;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 140;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 3;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 3;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 3;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 3;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 1;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "贵");
    buttonPtr->text_length = 1;

    buttonPtr->status = REST;
}