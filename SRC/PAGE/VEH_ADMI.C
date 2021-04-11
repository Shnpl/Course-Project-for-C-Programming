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

void veh_admi_button_car_service_init(BFL_button* );
void veh_admi_button_other_insurance_init(BFL_button* );
void veh_admi_button_exit_init(BFL_button* );
void veh_admi_button_my_info_init(BFL_button* );

void veh_admi_button_annual_check_appointment_page_init(BFL_button* );


/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int VEH_ADMI(char* user_ID)
{
    /* DEFINITION START */

    int page = _VEH_ADMI;

    BFL_button button_car_service;
    BFL_button button_other_insurance;
    BFL_button button_exit;
    BFL_button button_my_info;
    BFL_button button_annual_check_appointment_page;

    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */

    veh_admi_button_car_service_init(&button_car_service );
    veh_admi_button_other_insurance_init(&button_other_insurance );
    veh_admi_button_exit_init(&button_exit );
    veh_admi_button_my_info_init(&button_my_info);
    veh_admi_button_annual_check_appointment_page_init(&button_annual_check_appointment_page);

    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1,LIGHTGRAY);
    bar(0,420,640,480);

    setfillstyle(1,DARKGRAY);
    bar(600,405,645,465);//按钮的边
    setfillstyle(1,RED);
    bar(595,400,640,460);//按钮的边

    CHN_print(22,21,"交管",48,DARKGRAY);
    CHN_print(22,71,"服务",48,DARKGRAY);

    CHN_print(20,20,"交管",48,RED);
    CHN_print(20,70,"服务",48,RED);

    /* DRAW END */

    /*WHILE*/
    while (page == _VEH_ADMI)
    {
        /*ACTION START*/
        BFL_mouse_action();

        BFL_button_action(&button_car_service);
        BFL_button_action(&button_other_insurance);
        BFL_button_action(&button_exit);
        BFL_button_action(&button_my_info);

        BFL_button_action(&button_annual_check_appointment_page);

        /* ACTION END */

	    /*CODE START*/
        if(button_exit.status == PRESS)
        {
            page = _MAIN_PAGE;
            break;
        }
        if(button_my_info.status == PRESS)
        {
            page = _MY_INFO;
            break;
        }
        if(button_car_service.status == PRESS)
        {
            page = _CAR_SERV;
            break;
        }
        if(button_annual_check_appointment_page.status == PRESS)
        {
            page = _CHK_APMT;
            break;
        }
	    /* CODE END */

        /* REDRAW START */
        BFL_button_draw(&button_car_service);
        BFL_button_draw(&button_other_insurance);
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_my_info);

        BFL_button_draw(&button_annual_check_appointment_page);

        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;

}   

void veh_admi_button_car_service_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=170;
    buttonPtr->position_top =400;
    buttonPtr->position_right = 315;
    buttonPtr->position_bottom = 460;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    
    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"汽车服务");

    buttonPtr->status = REST;
}

void veh_admi_button_other_insurance_init(BFL_button* buttonPtr )
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

    buttonPtr->status = REST;
}
void veh_admi_button_exit_init(BFL_button* buttonPtr )
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

    buttonPtr->status = REST;
}

void veh_admi_button_my_info_init(BFL_button* buttonPtr )
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

    buttonPtr->status = REST;
}


void veh_admi_button_annual_check_appointment_page_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=200;
    buttonPtr->position_top =160;
    buttonPtr->position_right = 570;
    buttonPtr->position_bottom = 210;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 125;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"预约年检");

    buttonPtr->status = REST;
}