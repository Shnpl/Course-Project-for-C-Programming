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

void login_textbox_user_name_init(BFL_textbox* );
void login_textbox_user_code_init(BFL_textbox* );
void login_button_confirm_init(BFL_button* );
void login_button_exit_init(BFL_button* );
void login_user_init(user*);
void login_label_1_init(BFL_label*);

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int LOGIN(char* user_ID)
{
    /*DEFINITION START*/
    int page = 2;
    user login_user;
    user temp_user;//查询是否对应的临时用户结构体

    FILE* user_file = NULL;
    int user_OK = RESET;//用户是否对应标志位
    

    BFL_textbox textbox_user_name;
    BFL_textbox textbox_user_code;
    BFL_button button_confirm;
    BFL_button button_exit;
    BFL_label label_1;

    int poly_top_bar[10]={0,0,640,0,640,10,0,10,0,0};

    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);
    
    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    login_textbox_user_name_init(&textbox_user_name);
    login_textbox_user_code_init(&textbox_user_code);
    login_button_confirm_init(&button_confirm);
    login_button_exit_init(&button_exit);

    login_label_1_init(&label_1);

    login_user_init(&login_user);
    /* COMPONENTS INIT END */

    /* DRAW START */

    setfillstyle(1,LIGHTGRAY);
    bar(0,0,640,13);
    setfillstyle(1,RED);
    setcolor(RED);
    drawpoly(5,poly_top_bar);
    floodfill(5,5,RED);


    setfillstyle(1,LIGHTGRAY);
    bar(55,55,105,105);
    setfillstyle(1,RED);
    bar(50,50,100,100);

    CHN_print(122,52,"用户登录",48,48,LIGHTGRAY,4);
    CHN_print(120,50,"用户登录",48,48,RED,4);

    //CHN_print(52,152,"请输入用户名：",24,24,LIGHTGRAY,7);
    CHN_print(50,150,"请输入用户名：",24,24,RED,7);
    
    //CHN_print(52,202,"请输入密码：",24,24,LIGHTGRAY,6);
    CHN_print(50,200,"请输入密码：",24,24,RED,6);

    /* DRAW END */

    /*WHILE*/
    while (page == 2)
    {
        /*ACTION START*/
        BFL_mouse_action();

        BFL_button_action(&button_confirm);
        BFL_label_action(&label_1);
        BFL_button_action(&button_exit);

        BFL_textbox_action(&textbox_user_name);
        BFL_textbox_action(&textbox_user_code);
        /* ACTION END */

	    /*CODE START*/
        if(button_exit.status == PRESS)
        {
            page = 0;
            break;
        } 
	    
        if(button_confirm.status == PRESS)
        {//输入完成

            strcpy(login_user.name,textbox_user_name.true_text);
            strcpy(login_user.code,textbox_user_code.true_text);
  
            if( (user_file = fopen("./FILE/USERFILE.TXT","rt")) == NULL)
            {
                outtextxy(0,0,"FILE ERROR");
            }
            else
            {
                while(!feof(user_file))
                {
                    fread(&temp_user,sizeof(temp_user),1,user_file);
                    if(strcmp(temp_user.name,login_user.name) == 0 && strcmp(temp_user.name,login_user.name) == 0 )
                    {
                        fclose(user_file);
                        user_OK = SET;
                        strcpy(label_1.display_text,"登录成功！");
                        label_1.word_length = 5;
                        label_1.reDraw = 1;
                        page = 3;
                        strcpy(user_ID,login_user.name);
                        break;
                    }
                }
                fclose(user_file);
                if(user_OK == RESET)
                {
                    
                
                    strcpy(label_1.display_text,"用户名或密码错误，请重试！");
                    label_1.word_length = 13;
                    label_1.reDraw = 1;
                }
            }
        }    
	
        if(button_exit.status == PRESS)
        {
            page = 0;
            break;
        }
	    /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_confirm);
        
        BFL_textbox_draw(&textbox_user_name);
        BFL_textbox_draw(&textbox_user_code);
        BFL_label_draw(&label_1);

        BFL_mouse_draw();
        /* REDRAW  END */
    }
    if(user_OK == SET)
    {
        delay(400);
        return page;
    }
    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;

}   

void login_textbox_user_name_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    textboxPtr->color_shadow = DARKGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;

    textboxPtr->position_left = 250;//可修改
    textboxPtr->position_top = 140;//可修改
    textboxPtr->position_right = 460;//可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 40;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left+5;
    textboxPtr->position_shadow_top = textboxPtr->position_top+5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom +5;
    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 10;
    textboxPtr->is_secret = RESET;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}

void login_textbox_user_code_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->color_text = RED;
    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;

    textboxPtr->position_left = 250;//可修改
    textboxPtr->position_top = 190;//可修改
    textboxPtr->position_right = 460;//可修改
    textboxPtr->position_bottom = textboxPtr->position_top + 40;

    textboxPtr->is_shadow_enable = SET;
    textboxPtr->position_shadow_left = textboxPtr->position_left+5;
    textboxPtr->position_shadow_top = textboxPtr->position_top+5;
    textboxPtr->position_shadow_right = textboxPtr->position_right + 5;
    textboxPtr->position_shadow_bottom = textboxPtr->position_bottom +5;

    textboxPtr->current_length = -1;
    *(textboxPtr->display_text) = '\0';
    *(textboxPtr->true_text) = '\0';
    textboxPtr->word_length = 10;
    textboxPtr->is_secret = SET;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}

void login_button_confirm_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;  
    buttonPtr->color_text=YELLOW;
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=390;
    buttonPtr->position_top =370;
    buttonPtr->position_right = 480;
    buttonPtr->position_bottom = 420;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left =buttonPtr->position_left+5;
    buttonPtr->position_shadow_top = buttonPtr->position_top +5;
    buttonPtr->position_shadow_right = buttonPtr->position_right +5;
    buttonPtr->position_shadow_bottom=buttonPtr->position_bottom+5;

    buttonPtr->position_text_left =buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text,"确认");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}

void login_button_exit_init(BFL_button* buttonPtr)
{
    buttonPtr->color_rest=RED;
    buttonPtr->color_hover=LIGHTRED;
    buttonPtr->color_text=YELLOW; 
    buttonPtr->color_shadow=LIGHTGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left=500;
    buttonPtr->position_top =370;
    buttonPtr->position_right = 590;
    buttonPtr->position_bottom = 420;

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

void login_user_init(user* userPtr)
{
    memset(userPtr->name,0,30);
    memset(userPtr->code,0,30);
    memset(userPtr->codeRepeat,0,30);
}

void login_label_1_init(BFL_label* labelPtr)
{
    labelPtr->color_box = YELLOW;
    labelPtr->color_text = RED;

    labelPtr->position_left = 50;
    labelPtr->position_top = 300;
    labelPtr->position_right = 500;
    labelPtr->position_bottom = 350;
    memset(labelPtr->display_text,0,51);
    labelPtr->reDraw = RESET;
}
