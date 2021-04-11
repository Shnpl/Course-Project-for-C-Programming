#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>
#include<STRING.H>

#include"INCLUDE/GENERAL.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/TEXTBOX.H"
#include"INCLUDE/CHN.H"

//void textbox_1_init(BFL_textbox* textbox_1);
void button_sign_in_init(BFL_button* buttonPtr);
void button_login_init(BFL_button* buttonPtr);
void button_exit_init(BFL_button* buttonPtr);
void button_test_init(BFL_button* buttonPtr);
int INITIAL()
{
    /* DEFINITION START */
    int page = 0;
    BFL_button button_sign_in;
    BFL_button button_login;
    BFL_button button_exit;
    BFL_button button_test;
    //BFL_textbox textbox_1;
    
    int poly_1[]={0,160,290,160,350,100,640,100,640,160,640,170,0,170};
    int poly_2[]={0,180,640,180,640,187,0,187};

    /* DEFINITION END */
    
    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);
    /* DEVICE AND MOUSE INIT END */

    /*COMPONENTS INIT START*/
    button_sign_in_init(&button_sign_in);
    button_login_init(&button_login);
    button_exit_init(&button_exit);
    button_test_init(&button_test);
    // textbox_1_init(&textbox_1);
    /*COMPONENTS INIT END*/

    /* DRAW START */
    CHN_print(43,103,"平安好车主",48,LIGHTGRAY);
    CHN_print(40,100,"平安好车主",48,RED);
    
    
    setfillstyle(1,LIGHTGRAY);
    bar(0,165,640,173);
    bar(0,185,640,190);
    
    setfillstyle(1,RED);
    setcolor(RED);
    drawpoly(7,poly_1);
    floodfill(290+5,160,RED); 
    drawpoly(5,poly_2);
    floodfill(5,180+3,RED);
    
    /* DRAW END */

    /*WHILE*/
    while (page == _INITIAL)
    {
        /* ACTION START */
        BFL_mouse_action();

        BFL_button_action(&button_sign_in);
        BFL_button_action(&button_login);
        BFL_button_action(&button_exit);
        BFL_button_action(&button_test);
        //BFL_textbox_action(&textbox_1);
        /* ACTION END */

        /* CODE START */
        if(button_sign_in.status == PRESS)
        {
           page = 1;
           break;
        }
        if(button_login.status == PRESS)
        {
            page = 2;
            break;
        }
        if(button_exit.status == PRESS)
	{
	    closegraph();
            exit(0);
        }
        if(button_test.status == PRESS)
        {
            page = -1;
        }
        /* CODE END */

        /* REDRAW START */
        BFL_button_draw(&button_sign_in);
        BFL_button_draw(&button_login);
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_test);

        //BFL_textbox_draw(&textbox_1);
        BFL_mouse_draw();
        /* REDRAW END */

    }
    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}   
/*
void textbox_1_init(BFL_textbox* textbox_1)
{
    textbox_1->color_box = LIGHTGRAY;
    textbox_1->color_cursor =BROWN;
    textbox_1->color_text = BLUE;
    textbox_1->reDraw = SET;
    // textbox_1->cursor_count = 0;

    textbox_1->position_left = 200;//可修改
    textbox_1->position_top = 300;//可修改
    textbox_1->position_right = 500;
    textbox_1->position_bottom = textbox_1->position_top + 40;
    textbox_1->current_length = -1;
    *(textbox_1->display_text) = '\0';
    *(textbox_1->true_text) = '\0';
    //textbox_1->word_length = 10;
    textbox_1->is_secret = SET;
    BFL_textbox_draw(textbox_1);
    
    textbox_1->reDraw = RESET;
}
*/
void button_sign_in_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=475;
    buttonPtr->position_top =230;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 280;
    
    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;


    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;
    strcpy(buttonPtr->display_text,"注册");

    buttonPtr->status = REST;
}
void button_login_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=475;
    buttonPtr->position_top =310;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 360;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"登录");
    buttonPtr->status = REST;
}
void button_exit_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;
    buttonPtr->color_text=YELLOW; 
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=475;
    buttonPtr->position_top =390;
    buttonPtr->position_right = 600;
    buttonPtr->position_bottom = 440;

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

void button_test_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;
    buttonPtr->color_text=YELLOW; 
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=175;
    buttonPtr->position_top =390;
    buttonPtr->position_right = 300;
    buttonPtr->position_bottom = 440;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"测试");

    buttonPtr->status = REST;
}