/* SYSTEM INCLUDES START */
#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>
#include<STRING.H>
/* SYSTEM INCLUDE END */

/* BFL INCLUDES START */
#include"INCLUDE/GENERAL.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/TEXTBOX.H"
#include"INCLUDE/CHN.H"
#include"INCLUDE/LABEL.H"
/*BFL INCLUDES END*/

/*OTHER INCLUDES START*/

/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */
void car_serv_button_other_insurance_init(BFL_button* );
void car_serv_button_exit_init(BFL_button* );
void car_serv_button_my_info_init(BFL_button* );

void car_serv_button_car_insurance_page_init(BFL_button*);
void car_serv_button_car_maintenance_page_init(BFL_button*);
void car_serv_button_car_roadside_assistance_page_init(BFL_button*);
void car_serv_button_car_vehicle_administration_page_init(BFL_button*);

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int CAR_SERV(char* user_ID)
{
    /* DEFINITION START */

    int page = _CAR_SERV;
    
    BFL_button button_other_insurance;
    BFL_button button_exit;
    BFL_button button_my_info;
    
    BFL_button button_car_insurance_page;
    BFL_button button_car_maintenance_page;
    BFL_button button_car_roadside_assistance_page;
    BFL_button button_car_vehicle_administration_page;
    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */

    car_serv_button_other_insurance_init(&button_other_insurance );
    car_serv_button_exit_init(&button_exit);
    car_serv_button_my_info_init(&button_my_info);

    car_serv_button_car_insurance_page_init(&button_car_insurance_page);
    car_serv_button_car_maintenance_page_init(&button_car_maintenance_page);
    car_serv_button_car_roadside_assistance_page_init(&button_car_roadside_assistance_page);
    car_serv_button_car_vehicle_administration_page_init(&button_car_vehicle_administration);
    


    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1,LIGHTGRAY);
    bar(0,420,640,480);    
    setfillstyle(1,DARKGRAY);
    bar(600,405,645,465);//按钮的边
    setfillstyle(1,RED);
    bar(595,400,640,460);//按钮的边

    CHN_print(22,21,"汽车",48,48,DARKGRAY,2);
    CHN_print(22,71,"服务",48,48,DARKGRAY,2);

    CHN_print(20,20,"汽车",48,48,RED,2);
    CHN_print(20,70,"服务",48,48,RED,2);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(170+5,400+5,315+5,460+5);
    setfillstyle(SOLID_FILL,RED);
    bar(170,400,315,460);
   


    /* DRAW END */

    /*WHILE*/
    while (page == _CAR_SERV)
    {
        /*ACTION START*/
        BFL_mouse_action();

        BFL_button_action(&button_other_insurance);
        BFL_button_action(&button_exit);
        BFL_button_action(&button_my_info);

        BFL_button_action(&button_car_insurance_page);
        BFL_button_action(&button_car_maintenance_page);
        BFL_button_action(&button_car_roadside_assistance_page);
        BFL_button_action(&button_car_vehicle_administration_page);
        /* ACTION END */

	    /*CODE START*/
        if(button_exit.status == PRESS)
        {
            page = _INITIAL;
            break;
        }
        if(button_my_info.status == PRESS)
        {
            page = _MY_INFO;
            break;
        }
	    /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_other_insurance);
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_my_info);
        BFL_button_draw(&button_car_insurance_page);
        BFL_button_draw(&button_car_maintenance_page);
        BFL_button_draw(&button_car_roadside_assistance_page);
        BFL_button_draw(&button_car_vehicle_administration_page);

        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;

}   


void car_serv_button_other_insurance_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=325;
    buttonPtr->position_top =400;
    buttonPtr->position_right = 470;
    buttonPtr->position_bottom = 460;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"其他保险");
    buttonPtr->text_length = 4;

    buttonPtr->status = REST;
}
void car_serv_button_exit_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=480;
    buttonPtr->position_top =400;
    buttonPtr->position_right = 585;
    buttonPtr->position_bottom = 460;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"退出");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}

void car_serv_button_my_info_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=5;
    buttonPtr->position_top =350;
    buttonPtr->position_right = 155;
    buttonPtr->position_bottom = 460;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 17;
    buttonPtr->position_text_top = buttonPtr->position_top + 25;
    buttonPtr->text_size = 48;

    strcpy(buttonPtr->display_text,"我的");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}

void car_serv_button_car_insurance_page_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=BROWN;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=180;
    buttonPtr->position_top =50;
    buttonPtr->position_right = 360;
    buttonPtr->position_bottom = 120;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 20;
    buttonPtr->position_text_top = buttonPtr->position_top + 20;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"车险服务");
    buttonPtr->text_length = 4;

    buttonPtr->status = REST;
}

void car_serv_button_car_maintenance_page_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=BROWN;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=420;
    buttonPtr->position_top =50;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 120;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 20;
    buttonPtr->position_text_top = buttonPtr->position_top + 20;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"用车养车");
    buttonPtr->text_length = 4;

    buttonPtr->status = REST;
}

void car_serv_button_car_roadside_assistance_page_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=BROWN;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=180;
    buttonPtr->position_top =210;
    buttonPtr->position_right = 360;
    buttonPtr->position_bottom = 280;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 20;
    buttonPtr->position_text_top = buttonPtr->position_top + 20;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"道路帮助");
    buttonPtr->text_length = 4;

    buttonPtr->status = REST;
}

void car_serv_button_car_vehicle_administration_page_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=BROWN;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;
    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=420;
    buttonPtr->position_top =210;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 280;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 20;
    buttonPtr->position_text_top = buttonPtr->position_top + 20;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"交管服务");
    buttonPtr->text_length = 4;

    buttonPtr->status = REST;
}