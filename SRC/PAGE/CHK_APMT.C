/* SYSTEM INCLUDES START */
#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>
#include<STRING.H>
#include<BIOS.H>
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
#include"INCLUDE/CHK_APMT.H"
/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */


void chk_apmt_button_exit_init(BFL_button* );
void chk_apmt_textbox_tel_init(BFL_textbox* );

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int CHK_APMT(char* user_ID)
{
    /* DEFINITION START */

    int page = _CHK_APMT;
    check_appointment check_appointment_handle;
    BFL_button button_exit;
    BFL_textbox textbox_tel;
    
    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    memset(check_appointment_handle.user_id,0,50);
    strcpy(check_appointment_handle.user_id,user_ID);
    
    chk_apmt_button_exit_init(&button_exit);
    chk_apmt_textbox_tel_init(&textbox_tel);
    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1,LIGHTGRAY);
    bar(0,420,640,480);    
 

    CHN_print(22,21,"预约",48,48,DARKGRAY,2);
    CHN_print(22,71,"年检",48,48,DARKGRAY,2);

    CHN_print(20,20,"预约",48,48,RED,2);
    CHN_print(20,70,"年检",48,48,RED,2);

    CHN_print(140,40,"请输入预约车辆号牌：",16,16,RED,10);
    CHN_print(188,140,"请输入联系人：",16,16,RED,7);
    CHN_print(172,220,"请输入联系电话：",16,16,RED,8);
    CHN_print(220,260,"预约时间：",16,16,RED,5);
    CHN_print(220,300,"预约地点：",16,16,RED,5);
    setfillstyle(1,DARKGRAY);
    bar(330,295,470,320);
    CHN_print(380,300,"自动",16,16,YELLOW,2);

    CHN_print(20,350,"费用（代办费）：",16,16,RED,8);
    CHN_print(20,380,"（不含年检费用）",16,16,RED,8);
    setfillstyle(1,DARKGRAY);
    bar(144,345,200,370);
    setcolor(YELLOW);
    settextstyle(0,0,1);
    outtextxy(150,355,"100");
    CHN_print(180,350,"元",16,16,YELLOW,1);




    


    /* DRAW END */

    /*WHILE*/
    while (page == _CHK_APMT)
    {
        /*ACTION START*/
        BFL_mouse_action();
        BFL_button_action(&button_exit);
        BFL_textbox_action(&textbox_tel);

        /* ACTION END */

	    /*CODE START*/
        if(button_exit.status == PRESS)
        {
            page = _VEH_ADMI;
            break;
        }
	    /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_textbox_draw(&textbox_tel);
        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;

}   

void chk_apmt_button_exit_init(BFL_button* buttonPtr )
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=520;
    buttonPtr->position_top =400;
    buttonPtr->position_right = 610;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"退出");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}

void chk_apmt_textbox_tel_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 3;

    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

    textboxPtr->position_left = 330;//可修改
    textboxPtr->position_top = 210;//可修改
    textboxPtr->position_right = 515;//可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 30;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left+5;
    textboxPtr->position_shadow_top = textboxPtr->position_top+5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom +5;

    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 11;
    textboxPtr->is_secret = RESET;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}
