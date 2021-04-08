/* SYSTEM INCLUDES START */
#include <STDIO.H>
#include <GRAPHICS.H>
#include <STDLIB.H>
#include<MALLOC.H>
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
#include "INCLUDE/MY_SERV.H"
#include"INCLUDE/CHK_APMT.H"
/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */

void my_serv_button_exit_init(BFL_button*);
void my_serv_button_delete_init(BFL_button*);
struct CHK_APMT_node;
typedef struct CHK_APMT_node* CHK_APMT_node_ptr;
typedef CHK_APMT_node_ptr CHK_APMT_position;
typedef CHK_APMT_node_ptr CHK_APMT_list;

//struct main_linklist_node;
//typedef struct main_linklist_node* main_linklist_ptr;
//typedef main_linklist_ptr main_linklist_position;
//typedef main_linklist_ptr main_linklist_list;

//struct main_linklist_node
//{
//
//}

struct CHK_APMT_node
{
    check_appointment check_appointment_node;
    CHK_APMT_position next;
};


/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int MY_SERV(char *user_ID)
{
    /* DEFINITION START */

    int page = _MY_SERV;
    
    BFL_button button_exit;
    BFL_button button_delete;

    int check_appointment_count = 0;
    FILE* check_appointment_file;

    CHK_APMT_list CHK_APMT_HEAD = (CHK_APMT_list)malloc(sizeof(struct CHK_APMT_node));
    CHK_APMT_position CHK_APMT_READ_PTR = CHK_APMT_HEAD;

    char debug1[50]={'\0'};
    char debug2[50]={'\0'};
    char debug3[50]={'\0'};
    

    
    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    if(CHK_APMT_HEAD == NULL)
    {
        outtextxy(0,0,"MEMORY ERROR");
    }
    CHK_APMT_HEAD->next = NULL;
    
    if((check_appointment_file =fopen("./FILE/CHK_APMT.TXT","at+")) == NULL)
    {
        outtextxy(0,0,"FILE ERROR");
    }

    while(!feof(check_appointment_file))
    {
        CHK_APMT_READ_PTR->next = malloc(sizeof(struct CHK_APMT_node));
        if(CHK_APMT_READ_PTR->next == NULL)
        {
            outtextxy(0,0,"MEMORY ERROR");
        }
        if((fread(&(CHK_APMT_READ_PTR->next->check_appointment_node),sizeof(check_appointment),1,check_appointment_file)) == 0)
        {
            free(CHK_APMT_READ_PTR->next);
            CHK_APMT_READ_PTR->next = NULL;
            break;
        } 
        if(strcmp(CHK_APMT_READ_PTR->next->check_appointment_node.user_id,user_ID) == 0)
        {
            CHK_APMT_READ_PTR = CHK_APMT_READ_PTR->next;
            CHK_APMT_READ_PTR->next = NULL;
            check_appointment_count++;
        }
        else
        {
            free(CHK_APMT_READ_PTR->next);
            CHK_APMT_READ_PTR->next = NULL;
        }
        
    }
    fclose(check_appointment_file);
    
    outtextxy(0,200,CHK_APMT_READ_PTR->check_appointment_node.tel);
    //itoa((int)CHK_APMT_READ_PTR,debug1,16);// once used in debug
    //itoa((int)CHK_APMT_HEAD->next,debug2,16);
    itoa(check_appointment_count,debug3,10);
    
    //outtextxy(0,240,debug1);
    //outtextxy(0,280,debug2);
    outtextxy(0,320,debug3);

    my_serv_button_exit_init(&button_exit);
    my_serv_button_delete_init(&button_delete);

    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1, LIGHTGRAY);
    bar(0, 420, 640, 480);

    CHN_print(22, 21, "我的", 48, 48, DARKGRAY, 2);
    CHN_print(22, 71, "服务", 48, 48, DARKGRAY, 2);

    CHN_print(20, 20, "我的", 48, 48, RED, 2);
    CHN_print(20, 70, "服务", 48, 48, RED, 2);


    /* DRAW END */

    /*WHILE*/
    while (page == _MY_SERV)
    {
        /* ACTION START */
        BFL_mouse_action();
        BFL_button_action(&button_exit);
        BFL_button_action(&button_delete);

        /* ACTION END */

        /*CODE START*/
        
        if (button_exit.status == PRESS)
        {
            page = _VEH_ADMI;
            break;
        }
        /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_delete);
        
        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200); //防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}

void my_serv_button_exit_init(BFL_button *buttonPtr)
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

void my_serv_button_delete_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 150;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 240;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "删除");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}