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
void textbox_user_name_init(BFL_textbox* );
void textbox_user_code_init(BFL_textbox* );
void textbox_user_code_repeat_init(BFL_textbox* );
void button_confirm_init(BFL_button* );
void button_exit_sign_in_init(BFL_button* );
void user_init(user*);
void label_1_init(BFL_label*);
//void button_login_init(BFL_button* buttonPtr);
/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int SIGN_IN()
{
    /*DEFINITION START*/
    int page = 1;
    user sign_in_user;
    user temp_user;//查询是否重复的临时用户结构体

    FILE* user_file = NULL;
    int file_write_OK = RESET;
    int user_OK = SET;//用户是否重复标志位
    

    BFL_textbox textbox_user_name;
    BFL_textbox textbox_user_code;
    BFL_textbox textbox_user_code_repeat;
    BFL_button button_confirm;
    BFL_button button_exit;
    BFL_label label_1;

    //BFL_button button_login;
    //BFL_button button_exit;

    int poly_top_bar[10]={0,0,640,0,640,10,0,10,0,0};
    //int poly_2[]={0,180,640,180,640,187,0,187};

    /*DEFINITION END*/

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    textbox_user_name_init(&textbox_user_name);
    textbox_user_code_init(&textbox_user_code);
    textbox_user_code_repeat_init(&textbox_user_code_repeat);
    button_confirm_init(&button_confirm);
    button_exit_sign_in_init(&button_exit);

    label_1_init(&label_1);

    user_init(&sign_in_user);

    //button_login_init(&button_login);
    /* COMPONENTS INIT END */

    /* DRAW START */
    //CHN_print(40,100,"平安好车主",48,48,RED,5);
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
    CHN_print(120,50,"用户注册",48,48,RED,4);

    CHN_print(50,150,"请输入用户名：",24,24,RED,7);
    CHN_print(50,200,"请输入密码：",24,24,RED,6);
    CHN_print(50,250,"请再次输入密码：",24,24,RED,8);

    /* DRAW END */

    /*WHILE*/
    while (page == 1)
    {
        /*ACTION START*/
        BFL_mouse_action();

        BFL_button_action(&button_confirm);
        BFL_label_action(&label_1);
        BFL_button_action(&button_exit);
        BFL_textbox_action(&textbox_user_name);
        BFL_textbox_action(&textbox_user_code);
        BFL_textbox_action(&textbox_user_code_repeat);
        /*ACTION END*/

	/*CODE START*/
	
        if(button_confirm.status == PRESS && file_write_OK == RESET)
        {//输入完成

            strcpy(sign_in_user.name,textbox_user_name.true_text);
            strcpy(sign_in_user.code,textbox_user_code.true_text);
            strcpy(sign_in_user.codeRepeat,textbox_user_code_repeat.true_text);
            
            if(strcmp(sign_in_user.code,sign_in_user.codeRepeat) != 0 )
            {
                strcpy(label_1.display_text,"两次密码不一致，请重新输入！");
                label_1.word_length = 14;
                label_1.reDraw = SET;
            }
            else
            {
               
                if( (user_file = fopen("./FILE/USERFILE.TXT","at+")) == NULL)
                {
                    outtextxy(0,0,"FILE ERROR");
                }

                //查询用户是否重复
                user_OK = SET;
                while(!feof(user_file))
                {
                    if((fread(&temp_user,sizeof(temp_user),1,user_file)) == 0)
                    {
                        break;
                    }
                    if(strcmp(temp_user.name,sign_in_user.name) == 0)
                    {
                        fclose(user_file);
                        strcpy(label_1.display_text,"用户名已被注册！");
                        label_1.word_length = 8;
                        label_1.reDraw = SET;
                        user_OK = RESET;
                    }
                }
                rewind(user_file);
                if(user_OK == SET)
                {

                    //outtextxy(0,0,sign_in_user.name);
                    //outtextxy(0,50,sign_in_user.code);
                    fwrite(&sign_in_user,sizeof(sign_in_user),1,user_file);
                    fclose(user_file);
                    file_write_OK = SET;
                    
                    strcpy(label_1.display_text,"完成注册！");
                    label_1.word_length = 5;
                    label_1.reDraw = SET;
                    page = 0;
                    break;

                }
            }
            
        }
	
        if(button_exit.status == PRESS)
        {
            page = 0;
            break;
        }

	/*CODE END*/

        /*REDRAW START*/
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_confirm);
        
        BFL_textbox_draw(&textbox_user_name);
        BFL_textbox_draw(&textbox_user_code);
        BFL_textbox_draw(&textbox_user_code_repeat);
        BFL_label_draw(&label_1);

        BFL_mouse_draw();
        /* REDRAW  END */
    }
    delay(200);//防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}   

void textbox_user_name_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 4;
    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;
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
    textboxPtr->mode = 0;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}

void textbox_user_code_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 4;


    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

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
    textboxPtr->mode = 0;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}
void textbox_user_code_repeat_init(BFL_textbox* textboxPtr)
{
    textboxPtr->color_box = LIGHTGRAY;
    //textboxPtr->color_cursor =BROWN;
    textboxPtr->color_text = RED;
    textboxPtr->color_shadow = DARKGRAY;
    textboxPtr->size = 4;


    textboxPtr->reDraw = SET;
    // textboxPtr->cursor_count = 0;
    textboxPtr->is_in_the_box = 0;

    textboxPtr->position_left = 250;//可修改
    textboxPtr->position_top = 240;//可修改
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
    textboxPtr->mode = 0;
    BFL_textbox_draw(textboxPtr);
    
    textboxPtr->reDraw = RESET;
}


void button_confirm_init(BFL_button* buttonPtr)
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

void button_exit_sign_in_init(BFL_button* buttonPtr)
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

void user_init(user* userPtr)
{
    memset(userPtr->name,0,30);
    memset(userPtr->code,0,30);
    memset(userPtr->codeRepeat,0,30);
}
void label_1_init(BFL_label* labelPtr)
{
    labelPtr->color_box = YELLOW;
    labelPtr->color_text = RED;

    labelPtr->position_left = 50;
    labelPtr->position_top = 300;
    labelPtr->position_right = 500;
    labelPtr->position_bottom = 350;

    labelPtr->position_text_left = labelPtr->position_left;
    labelPtr->position_text_top = labelPtr->position_top;
    labelPtr->size = 32;
    labelPtr->display_type = 0;
    memset(labelPtr->display_text,0,51);
    labelPtr->reDraw = RESET;
}
